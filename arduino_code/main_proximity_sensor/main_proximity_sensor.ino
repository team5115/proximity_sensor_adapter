#include <Arduino.h>
#include "version.h"
#include "digital_io.h"
#include "proximity_sensor.h"

const uint32_t update_time_ms=1000*1;

const int output_pin_number=7;

proximity_sensor the_prox_sensor;
digital_io the_output_pin(output_pin_number, OUTPUT);
digital_io the_led(13, OUTPUT);

uint16_t threshold=2047/2;
uint16_t counter=0;

void setup()
{

    Wire.begin();
    Serial.begin(115200);

    //////////////////////////////////////////////////////
    //
    // setup the hardware
    //
    ///////////////////////////////////////////////////
    the_prox_sensor.setup();
    the_output_pin.setup();
    the_led.setup();

    //the_hw_controller.setup();

    //const auto close_value=the_prox_sensor.get_proximity_value_close();
    //const auto far_value=the_prox_sensor.get_proximity_value_far();

    //threshold=fabs((far_value-close_value)/2);
    threshold=512;
}


void loop()
{

    uint16_t value=the_prox_sensor.get_proximity();

    //uint16_t value=counter;
    counter++;
    //if (counter > 1024)
    //{
    //  counter =0;
    //}

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

    if ((counter % 1000)==0)
    {
        Serial.print(static_cast<int>(counter));
        Serial.print(":");
        Serial.print(static_cast<int>(value));
        Serial.print(" ");
        Serial.println();
    }
    // prints another carriage return
}
