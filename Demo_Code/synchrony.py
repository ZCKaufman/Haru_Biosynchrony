#!/usr/bin/env python
# coding: utf-8

# In[3]:


from scipy import stats
import numpy as np
import pandas
import matplotlib.pyplot as plt

data = pandas.read_csv("test_Data.csv")

#from first user
HR_1 = data['Heartrate'].tolist()
Con_1 = data['Confidence(HR)'].tolist()
GSR_1 = data['GSR'].tolist()
pt_1 = data['#'].tolist()

#from second user
HR_2 = data['Heartrate'].tolist()
Con_2 = data['Confidence(HR)'].tolist()
GSR_2 = data['GSR'].tolist()
pt_2 = data['#'].tolist()

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

plt.plot(HR_1)

### after getting ppg and gsr ###
#PPG_1_cor = 0
#GSR_1_cor = 0
j = 1
k = 1
for m in range(len(Con_1)):
    GSR_1_sec[m] = GSR_1[m]
    if Con_1[m] < 50:
    #    HR[m] = np.nan
    #    GSR_1[m] = np.nan
    #GSR_1_sec[i] = GSR_1
        PPG_1_sec[m] = 0
#    print(GSR_1_sec[m])
#    print(PPG_1_sec[m])
    if pt_1[m]%200 == 0:
        j = 0
        k = 0
        GSR_1_sec = [0 for j in range(len(GSR_1))]
        PPG_1_sec = [0 for k in range(len(HR_1))]
#    if j == 0 and k == 0: #idk
#        GSR_1_sec[m] = GSR_1[m] #idk
#        PPG_1_sec[m] = HR_1[m] #idk

#PPG_2_cor = 0
#GSR_2_cor = 0
j = 1
k = 1
for m in range(len(Con_2)):
    GSR_2_sec[m] = GSR_2[m]
    if Con_2[m] < 50:
    #    HR[m] = np.nan
    #    GSR_2[m] = np.nan
    #GSR_2_sec[i] = GSR_2
        PPG_2_sec[m] = 0
#    print(GSR_2_sec[m])
#    print(PPG_2_sec[m])
    if pt_2[m]%200 == 0:
        j = 0
        k = 0
        GSR_2_sec = [0 for j in range(len(GSR_2))]
        PPG_2_sec = [0 for k in range(len(HR_2))]
#    if j == 0 and k == 0: #idk
#        GSR_2_sec[m] = GSR_2[m] #idk
#        PPG_2_sec[m] = HR_2[m] #idk


### then eventually ###

#nan removal
#GSR_1_sec = [eval(GSR_1_sec)]
#PPG_1_sec = [eval(PPG_1_sec)]
#GSR_1_sec = GSR_1_sec[~np.isnan(GSR_sec)]
#PPG_1_sec = PPG_1_sec[~np.isnan(PPG_1_sec)]

#Pearson correlation
PPG_corr = stats.pearsonr(PPG_1_sec, PPG_2_sec) #these variables don't exist yet
GSR_corr = stats.pearsonr(GSR_1_sec, GSR_2_sec) #these variables don't exist yet

#bio-syncrhony for GSR
GSR_num = 0
GSR_den = 0
for i in range(len(GSR_sec)):
    if GSR_corr[i] > 0:
        GSR_num = GSR_num + GSR_corr[i]
    else:
        GSR_den = GSR_den + GSR_corr[i]
GSR_synch = np.log(GSR_1_num/abs(GSR_1_den))

#bio-syncrhony for PPG
PPG_num = 0
PPG_den = 0
for i in range(len(PPG_sec)):
    if PPG_corr[i] > 0:
        PPG_num = PPG_num + PPG_corr[i]
    else:
        PPG_den = PPG_den + PPG_corr[i]
PPG_synch = np.log(PPG_num/abs(PPG_den))


# In[ ]: