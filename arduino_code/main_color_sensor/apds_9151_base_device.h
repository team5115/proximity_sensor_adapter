#ifndef _apds_9151_base_device_h_
#define _apds_9151_base_device_h_

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

class apds_9151_base_device
{

    public:
        apds_9151_base_device(void);

        void setup(void);

    protected:
        i2c_interface the_i2c_interface;
        //const int n_bits_read_out;

        void write_register(APDS_9151::REGISTERS reg, uint8_t data);

        uint32_t read_20_bit_register(APDS_9151::REGISTERS reg);
        uint16_t read_11_bit_register(APDS_9151::REGISTERS reg);

        void write(APDS_9151::REGISTERS reg, uint8_t data);
        void read(APDS_9151::REGISTERS reg, int count, uint8_t* data);

    public:
        void enable_apds_9151_base_device_and_apds_9151_base_device(void);
        void enable_apds_9151_base_device_only(void);

        //void configure_apds_9151_base_device_led(uint8_t pulse_freq, uint8_t led_curr, uint8_t n_pulses);
        void configure_apds_9151_base_device(uint8_t measurement_res, uint8_t measurement_rate);

        // uint32_t get_proximity();

        // uint32_t get_proximity_value_close() {return pow(2,n_bits_read_out)-1;}
        // uint32_t get_proximity_value_far()   {return 0;}
        // bool get_proximity_slope_neg()   {return true;}

        static uint32_t To20Bit(uint8_t *val)
        {
            return (static_cast<uint32_t>(val[0]) |
                (static_cast<uint32_t>(val[1]) << 8) |
                (static_cast<uint32_t>(val[2]) << 16)) &
                0x03FFFF;
        }

        static uint16_t To11Bit(uint8_t *val)
        {
            return (static_cast<uint16_t>(val[0]) |
                (static_cast<uint16_t>(val[1]) << 8)) &
                0x7FF;
        }

};
#endif
