#ifndef _color_sensor_v3_h_
#define _color_sensor_v3_h_

/*

  support for the color sensor portion of the Broadcom APDS-9151
  "Digital Proximity and RGB Sensor in Small Aperture"

  This is the sensor used in the Rev robotics color sensor v3

  This only supports the color sensor function

  Heavily cribbed from Rev Robotics source code
  git@github.com:REVrobotics/Color-Sensor-v3.git

*/

#include <Arduino.h>
#include <Wire.h>
#include "i2c_interface.h"
#include "bit_conversion_utils.h"
#include "apds_9151_constants.h"

#include "apds_9151_base_device.h"

#include "raw_color.h"

class color_sensor_v3 : public apds_9151_base_device
{

    public:
        color_sensor_v3(void);

        void setup(void);

    public:
        void enable_color_sensor(void);
        void configure_color_sensor(APDS_9151::color_resolution_t res, APDS_9151::color_measurement_rate_t rate);

        raw_color_t get_raw_color();

};
#endif
