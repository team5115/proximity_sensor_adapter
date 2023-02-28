#ifndef _proximity_sensor_h_
#define _proximity_sensor_h_

/*

  support for the proximity sensor portion of the Broadcom APDS-9151
  "Digital Proximity and RGB Sensor in Small Aperture"

  This is the sensor used in the Rev robotics color sensor v3

  This only supports the proximity sensor function

  Heavily cribbed from Rev Robotics source code
  git@github.com:REVrobotics/Color-Sensor-v3.git

values out of prox sensor (assuming 11 bit mode):
0    is far (ie no object)
2047 is near (2^11-1)

*/

#include <Arduino.h>
#include <Wire.h>
#include "i2c_interface.h"
#include "bit_conversion_utils.h"
#include "apds_9151_constants.h"
#include "apds_9151_base_device.h"

class proximity_sensor: public apds_9151_base_device
{

    public:
        proximity_sensor(void);

        void setup(void);

    protected:
        // i2c_interface the_i2c_interface;
        const int n_bits_read_out;

        // void write_register(APDS_9151::REGISTERS reg, uint8_t data);

        // uint32_t read_20_bit_register(APDS_9151::REGISTERS reg);
        // uint16_t read_11_bit_register(APDS_9151::REGISTERS reg);

    public:
        void enable_proximity_sensor_and_color_sensor(void);
        void enable_proximity_sensor_only(void);

        void configure_proximity_sensor_led(uint8_t pulse_freq, uint8_t led_curr, uint8_t n_pulses);
        void configure_proximity_sensor(uint8_t measurement_res, uint8_t measurement_rate);

        uint32_t get_proximity();

        uint32_t get_proximity_value_close() {return pow(2,n_bits_read_out)-1;}
        uint32_t get_proximity_value_far()   {return 0;}
        bool get_proximity_slope_neg()   {return true;}
};
#endif
