#ifndef _i2c_interface_h_
#define _i2c_interface_h_

#include <Arduino.h>
#include <Wire.h>

class i2c_interface
{
    public:
        i2c_interface(int i2c_address);

    protected:
        int m_i2c_address;

    public:
        void setup(void);
        //void i2c_write_bulk(uint8_t reg, uint8_t val, uint16_t len);

        void write_byte(uint8_t reg, uint8_t val);

        void read_bytes(uint8_t reg, uint8_t* val, uint16_t len);

};
#endif
