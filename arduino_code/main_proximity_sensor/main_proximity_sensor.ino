#include <Arduino.h>
#include "version.h"
#include "digital_io.h"
#include "proximity_sensor.h"

//#define SERIAL_DEBUG_ENABLED

// this is the pin the arduino will output on
// this is the digital pin
// so 7 is digital 7 or D7
const int output_pin_number=7;

// this is the proximity sensor threshold where the arduino says there
// is a ball
// close is 2047, far is 0
//
uint16_t threshold=512;

// construct the proximity_sensor object and output pins
proximity_sensor the_prox_sensor;
digital_io the_output_pin(output_pin_number, OUTPUT);
digital_io the_led(13, OUTPUT);

#ifdef SERIAL_DEBUG_ENABLED
uint16_t serial_debug_counter=0;
#endif

void setup()
{

    Wire.begin();

    #ifdef SERIAL_DEBUG_ENABLED
    Serial.begin(115200);
    #endif

    //////////////////////////////////////////////////////
    //
    // setup the hardware
    //
    ///////////////////////////////////////////////////
    the_prox_sensor.setup();
    the_output_pin.setup();
    the_led.setup();

    //const auto close_value=the_prox_sensor.get_proximity_value_close();
    //const auto far_value=the_prox_sensor.get_proximity_value_far();
    //threshold=fabs((far_value-close_value)/2);
    //    threshold=512;
}


void loop()
{

    uint16_t value=the_prox_sensor.get_proximity();

    // the sensor has an inverse response
    if (value < threshold)
    {

        the_output_pin.set_high();
        the_led.set_high();
    }
    else
    {
        the_output_pin.set_low();
        the_led.set_low();

    }

    #ifdef SERIAL_DEBUG_ENABLED
    if ((serial_debug_counter++ % 1000)==0)
    {
        Serial.print(static_cast<int>(serial_debug_counter));
        Serial.print(":");
        Serial.print(static_cast<int>(value));
        Serial.print(" ");
        Serial.println();
    }
    // prints another carriage return
    #endif

}
