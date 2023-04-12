#Basic imports for modules being used
import neurokit2 as nk
import matplotlib.pyplot as plt
import pandas as pd
import csv
from scipy.stats import pearsonr


plt.rcParams['figure.figsize'] = [15, 5]  # Make the graphed images bigger
data = pd.read_csv(r"C:\Users\Cameron\Downloads\Data - Cam 1.csv") #Import data
GSR = data['GSR'].tolist() #Be able to get GSR to a list instead of array
signals, info = nk.eda_process(GSR, sampling_rate=40) #This both cleans and processes the data, giving the cleaned signals back and also information about the signals
cleaned = signals["EDA_Clean"] #Labeling
features = [info["SCR_Onsets"], info["SCR_Peaks"], info["SCR_Recovery"]] #Labeling all Onsets, Peaks, and Recovery on the graphs

data2 = pd.read_csv(r"C:\Users\Cameron\Downloads\Data - Dawson 1.csv") #Import data
GSR2 = data2['GSR'].tolist()  #Be able to get GSR to a list instead of array
signals2, info2 = nk.eda_process(GSR2, sampling_rate=40)  #This both cleans and processes the data, giving the cleaned signals back and also information about the signals
cleaned2 = signals2["EDA_Clean"] #Labeling
features2 = [info2["SCR_Onsets"], info2["SCR_Peaks"], info2["SCR_Recovery"]] #Labeling all Onsets, Peaks, and Recovery on the graphs

plot = nk.events_plot(features, cleaned) #plot first graph
plot2 = nk.events_plot(features2, cleaned2) #plot second graph
#color=['red', 'blue', 'orange']