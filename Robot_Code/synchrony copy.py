#!/usr/bin/env python
# coding: utf-8

import neurokit2 as nk
from scipy import stats
import numpy as np
import pandas
import matplotlib.pyplot as plt
import rospy
from sensor_msgs.msg import *
from std_msgs.msg import *

### GLOBAL VARIABLES ###
n_samples = 200
sampling_rate = 40
hr_data_A = []
con_data_A = []
gsr_data_A = []
hr_data_B = []
con_data_B = []
gsr_data_B = []
i = 1

def listener():
    # Creates ROS listeners for our body A topics
    rospy.Subscriber("/body_A/heart_rate", String, sampler, 1, 'a')
    rospy.Subscriber("/body_A/confidence", String, sampler, 2, 'a')
    rospy.Subscriber("/body_A/gsr", String, sampler, 3, 'a')

    # Creates ROS listeners for our body B topics
    rospy.Subscriber("/body_B/heart_rate", String, sampler, 1, 'b')
    rospy.Subscriber("/body_B/confidence", String, sampler, 2, 'b')
    rospy.Subscriber("/body_B/gsr", String, sampler, 3, 'b')

def sampler(data, metric, device):
    # Recognize global variables
    global n_samples
    global hr_data_A
    global con_data_A
    global gsr_data_A
    global hr_data_B
    global con_data_B
    global gsr_data_B
    global i

    t_samples = n_samples * i

    # Run analysis() if there are n_samples new data points for each metric on each device
    if(len(hr_data_A) >= t_samples and len(con_data_A) >= t_samples and len(gsr_data_A) >= t_samples and len(hr_data_B) >= t_samples and len(con_data_B) >= t_samples and len(gsr_data_B) >= t_samples):
        # Arguments for analysis
        hr_data_A_sample = hr_data_A[t_samples - n_samples: t_samples]
        con_data_A_sample = con_data_A[t_samples - n_samples: t_samples]
        gsr_data_A_sample = gsr_data_A[t_samples - n_samples: t_samples]
        hr_data_B_sample = hr_data_B[t_samples - n_samples: t_samples]
        con_data_B_sample = con_data_B[t_samples - n_samples: t_samples]
        gsr_data_B_sample = gsr_data_B[t_samples - n_samples: t_samples]

        # Call to analysis()
        analysis(hr_data_A_sample, con_data_A_sample, gsr_data_A_sample, hr_data_B_sample, con_data_B_sample, gsr_data_B_sample)
        i += 1

    # Appends data lists with new data from subscriber
    if(device == 'a'):
        if(metric == 1):
            hr_data_A.append(data)
        elif(metric == 2):
            con_data_A.append(data)
        elif(metric == 3):
            gsr_data_A.append(data)
    if(device == 'b'):
        if(metric == 1):
            hr_data_B.append(data)
        elif(metric == 2):
            con_data_B.append(data)
        elif(metric == 3):
            gsr_data_B.append(data)

def analysis(HR_A, Con_A, GSR_A, HR_B, Con_B, GSR_B):
    # Global Variable Recognition
    global hr_data_A
    global con_data_A
    global gsr_data_A
    global hr_data_B
    global con_data_B
    global gsr_data_B
    global sampling_rate

    # Process GSR using neurokit2
    GSR_A_data, ignoreA = nk.eda_process(GSR_A, sampling_rate=sampling_rate)
    GSR_A = GSR_A_data["EDA_Clean"]
    GSR_B_data, ignoreB = nk.eda_process(GSR_B, sampling_rate=sampling_rate)
    GSR_B = GSR_B_data["EDA_Clean"]

     # Removes data with low confidence
    for m in range(len(HR_A)):
        if Con_A[m] < 50:
            HR_A[m] = 0

    for m in range(len(HR_B)):
        if Con_B[m] < 50:
            HR_B[m] = 0

    # Pearson correlation on GSR and PPG data
    GSR_corr = [0 for i in range(n_samples)]
    PPG_corr = [0 for i in range(n_samples)]
    beg = 0
    end = sampling_rate - 1
    for i in range(4): #gets 5 correlations, each for 1 second of data
        if np.std(HR_A[beg:end]) != 0 and np.std(HR_B[beg:end]) != 0:
            PPG_corr[i], ignore1 = stats.pearsonr(HR_A[beg:end], HR_B[beg:end])
        else:
            PPG_corr[i] = 0
        beg += 40
        end += 40
    beg = 0
    end = sampling_rate - 1
    for i in range(4):  #gets 5 correlations, each for 1 second of data
        if np.std(GSR_A[beg:end]) != 0 and np.std(GSR_B[beg:end]) != 0:
            GSR_corr[i], ignore2 = stats.pearsonr(GSR_A[beg:end], GSR_B[beg:end])
        else:
            GSR_corr[i] = 0
        beg += 40
        end += 40    

    # Bio-syncrhony for PPG
    PPG_num = 0 #numerator of log equation
    PPG_den = 0 #denominator of log equation
    for i in range(4):
        if PPG_corr[i] > 0:
            PPG_num = PPG_num + PPG_corr[i] #sum of positive correlations (from each second of data)
        else:
            PPG_den = PPG_den + PPG_corr[i] #sum of negative correlations (from each second of data)
    if PPG_num == 0:
        PPG_sync = 0
    elif PPG_den != 0:
        PPG_sync = np.log(PPG_num/abs(PPG_den))
    else:
        PPG_sync = np.nan

        
    # Bio-syncrhony for GSR
    GSR_num = 0 #numerator of log equation
    GSR_den = 0 #denominator of log equation
    for i in range(4):
        if GSR_corr[i] > 0:
            GSR_num = GSR_num + GSR_corr[i] #sum of positive correlations (from each second of data)
        else:
            GSR_den = GSR_den + GSR_corr[i] #sum of negative correlations (from each second of data)
    if GSR_num == 0:
        GSR_sync = 0
    elif GSR_den != 0:
        GSR_sync = np.log(GSR_num/abs(GSR_den))
    else:
        GSR_sync = np.nan

    # Publish Data to ROS
    PPG_pub = rospy.Publisher('synchrony/ppg', std_msgs.msg.Float32, queue_size=10)
    GSR_pub = rospy.Publisher('synchrony/gsr', std_msgs.msg.Float32, queue_size=10)
    PPG_pub.publish(std_msgs.msg.Float32(PPG_sync))
    GSR_pub.publish(std_msgs.msg.Float32(GSR_sync))
    