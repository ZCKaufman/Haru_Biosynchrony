#include <SparkFun_Bio_Sensor_Hub_Library.h>
#define USE_USBCON
#include <Wire.h>
#include <ros.h>
#include <std_msgs/String.h>

// No other Address options. Does not need to be changed ever.
#define DEF_ADDR 0x55

// Creates ROS node handle, which takes care of serial communication and creating publishers and subscribers
ros::NodeHandle nh;
std_msgs::String str_msg;

// Instantiate ROS publishers
ros::Publisher heart_rate("body_B/heart_rate", &str_msg);
ros::Publisher confidence("body_B/confidence", &str_msg);
ros::Publisher oxygen("body_B/oxygen", &str_msg);
ros::Publisher status("body_B/status", &str_msg);
ros::Publisher ext_status("body_B/ext_status", &str_msg);
ros::Publisher r_value("body_B/r_value", &str_msg);
ros::Publisher gsr("body_B/gsr", &str_msg);

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
  Serial.begin(9600); //ros serial uses a baud rate of 57600
  nh.getHardware()->setBaud(57600);

  // ROS Setup
  nh.initNode();
  nh.advertise(heart_rate);
  nh.advertise(confidence);
  nh.advertise(oxygen);
  nh.advertise(status);
  nh.advertise(ext_status);
  //nh.advertise(r_value);
  nh.advertise(gsr);

  Wire.begin();
  int result = bioHub.begin();
  // if (!result)
    // Serial.println("Sensor started!");
  // else
    // Serial.println("Could not communicate with the sensor!!!");

  // Serial.println("Configuring Sensor...."); 
  pinMode(GSRPin, INPUT);
  int error = bioHub.configBpm(MODE_TWO); // Configuring just the BPM settings. 
  if(!error){
    // Serial.println("Sensor configured.");
  }
  else {
    // Serial.println("Error configuring sensor.");
    // Serial.print("Error: "); 
    // Serial.println(error); 
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
    // Serial.println(String(body.heartRate) + "," + String(body.confidence) + "," + String(body.oxygen) + "," + String(body.status) + "," + String(body.extStatus) + "," + String(body.rValue) + "," + String(GSRVal) + "\n");
    str_msg.data = body.heartRate;
    heart_rate.publish(&str_msg);

    str_msg.data = body.confidence;
    confidence.publish(&str_msg);

    str_msg.data = body.oxygen;
    oxygen.publish(&str_msg);

    str_msg.data = body.status;
    status.publish(&str_msg);

    str_msg.data = body.extStatus;
    ext_status.publish(&str_msg);

    //str_msg.data = body.rValue;
    //r_value.publish(&str_msg);

    str_msg.data = GSRVal;
    gsr.publish(&str_msg);

    nh.spinOnce();    
    delay(25); // Slowing it down, we don't need to break our necks here.
}
