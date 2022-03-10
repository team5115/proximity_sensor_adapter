#ifndef _proximity_sensor_h_
#define _proximity_sensor_h_

/*

  support for the Broadcom APDS-9151
  "Digital Proximity and RGB Sensor in Small Aperture"


  This is the sensor used in the Rev robotics color sensor v3

  This only supports the proximity sensor function



  Heavily cribbed from Rev Robotics source code
  git@github.com:REVrobotics/Color-Sensor-v3.git 



 */


#include <Arduino.h>
#include <Wire.h>
#include "i2c_interface.h"
#include "bit_conversion_utils.h"

class proximity_sensor
{
    public:
        typedef uint8_t register_t;

    public:
        proximity_sensor(void);

        void setup(void);

    protected:
        i2c_interface the_i2c_interface;

  // the template function is to avoid a cast on every write register using an enum class 
        template <class T>
            void write_register(T reg, uint8_t data)
            { write_register(static_cast<uint8_t>(reg),data);}

        void write_register(register_t reg, uint8_t data);
        void read_register(register_t reg, int count, uint8_t* data);

        uint32_t read_20_bit_register(register_t reg);
        uint16_t read_11_bit_register(register_t reg);

    public:
        void enable_proximity_sensor_and_color_sensor(void);
        void enable_proximity_sensor_only(void);

        void configure_proximity_sensor_led(uint8_t pulse_freq, uint8_t led_curr, uint8_t n_pulses);
        void configure_proximity_sensor(uint8_t measurement_res, uint8_t measurement_rate);

        // 0    is far
        // 2047 is near (2^11-1)

        uint32_t get_proximity();

        uint32_t get_proximity_value_close() {return pow(2,11)-1;}
        uint32_t get_proximity_value_far()   {return 0;}
        bool get_proximity_slope_neg()   {return true;}
};
#endif
