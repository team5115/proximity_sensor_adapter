#include "digital_io.h"
#include <Arduino.h>

digital_io::digital_io(int pin_no, int direction, bool set_with_pullup):
m_pin_no(pin_no),
m_direction(direction),
m_set_with_pullup(set_with_pullup)
{

}


void digital_io::setup(void)
{

    pinMode(m_pin_no, m_direction);
    if (m_direction==OUTPUT)
    {

        set_value(0);
    }
    else
    {
        if (m_set_with_pullup)
        {

            pinMode(m_pin_no, INPUT_PULLUP);
        }
        else
        {
            pinMode(m_pin_no, INPUT);
        }
    }
}


void digital_io::set_value(int i)
{

    if (i==0)
    {
        digitalWrite(m_pin_no, LOW);
    }
    else
    {
        digitalWrite(m_pin_no, HIGH);
    }
}


int digital_io::get_value(void)
{
    return digitalRead(m_pin_no);
}


void digital_io::set_high(void) {set_value(1);}
void digital_io::set_low(void)  {set_value(0);}
