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
GSR_1_temp = data1['GSR'].tolist() #uncleaned GSR data from user 1
GSR_1_long, ignore1 = nk.eda_process(GSR_1_temp, sampling_rate=40) #processing GSR data from user 1
GSR_1 = GSR_1_long["EDA_Clean"] #processed data from user 1

#from second user
HR_2 = data2['Heartrate'].tolist()
Con_2 = data2['Confidence(HR)'].tolist()
GSR_2_temp = data1['GSR'].tolist() #uncleaned GSR data from user 2
GSR_2_long, ignore2 = nk.eda_process(GSR_2_temp, sampling_rate=40) #processing GSR data from user 2
GSR_2 = GSR_2_long["EDA_Clean"] #processed data from user 2

#removal of unclean HR data, or sub-50% confidence HR data
for m in range(len(HR_1)):
    if Con_1[m] < 50:
        HR_1[m] = 0

for m in range(len(HR_2)):
    if Con_2[m] < 50: 
        HR_2[m] = 0

#Pearson correlation
GSR_corr = []
PPG_corr = []
GSR_corr = [0 for i in range(len(HR_1))]
PPG_corr = [0 for i in range(len(GSR_1))]
beg = 0
end = 39
for i in range(4): #gets 5 correlations, each for 1 second of data
    if np.std(HR_1[beg:end]) != 0 and np.std(HR_2[beg:end]) != 0:
        PPG_corr[i], ignore1 = stats.pearsonr(HR_1[beg:end], HR_2[beg:end])
    else:
        PPG_corr[i] = 0
    beg += 40
    end += 40
beg = 0
end = 39
for i in range(4):  #gets 5 correlations, each for 1 second of data
    if np.std(GSR_1[beg:end]) != 0 and np.std(GSR_2[beg:end]) != 0:
        GSR_corr[i], ignore2 = stats.pearsonr(GSR_1[beg:end], GSR_2[beg:end])
    else:
        GSR_corr[i] = 0
    beg += 40
    end += 40    
                
#bio-syncrhony for PPG
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

    
#bio-syncrhony for GSR
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

print(PPG_sync)
print(GSR_sync)