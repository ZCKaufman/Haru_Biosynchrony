import serial, sys, keyboard, time, os

# Endpoint will need to be updated with the appropriate serial interface
# For linux can take the form of '/dev/ttyUSB0'
# For Windows can take the form of 'COM3'
# Baudrate must match the rate of the microcontroller
try:
    endpoint = serial.Serial('COM5', baudrate=9600, timeout=0.5)
    print("Serial Connection Established!\nMake sure to press and hold SPACE when you would like to terminate data collection!\nCTRL+C will terminate the program without correctly saving the collected data.")
    time.sleep(3)
except:
    print("Serial Connection Failure")
    sys.exit(-1)

if os.path.exists("Data.csv"):
    os.remove("Data.csv")
dataOut = open("Data.csv", 'a')
i = 1
dataOut.write("#,Heartrate,Confidence(HR),Oxygen,Status(Sensor),ExtendedStatus(Sensor),BloodOxygenRValue,GSR\n")

while not keyboard.is_pressed("space"):
    try:
        HR, Con, Oxy, Stat, EStat, BOR, GSR = endpoint.readline().decode("utf-8").split(",")
        print("Heartrate: " + str(HR) + "\nConfidence (HR): " + str(Con) + "\nOxygen: " + str(Oxy) + "\nStatus (Sensor): " + str(Stat) + "\nExtended Status (Sensor): " + str(EStat) + "\nBlood Oxygen R Value: " + str(BOR) + "\nGSR: " + str(GSR))
        dataOut.write(str(i) + "," + str(HR) + "," + str(Con) + "," + str(Oxy) + "," + str(Stat) + "," + str(EStat) + "," + str(BOR) + "," + str(GSR))
        i = i + 1
    except:
        pass

print("SPACE key pressed! Closing stream and saving data to file...")
dataOut.close()