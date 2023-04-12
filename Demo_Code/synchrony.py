#!/usr/bin/env python
# coding: utf-8

# In[3]:


from scipy import stats
import numpy as np
import pandas
import matplotlib.pyplot as plt

data = pandas.read_csv("test_Data.csv")
HR = data['Heartrate'].tolist()
Con = data['Confidence(HR)'].tolist()
GSR = data['GSR'].tolist()
pt = data['#'].tolist()

re = 0 #iterating while values are printed to command line

### before "while not" ###

GSR_sec = []
GSR_sec = [0 for j in range(len(GSR))]#range(200) in actual
PPG_sec = []
PPG_sec = [0 for k in range(len(HR))]#range(200) in actual

plt.plot(HR)

### after getting ppg and gsr ###
#PPG_cor = 0
#GSR_cor = 0
j = 1
k = 1
for m in range(len(Con)):
    GSR_sec[m] = GSR[m]
    if Con[m] < 50:
    #    HR[m] = np.nan
    #    GSR[m] = np.nan
    #GSR_sec[i] = GSR
        PPG_sec[m] = 0
#    print(GSR_sec[m])
#    print(PPG_sec[m])
    if pt[m]%200 == 0:
        j = 0
        k = 0
        GSR_sec = [0 for j in range(len(GSR))]
        PPG_sec = [0 for k in range(len(HR))]
#    if j == 0 and k == 0: #idk
#        GSR_sec[m] = GSR[m] #idk
#        PPG_sec[m] = HR[m] #idk


### then eventually ###

#nan removal
#GSR_sec = [eval(GSR_sec)]
#PPG_sec = [eval(PPG_sec)]
#GSR_sec = GSR_sec[~np.isnan(GSR_sec)]
#PPG_sec = PPG_sec[~np.isnan(PPG_sec)]

#Pearson correlation
#PPG_corr = stats.pearsonr(firstuser, seconduser) #these variables don't exist yet
#GSR_corr = stats.pearsonr(firstuser, seconduser) #these variables don't exist yet

#bio-syncrhony for GSR
#GSR_num = 0
#GSR_den = 0
#for i in range(len(GSR_sec)):
#    if GSR_sec[i] > 0:
#        GSR_num = GSR_num + GSR_sec[i]
#    else:
#        GSR_den = GSR_den + GSR_sec[i]
#GSR_synch = np.log(GSR_num/abs(GSR_den))

#bio-syncrhony for PPG
#PPG_num = 0
#PPG_den = 0
#for i in range(len(PPG_sec)):
#    if PPG_corr[i] > 0:
#        PPG_num = PPG_num + PPG_corr[i]
#    else:
#        PPG_den = PPG_den + PPG_corr[i]
#PPG_synch = np.log(PPG_num/abs(PPG_den))


# In[ ]:
