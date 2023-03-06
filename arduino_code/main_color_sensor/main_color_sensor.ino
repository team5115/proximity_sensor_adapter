#include <Arduino.h>
#include "version.h"
#include "digital_io.h"
#include "proximity_sensor.h"
#include "color_sensor_v3.h"
#include "ncolor.h"

#define SERIAL_DEBUG_ENABLED
#define SerialPort SerialUSB
//#define SerialPort Serial
// this is the pin the arduino will output on
// this is the digital pin
// so 7 is digital 7 or D7
const int output_pin_number_red=7;
const int output_pin_number_green=8;
const int output_pin_number_blue=9;

// this is the proximity sensor threshold where the arduino says there
// is a ball
// close is 2047, far is 0
//
uint16_t threshold=512;

// construct the proximity_sensor object and output pins
color_sensor_v3 the_color_sensor;

digital_io output_pin_red(output_pin_number_red, OUTPUT);
digital_io output_pin_green(output_pin_number_green, OUTPUT);
digital_io output_pin_blue(output_pin_number_blue, OUTPUT);

digital_io the_led(13, OUTPUT);

#ifdef SERIAL_DEBUG_ENABLED
uint16_t serial_debug_counter=0;
#endif

void setup()
{

    Wire.begin();

    // for the Arduino Zero serial ports on complicated
    //  Serial - Programming Port (the path is SAMD->uart->EDBG->usb->PC)
    //  Serial1 - Serial uart on pins 0 and 1
    //  SerialUSB - Native Port, this is an emulated serial port (USB-CDC)
    //
    // I've only been succesful in uploading this via the native USB port
    // using the arduino ide. both 1de v1.8 and v2.x seem to work
    //
    // I use serialUSB so the serial debug messages are on the same cable as
    // the programming cable

    #ifdef SERIAL_DEBUG_ENABLED
    //Serial.begin(115200);
    //Serial.begin(9600);
    SerialPort.begin(115200);
    #endif

    //////////////////////////////////////////////////////
    //
    // setup the hardware
    //
    ///////////////////////////////////////////////////
    the_color_sensor.setup();

    output_pin_red.setup();
    output_pin_green.setup();
    output_pin_blue.setup();
    the_led.setup();

    //const auto close_value=the_color_sensor.get_proximity_value_close();
    //const auto far_value=the_color_sensor.get_proximity_value_far();
    //threshold=fabs((far_value-close_value)/2);
    //    threshold=512;
}


void loop()
{

    raw_color_t the_raw_color=the_color_sensor.get_raw_color();
    // the sensor has an inverse response
    ncolor_t the_color(the_raw_color);

    auto r_red=the_raw_color.red;
    auto r_green=the_raw_color.green;
    auto r_blue=the_raw_color.blue;
    auto r_ir=the_raw_color.ir;

    auto red=the_color.red;
    auto green=the_color.green;
    auto blue=the_color.blue;

    output_pin_red.set_value(red>threshold);
    output_pin_green.set_value(blue>threshold);
    output_pin_blue.set_value(green>threshold);

    the_led.set_value(red>threshold);

    #ifdef SERIAL_DEBUG_ENABLED
    if ((serial_debug_counter++ % 1000)==0)
    {

        SerialPort.print("\n");
        for(size_t i=0; i < the_color_sensor.n_bytes; i++)
        {
            uint8_t x_i=the_color_sensor.raw_buffer[i];

            ;
            //SerialPort.print(i);
            //SerialPort.print(i);
            SerialPort.print("[0x");
            SerialPort.print(x_i,HEX);
            SerialPort.print("]");

        }

        SerialPort.print("\n");

        SerialPort.print(static_cast<int>(serial_debug_counter));
        SerialPort.print(":");
        SerialPort.print(" RAW=");
        SerialPort.print("(");
        SerialPort.print(r_red);
        SerialPort.print(",");
        SerialPort.print(r_green);
        SerialPort.print(",");
        SerialPort.print(r_blue);
        SerialPort.print(",");
        SerialPort.print(r_ir);
        SerialPort.print(")");
        SerialPort.print("\t Norm=");
        SerialPort.print("(");
        SerialPort.print(red);
        SerialPort.print(",");
        SerialPort.print(green);
        SerialPort.print(",");
        SerialPort.print(blue);
        SerialPort.print(")");
        SerialPort.println();
    }
    // prints another carriage return
    #endif

}
