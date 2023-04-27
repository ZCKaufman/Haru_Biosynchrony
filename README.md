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
    11. To stop and start over, just click ctrl+c and rerun the command from step 9

## Understanding the output
The output from this program will be a metric of synchrony called a Pearson Correlation and it will update the metric every 5 seconds. The metric will be published on ROS as well as printed to the terminal running the program. 
- Negative Score (-2-0)
    - A negative score means the two participants are becoming less synchronized over time. Their heart rate or GSR data has less in common than it did when the program began.
- Zero Score (0)
    - A 0 score means that the two participants are just as in sync as they were when the program began. Their heart rate and GSR data is the same as when the program started.
- Positive Score (0-2)
    - A positive score means the participants are becoming more synchronized over time. Their heart rate and GSR data has more in common than it did when the program began.

