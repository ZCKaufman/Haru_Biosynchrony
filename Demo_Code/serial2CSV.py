import serial, sys, keyboard, time, os

# Endpoint will need to be updated with the appropriate serial interface
# For linux can take the form of '/dev/ttyUSB0'
# For Windows can take the form of 'COM3'
# Baudrate must match the rate of the microcontroller
try:
    endpoint_1 = serial.Serial('COM9', baudrate=9600, timeout=0.5)
    endpoint_2 = serial.Serial('COM7', baudrate=9600, timeout=0.5)
    print("Serial Connection Established!\nMake sure to press and hold SPACE when you would like to terminate data collection!\nCTRL+C will terminate the program without correctly saving the collected data.")
    time.sleep(3)
except:
    print("Serial Connection Failure")
    sys.exit(-1)

if os.path.exists("Data_1.csv"):
    os.remove("Data_1.csv")
if os.path.exists("Data_2.csv"):
    os.remove("Data_2.csv")
dataOut_1 = open("Data_1.csv", 'a')
dataOut_2 = open("Data_2.csv", 'a')
i = 1
dataOut_1.write("#,Heartrate,Confidence(HR),Oxygen,Status(Sensor),ExtendedStatus(Sensor),BloodOxygenRValue,GSR\n")
dataOut_2.write("#,Heartrate,Confidence(HR),Oxygen,Status(Sensor),ExtendedStatus(Sensor),BloodOxygenRValue,GSR\n")

while not keyboard.is_pressed("space"):
    try:
        HR_1, Con_1, Oxy_1, Stat_1, EStat_1, BOR_1, GSR_1 = endpoint_1.readline().decode("utf-8").split(",")
        HR_2, Con_2, Oxy_2, Stat_2, EStat_2, BOR_2, GSR_2 = endpoint_2.readline().decode("utf-8").split(",")
        print("DEVICE 1:\nHeartrate: " + str(HR_1) + "\nConfidence (HR): " + str(Con_1) + "\nOxygen: " + str(Oxy_1) + "\nStatus (Sensor): " + str(Stat_1) + "\nExtended Status (Sensor): " + str(EStat_1) + "\nBlood Oxygen R Value: " + str(BOR_1) + "\nGSR: " + str(GSR_1))
        dataOut_1.write(str(i) + "," + str(HR_1) + "," + str(Con_1) + "," + str(Oxy_1) + "," + str(Stat_1) + "," + str(EStat_1) + "," + str(BOR_1) + "," + str(GSR_1))
        print("DEVICE 2:\nHeartrate: " + str(HR_2) + "\nConfidence (HR): " + str(Con_2) + "\nOxygen: " + str(Oxy_2) + "\nStatus (Sensor): " + str(Stat_2) + "\nExtended Status (Sensor): " + str(EStat_2) + "\nBlood Oxygen R Value: " + str(BOR_2) + "\nGSR: " + str(GSR_2))
        dataOut_2.write(str(i) + "," + str(HR_2) + "," + str(Con_2) + "," + str(Oxy_2) + "," + str(Stat_2) + "," + str(EStat_2) + "," + str(BOR_2) + "," + str(GSR_2))
        i = i + 1
    except:
        pass

print("SPACE key pressed! Closing stream and saving data to file...")
dataOut_1.close()
dataOut_2.close()