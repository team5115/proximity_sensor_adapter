# proximity_sensor_adapter

Arduino code to bypass I2C bug in FRC Roborio that results in a hung I2C bus when talking to the Rev Robotics Color Sensor v3

The workaround is to have an arduino talk to the sensor, get the value compare to a hardcoded thhreshold and output a digital high low 
if the proximity sensor senses something.

The Color Sensor V3 expects a 3.3V I2C bus, so this needs to be done with a 3.3 V arduino or you'll need to do voltage conversion stuff.

We used an arduino zero successfully

J. Adams
03/09/2022
