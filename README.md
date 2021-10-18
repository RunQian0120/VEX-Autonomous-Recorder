# VEX Robot Recorder

## Description
This is a demo project for the "Recorder" class that allows the user to record and play back past recorded autonomouses on VEX robots using the PROS API. 
## How it works
The class records the returned value of the `.get_voltage()` function of the PROS API motors during a specified period of time and then writes all the voltages into a text file that is stored on an 32 GB or lower storage sd card in the brain of the robot. It then reads those values during the autonomous period and sets the motors to the recorded voltages.

## Why would you use this?
1. This biggest advantage to this autonomous over traditional hard coded PID control algorithms is speed. It takes minutes to record an autonomous to the SD card while it often takes hours or days to tune a nice hard coded autonomous program. 
2. Due to the fluid nature of the class you can perform complex curves and maneuvers that are traditionnally very difficult to create using card coded PID algorithms without complex libraries like Okapi.
## Limitations
1. ACCURACY! This is currently the biggest flaw in this class. Without other sensors like gyroscopes or accelerometers, the functions are not accurate for longer and more complex autonomouses. I hope to fix this in the future however by adding and error correction system via the vex IMU sensor.

## How to use
1. Download the `Record Auto` project file from this git repository.
2. Refer to the next section to see which files you want to modify with your own code/specifications.

## Important files
1. To change the motor names edit the file `main.h` under the motor definitions. Make sure to then change the names of those motors throughout the rest of of the project including in the implementation of the class in `Recorder.cpp`.
2. To change the motor ports edit the file `main.h` under the motor ports definitions. You don't have to change anything else.
3. The rest should be obvious.
