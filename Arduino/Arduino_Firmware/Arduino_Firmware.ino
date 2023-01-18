#include <SparkFun_Bio_Sensor_Hub_Library.h>
#include <Wire.h>

// No other Address options. Does not need to be changed ever.
#define DEF_ADDR 0x55

// Reset pin, MFIO pin, GSR pin. Change based on appropriate digital / analog arduino pins.
const int resPin = 7;
const int mfioPin = 8;
const int GSRPin = A0;

// Takes address, reset pin, and MFIO pin.
SparkFun_Bio_Sensor_Hub bioHub(resPin, mfioPin); 

bioData body;  
int GSRVal;

void setup(){

  // Modify based on desired baud rate
  Serial.begin(9600); 

  Wire.begin();
  int result = bioHub.begin();
  if (!result)
    Serial.println("Sensor started!");
  else
    Serial.println("Could not communicate with the sensor!!!");

  Serial.println("Configuring Sensor...."); 
  pinMode(GSRPin, INPUT);
  int error = bioHub.configBpm(MODE_TWO); // Configuring just the BPM settings. 
  if(!error){
    Serial.println("Sensor configured.");
  }
  else {
    Serial.println("Error configuring sensor.");
    Serial.print("Error: "); 
    Serial.println(error); 
  }
  // Data lags a bit behind the sensor, if you're finger is on the sensor when
  // it's being configured this delay will give some time for the data to catch
  // up. 
  delay(1000); 

}

// The following loop is what we will be using to stream our data via serial to an endpoint.
// The streamed output will take the form of the following string described below:
// "Heartrate,Confidence(HR),Oxygen,Status(Sensor),ExtendedStatus(Sensor),BloodOxygenRValue,GSR\n"
void loop(){

    // Information from the readBpm function will be saved to our "body"
    // variable.  
    body = bioHub.readBpm();
    GSRVal = analogRead(GSRPin);
    Serial.println(String(body.heartRate) + "," + String(body.confidence) + "," + String(body.oxygen) + "," + String(body.status) + "," + String(body.extStatus) + "," + String(body.rValue) + "," + String(GSRVal) + "\n");
    delay(125); // Slowing it down, we don't need to break our necks here.
}
