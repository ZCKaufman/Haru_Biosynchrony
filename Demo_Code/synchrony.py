#!/usr/bin/env python
# coding: utf-8

# In[3]:

import neurokit2 as nk
from scipy import stats
import numpy as np
import pandas
import matplotlib.pyplot as plt

data1 = pandas.read_csv("Data_1.csv")
data2 = pandas.read_csv("Data_2.csv")

#from first user
HR_1 = data1['Heartrate'].tolist()
Con_1 = data1['Confidence(HR)'].tolist()
GSR_1_temp = data1['GSR'].tolist()
GSR_1_long, ignore1 = nk.eda_process(GSR_1_temp, sampling_rate=40)
GSR_1 = GSR_1_long["EDA_Clean"]
pt_1 = data1['#'].tolist()

#from second user
HR_2 = data2['Heartrate'].tolist()
Con_2 = data2['Confidence(HR)'].tolist()
GSR_2_temp = data1['GSR'].tolist()
GSR_2_long, ignore2 = nk.eda_process(GSR_2_temp, sampling_rate=40)
GSR_2 = GSR_2_long["EDA_Clean"]
pt_2 = data2['#'].tolist()

#re = 0 #iterating while values are printed to command line; ignore

### before "while not" ###

GSR_1_sec = []
GSR_1_sec = [0 for j in range(len(GSR_1))]#range(200) in actual
PPG_1_sec = []
PPG_1_sec = [0 for k in range(len(HR_1))]#range(200) in actual
GSR_2_sec = []
GSR_2_sec = [0 for j in range(len(GSR_2))]#range(200) in actual
PPG_2_sec = []
PPG_2_sec = [0 for k in range(len(HR_2))]#range(200) in actual

### after getting ppg and gsr ###

j = 1
k = 1
for m in range(len(GSR_1)):
    GSR_1_sec[m] = GSR_1[m]
    if Con_1[m] < 50:
        PPG_1_sec[m] = 0
    if pt_1[m]%200 == 0:
        j = 0
        k = 0
        GSR_1_sec = [0 for j in range(len(GSR_1))]
        PPG_1_sec = [0 for k in range(len(HR_1))]


j = 1
k = 1
for m in range(len(GSR_2)):
    GSR_2_sec[m] = GSR_2[m]
    if Con_2[m] < 50:
        PPG_2_sec[m] = 0
    if pt_2[m]%200 == 0:
        j = 0
        k = 0
        GSR_2_sec = [0 for j in range(len(GSR_2))]
        PPG_2_sec = [0 for k in range(len(HR_2))]


### then eventually ###

#Pearson correlation
#NOTE: this is for csv use; actual streaming code will not be in this loop
GSR_corr = []
PPG_corr = []
GSR_corr = [0 for i in range(len(PPG_1_sec))]
PPG_corr = [0 for i in range(len(GSR_1_sec))]
for i in range(len(PPG_1_sec)-1):
    if np.std(PPG_1_sec) != 0 and np.std(PPG_2_sec) != 0:
        PPG_corr[i], ignore1 = stats.pearsonr(PPG_1_sec, PPG_2_sec)
    else:
        PPG_corr[i] = 0
for i in range(len(GSR_2_sec)-1):
    if np.std(GSR_1_sec) != 0 and np.std(GSR_2_sec) != 0:
        GSR_corr[i], ignore2 = stats.pearsonr(GSR_1_sec, GSR_2_sec)
    else:
        GSR_corr[i] = 0
        
        
#bio-syncrhony for PPG
PPG_num = 0
PPG_den = 0
for i in range(len(PPG_1_sec)):
    if PPG_corr[i] > 0:
        PPG_num = PPG_num + PPG_corr[i]
    else:
        PPG_den = PPG_den + PPG_corr[i]
if PPG_den != 0:
    PPG_sync = np.log(PPG_num/abs(PPG_den))
else:
    PPG_sync = np.nan

    
#bio-syncrhony for GSR
GSR_num = 0
GSR_den = 0
for i in range(len(GSR_1_sec)):
    if GSR_corr[i] > 0:
        GSR_num = GSR_num + GSR_corr[i]
    else:
        GSR_den = GSR_den + GSR_corr[i]
if GSR_den != 0:
    GSR_sync = np.log(GSR_num/abs(GSR_den))
else:
    GSR_sync = np.nan

print(PPG_sync)
print(GSR_sync)