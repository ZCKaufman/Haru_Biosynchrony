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
import time

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
t_samples = n_samples
hr_data_A_sample = []
con_data_A_sample = []
gsr_data_A_sample = []
hr_data_B_sample = []
con_data_B_sample = []
gsr_data_B_sample = []

def listener():
    # Node initialization
    rospy.init_node('listener', anonymous=True)

    # Creates ROS listeners for our body A topics
    rospy.Subscriber("/body_A/heart_rate", Int16, hr_sampler, (1, 'a'))
    rospy.Subscriber("/body_A/confidence", Int16, sampler, (2, 'a'))
    rospy.Subscriber("/body_A/gsr", Int16, sampler, (3, 'a'))

    # Creates ROS listeners for our body B topics
    rospy.Subscriber("/body_B/heart_rate", Int16, sampler, (1, 'b'))
    rospy.Subscriber("/body_B/confidence", Int16, sampler, (2, 'b'))
    rospy.Subscriber("/body_B/gsr", Int16, sampler, (3, 'b'))

    # Keeps program running
    rospy.spin()

def hr_sampler(data, args):
    data = str(data)[5:]
    data = int(data)

    # Recognize global variables
    global n_samples
    global hr_data_A
    global con_data_A
    global gsr_data_A
    global hr_data_B
    global con_data_B
    global gsr_data_B
    global hr_data_A_sample
    global con_data_A_sample
    global gsr_data_A_sample
    global hr_data_B_sample
    global con_data_B_sample
    global gsr_data_B_sample
    global t_samples

    print(t_samples, n_samples, len(hr_data_A))
    # Run analysis() if there are n_samples new data points for each metric on each device
    if(len(hr_data_A) >= t_samples and len(gsr_data_A) >= t_samples and len(hr_data_B) >= t_samples and len(gsr_data_B) >= t_samples):
        # Arguments for analysis
        hr_data_A_sample = hr_data_A[t_samples - n_samples: t_samples]

        # Call to analysis()
        analysis(hr_data_A_sample, con_data_A_sample, gsr_data_A_sample, hr_data_B_sample, con_data_B_sample, gsr_data_B_sample)
        t_samples = t_samples + n_samples
        #time.sleep(0.5)

    # Appends data lists with new data from subscriber
    if(args[1] == 'a'):
        if(args[0] == 1):
            hr_data_A.append(data)
        elif(args[0] == 2):
            con_data_A.append(data)
        elif(args[0] == 3):
            gsr_data_A.append(data)
    if(args[1] == 'b'):
        if(args[0] == 1):
            hr_data_B.append(data)
        elif(args[0] == 2):
            con_data_B.append(data)
        elif(args[0] == 3):
            gsr_data_B.append(data)

def sampler(data, args):
    data = str(data)[5:]
    data = int(data)

    # Recognize global variables
    global n_samples
    global hr_data_A
    global con_data_A
    global gsr_data_A
    global hr_data_B
    global con_data_B
    global gsr_data_B
    global hr_data_A_sample
    global con_data_A_sample
    global gsr_data_A_sample
    global hr_data_B_sample
    global con_data_B_sample
    global gsr_data_B_sample
    global t_samples

    #print(t_samples, n_samples, len(hr_data_A))
    # Run analysis() if there are n_samples new data points for each metric on each device
    if(len(hr_data_A) >= t_samples and len(gsr_data_A) >= t_samples and len(hr_data_B) >= t_samples and len(gsr_data_B) >= t_samples):
        # Arguments for analysis
        hr_data_A_sample = hr_data_A[t_samples - n_samples: t_samples]
        con_data_A_sample = con_data_A[t_samples - n_samples: t_samples]
        gsr_data_A_sample = gsr_data_A[t_samples - n_samples: t_samples]
        hr_data_B_sample = hr_data_B[t_samples - n_samples: t_samples]
        con_data_B_sample = con_data_B[t_samples - n_samples: t_samples]
        gsr_data_B_sample = gsr_data_B[t_samples - n_samples: t_samples]

    # Appends data lists with new data from subscriber
    if(args[1] == 'a'):
        if(args[0] == 1):
            hr_data_A.append(data)
        elif(args[0] == 2):
            con_data_A.append(data)
        elif(args[0] == 3):
            gsr_data_A.append(data)
    if(args[1] == 'b'):
        if(args[0] == 1):
            hr_data_B.append(data)
        elif(args[0] == 2):
            con_data_B.append(data)
        elif(args[0] == 3):
            gsr_data_B.append(data)

def analysis(HR_A, Con_A, GSR_A, HR_B, Con_B, GSR_B):
    # Global Variable Recognition
    print("analysis")
    global hr_data_A
    global con_data_A
    global gsr_data_A
    global hr_data_B
    global con_data_B
    global gsr_data_B
    global sampling_rate

    # Process GSR using neurokit2
    print(len(GSR_A))
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
    GSR_corr = [0 for x in range(len(HR_A))]
    PPG_corr = [0 for x in range(len(GSR_A))]

    if np.std(HR_A[0:(len(HR_A)-1)]) != 0 and np.std(HR_B[0:(len(HR_B)-1)]) != 0:
        PPG_corr, ignore1 = stats.pearsonr(HR_A[0:len(HR_A)-1], HR_B[0:len(HR_B)-1])
    else:
        PPG_corr = 0
    if np.std(GSR_A[0:len(GSR_A)-1]) != 0 and np.std(GSR_B[0:len(GSR_B)-1]) != 0:
        GSR_corr, ignore2 = stats.pearsonr(GSR_A[0:len(GSR_A)-1], GSR_B[0:len(GSR_B)-1])
    else:
        GSR_corr = 0   


    # Publish Data to ROS
    print("GSR SYNC:", GSR_corr)
    print("PPG SYNC:", PPG_corr)
    print("PPG_A:", len(hr_data_A))
    print("PPG_B:", len(hr_data_B))
    print("GSR_A:", len(gsr_data_A))
    print("GSR_A:", len(gsr_data_A))
    PPG_pub = rospy.Publisher('synchrony/ppg', std_msgs.msg.Float32, queue_size=10)
    GSR_pub = rospy.Publisher('synchrony/gsr', std_msgs.msg.Float32, queue_size=10)
    PPG_pub.publish(std_msgs.msg.Float32(PPG_corr))
    GSR_pub.publish(std_msgs.msg.Float32(GSR_corr))
    return
    

if __name__ == '__main__':
    listener()