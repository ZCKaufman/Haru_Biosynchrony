import neurokit2 as nk
from scipy import stats
import numpy as np
import pandas
import statistics

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

if np.std(HR_1[0:(len(HR_1)-1)]) != 0 and np.std(HR_2[0:(len(HR_2)-1)]) != 0:
    PPG_corr, ignore1 = stats.pearsonr(HR_1[0:len(HR_1)-1], HR_2[0:len(HR_2)-1])
else:
    PPG_corr = 0
if np.std(GSR_1[0:len(GSR_1)-1]) != 0 and np.std(GSR_2[0:len(GSR_2)-1]) != 0:
    GSR_corr, ignore2 = stats.pearsonr(GSR_1[0:len(GSR_1)-1], GSR_2[0:len(GSR_2)-1])
else:
    GSR_corr = 0  


print(PPG_corr)
print(GSR_corr)