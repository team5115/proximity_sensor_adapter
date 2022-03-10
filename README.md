# proximity_sensor_adapter

Arduino code to bypass an aparrant I2C bug in FRC RoboRio that results in a hung I2C bus when talking to the Rev Robotics Color Sensor v3

https://docs.wpilib.org/en/stable/docs/yearly-overview/known-issues.html#onboard-i2c-causing-system-lockups

The workaround is to have an arduino talk to the sensor, get the value compare to a hardcoded thhreshold and output a digital high low 
if the proximity sensor senses something. The digital high low then goes into a DIO pin on the RoboRio effectively bypassing the i2c bus.

The Color Sensor V3 expects a 3.3V I2C bus, so this needs to be done with a 3.3 V arduino or you'll need to do voltage conversion stuff.

We used an arduino zero successfully

Stress test linked here
https://www.chiefdelphi.com/t/robot-keeps-losing-com-and-code-revisited/389391


Much of the code cribbed from Rev Robotics source code
git@github.com:REVrobotics/Color-Sensor-v3.git 

J. Adams
03/09/2022
