#include "i2c_interface.h"

i2c_interface::
i2c_interface(int i2c_address):
m_i2c_address(i2c_address)
{

    //  m_buffer_size=13;
}


void i2c_interface::setup(void)
{
    Wire.begin();                                 // Initiate the Wire library;

}


void i2c_interface::write_byte(uint8_t reg, uint8_t val)
{
    Wire.beginTransmission(m_i2c_address);
    Wire.write(reg);
    Wire.write(val);
    Wire.endTransmission();

}


// void i2c_interface::i2c_write_bulk(uint8_t reg, uint8_t val, uint16_t len)
// {
//     // Wire.beginTransmission(m_i2c_address);
//     // Wire.write(reg);
//     // Wire.write(val);
//     // Wire.endTransmission();

// }

void i2c_interface::read_bytes(uint8_t reg, uint8_t* val, uint16_t len)
{

    Wire.beginTransmission(m_i2c_address);
    Wire.write(reg);
    Wire.endTransmission();

    Wire.requestFrom(m_i2c_address, len);

    for(uint8_t i=0; i<len; i++)
    {
        val[i]=Wire.read();
    }

}
