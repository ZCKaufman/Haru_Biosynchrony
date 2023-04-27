# Haru_Biosynchrony
The Haru Biosynchrony detection device is a pair of devices created by Cameron Middleton, Carmen Hernandez, Dawson Thompson, Jonathan Ott, and Zachary Kaufman at Indiana University for the Intelligent Systems Engineering Senior Capstone (ENGR-E490/E491) course. The device is designed to be used with the Haru social desktop robot prototype by Honda Research Institute, and was created as a tool for the R-House Human-Robot Interaction lab to use for their studies involving intergenerational synchrony during interactions with Haru. 

Contents:
- Hardware Specifications
- Assembly Instructions
- Demo Instructions
- Using the Device
- Running the Code
- Understanding the Output

## Hardware Specifications


## Assembly Instructions


## Demo Instructions


## Using the Device
- This system uses two devices and finds relative bio-synchrony between them. Ensuring that both devices are currently placed on the participants is important for quality metrics of synchrony. 
1. Place the compute module on the top of your non-dominant wrist and secure with velcro strap firmly but not uncomfortably
2. Place the PPG sensor (the one with purple and red wires) on your index finger by slipping your index finger inside the black sleeve so that the red sensor is on the padding at the bottom of your finger
3. Place the PPG sensor (the one with the two thin wires) on your middle and forefinger by slipping those fingers into the black sleeves so that the metal sensors are on the bottom of the center of your finger
4. Place your non-dominant hand (the one with the sensors on it) at your waist if standing, or on your lap if sitting
    - Note: It is best for sensor resolution if the sensors are not moved a lot during the activity, try encouraging participants to keep their non-dominant hand at this position and to use their dominant hand for the activity
5. Now plug in the compute module to the Haru Zotac computer through a USB port and follow the `Running the Code` instructions

## Running the Code
- System Requirements
    - Python 3.10+
    - Ubuntu 20.04
    - ROS Noetic
- Instructions
    1. Open the Arduino IDE in two separate windows
    2. Open a terminal window and run the command `roscore`
    3. In the first window open the file `A_ROS_Arduino.ino` and in the second window open the file `B_ROS_Arduino.ino`
    4. In both windows make sure that the selected board (under Tools) is "Arduino Micro" and the selected port is the port that the Arduino is plugged into
    5. Click the blue/green "Upload" button in the upper left corner of the screen in both windows
    6. Now open two new tabs/windows in terminal and type in the following command for both devices: 'rosrun rosserial_arduino serial_node.py __name:="DevA" _port:=/dev/ttyACM0`
        NOTE: There are two underscores before `name` and one before `port`
        NOTE: Your port may be different, use the one found in the Arduino window for the device you are using under "Tools"
        - Run the same command again but rename the second device to `DevB` and change the port to whatever port the second device is plugged into
    7. Open the Haru_Biosynchrony repository in VSCode 
    8. Open a terminal within VSCode and run the following command `pyenv activate haru_sync`, this will activate the Haru Synchrony Python environment. This environment is installed on the Zotac machines from Honda
    9. Now run the code by entering the following command `python Robot_Code/synchrony.py`
    10. The code should now be running. Every 5 seconds a synchrony metric will be published to ROS and printed into the VS Code terminal
    11. To stop and start over, just click ctrl+c and rerun the command from step 9 (ix)

## Understanding the output
The output from this program will be a metric of synchrony called a Pearson Correlation and it will update the metric every 5 seconds. There will be a score published for heart rate and GSR separately. The metric will be published on ROS as well as printed to the terminal running the program. 
- Negative Score (-1 to 0)
    - A negative score means that the subjects are experiencing negative synchrony, meaning that their heart rate or GSR has an inverse correlation. An inverse correlation means that the subjects' heart rate or GSR data is trending in opposite values from each other. A score of less than -0.5 represents a strong inverse correlation.
- Zero Score (0)
    - A 0 score means that the two participants are neither in sync nor moving out of sync. Their heart rate and GSR data is not correlated.
- Positive Score (0 to 1)
    - A positive score means that the subjects are experiencing synchrony, meaning that their heart rate or GSR has a direct correlation. A score of greater than 0.5 represents a strong correlation. 

