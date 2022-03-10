#include "proximity_sensor.h"

proximity_sensor::proximity_sensor(void):
the_i2c_interface(APDS_9151::i2c_address),
n_bits_read_out(11)                               // currently supports only 11 bit read out
{

}


void proximity_sensor::setup(void)
{
    using namespace APDS_9151;
    the_i2c_interface.setup();

    enable_proximity_sensor_only();

    const auto led_pulse_frequency = static_cast<uint8_t>(LED_PULSE_FREQUENCY::f_60_kHz);
    const auto led_current =  static_cast<uint8_t>(LED_CURRENT::pulse_100_mA);
    const auto n_pulses =  static_cast<uint8_t>(32);

    configure_proximity_sensor_led(led_pulse_frequency, led_current, n_pulses);

    // currently supports only 11 bit read out
    // assert(n_bits_read_out==11);
    const auto prox_res =  static_cast<uint8_t>(PROXIMITY_RESOLUTION::res_11_bit);

    const auto prox_rate =  static_cast<uint8_t>(PROXIMITY_MEASUREMENT_RATE::rate_50_ms);

    configure_proximity_sensor(prox_res, prox_rate);
}


void proximity_sensor::enable_proximity_sensor_and_color_sensor(void)
{
    using namespace APDS_9151;
    uint8_t merged_data= ( static_cast<uint8_t>(CTRL_FIELDS::rgb_mode) |
        static_cast<uint8_t>(CTRL_FIELDS::light_sensor_enable) |
        static_cast<uint8_t>(CTRL_FIELDS::proximity_sensor_enable));

    write_register(REGISTERS::reg_main_ctrl, merged_data );

}


void proximity_sensor::enable_proximity_sensor_only(void)
{
    using namespace APDS_9151;
    uint8_t merged_data=static_cast<uint8_t>(CTRL_FIELDS::proximity_sensor_enable);
    write_register(REGISTERS::reg_main_ctrl, merged_data );

}


void proximity_sensor::configure_proximity_sensor_led(uint8_t pulse_freq, uint8_t led_curr, uint8_t n_pulses)
{
    using namespace APDS_9151;
    const uint8_t merged_data=pulse_freq | led_curr;
    write_register(REGISTERS::reg_proximity_sensor_led, merged_data);
    write_register(REGISTERS::reg_proximity_sensor_pulses, n_pulses);
}


void proximity_sensor::configure_proximity_sensor(uint8_t measurement_resolution, uint8_t measurement_rate)
{
    using namespace APDS_9151;
    const uint8_t merged_data=measurement_resolution | measurement_rate;
    write_register(REGISTERS::reg_proximity_sensor_rate, merged_data);
}


uint32_t proximity_sensor::get_proximity()
{
    using namespace APDS_9151;

    //assert(n_bits_read_out==11);
    // this needs to be recoded if n_bits_read_out is changed
    return read_11_bit_register(REGISTERS::reg_proximity_data);
}


void proximity_sensor::write_register(APDS_9151::REGISTERS reg, uint8_t data)
{
    return the_i2c_interface.write_byte(static_cast<uint8_t>(reg), data);
}


uint16_t proximity_sensor::read_11_bit_register(APDS_9151::REGISTERS reg)
{
    uint8_t raw[2];
    const int n_bytes=2;

    the_i2c_interface.read_bytes(static_cast<uint8_t>(reg), raw, n_bytes);

    return to_11_bit(raw);
}
