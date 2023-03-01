#include "color_sensor_v3.h"
#include "bit_conversion_utils.h"

// color_sensor_v3::color_sensor_v3(void)
// //the_i2c_interface(APDS_9151::i2c_address),
// //n_bits_read_out(11)                               // currently supports only 11 bit read out
// {

// }

void color_sensor_v3::setup(void)
{
    //using namespace APDS_9151;
    apds_9151_base_device::setup();

    enable_color_sensor();

    const auto color_resolution=APDS_9151::color_resolution_t::k13bit;
    const auto color_measurement_rate=APDS_9151::color_measurement_rate_t::k100ms;

    configure_color_sensor(color_resolution,color_measurement_rate);

}


void color_sensor_v3::enable_color_sensor(void)
{
    const auto datum=static_cast<uint8_t>(APDS_9151::CTRL_FIELDS::rgb_mode);
    write_register(APDS_9151::REGISTERS::reg_main_ctrl, datum);
}


void color_sensor_v3::configure_color_sensor(APDS_9151::color_resolution_t res, APDS_9151::color_measurement_rate_t rate)
{

    const auto merged_data= (static_cast<uint8_t>(res) |  static_cast<uint8_t>(rate));
    write(APDS_9151::REGISTERS::reg_light_sensor_measurement_rate, merged_data);
}


raw_color_t color_sensor_v3::get_raw_color()
{

    const int n_bytes=12;
    uint8_t raw_buffer[n_bytes];

    const auto reg=APDS_9151::REGISTERS::reg_data_infrared;

    read(reg, n_bytes, raw_buffer);

    const auto ir    =to_20_bit(&raw_buffer[0]);
    const auto green =to_20_bit(&raw_buffer[3]);
    const auto blue  =to_20_bit(&raw_buffer[6]);
    const auto red   =to_20_bit(&raw_buffer[9]);

    const raw_color_t the_raw_color(red, green, blue, ir);

    //const raw_color_t the_raw_color(to_20_bit(&raw[9]), to_20_bit(&raw[3]), to_20_bit(&raw[6]), to_20_bitmak(&raw[0]));

    return the_raw_color;
}
