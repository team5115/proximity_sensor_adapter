#ifndef _digital_io_h_
#define _digital_io_h_

#include <Arduino.h>

class digital_io
{

    public:

        int m_pin_no;
        int m_direction;
        bool m_set_with_pullup;
    public:

        digital_io(int pin_no, int direction=OUTPUT, bool set_with_pullup=true);

        void setup(void);

        void set_value(int i);

        void set_high(void);
        void set_low(void);

        int get_value(void);
        bool get_is_high(void) {return get_value()==1;}

};
#endif
