#include "apds_9151_base_device.h"

apds_9151_base_device::apds_9151_base_device(void):
the_i2c_interface(APDS_9151::i2c_address)
{

}


void apds_9151_base_device::setup(void)
{
    using namespace APDS_9151;
    the_i2c_interface.setup();

}


void apds_9151_base_device::write_register(APDS_9151::REGISTERS reg, uint8_t data)
{

    return the_i2c_interface.write_byte(static_cast<uint8_t>(reg), data);

}


void apds_9151_base_device::write(APDS_9151::REGISTERS reg, uint8_t data)
{

    return the_i2c_interface.write_byte(static_cast<uint8_t>(reg), data);

}


void apds_9151_base_device::read(APDS_9151::REGISTERS reg, int count, uint8_t* data)
{

    return the_i2c_interface.read_bytes(static_cast<uint8_t>(reg), data, count);

}


uint16_t apds_9151_base_device::read_11_bit_register(APDS_9151::REGISTERS reg)
{
    const int n_bytes=2;
    uint8_t raw[2];

    the_i2c_interface.read_bytes(static_cast<uint8_t>(reg), raw, n_bytes);

    return to_11_bit(raw);
}


uint32_t apds_9151_base_device::read_20_bit_register(APDS_9151::REGISTERS reg)
{
    const int n_bytes=3;
    uint8_t raw[n_bytes];

    the_i2c_interface.read_bytes(static_cast<uint8_t>(reg), raw, n_bytes);

    return to_20_bit(raw);

}
