#include "proximity_sensor.h"

//

const int i2c_address = 0x52;

// the enum class is a c++11  scoped enumerations

enum class LED_PULSE_FREQUENCY
{
    f_60_kHz = 0x18,
    f_70_kHz = 0x40,
    f_80_kHz = 0x28,
    f_90_kHz = 0x30,
    f_100_kHz = 0x38,
};

enum class LED_CURRENT
{
    pulse_2_mA = 0,
    pulse_5_mA = 1,
    pulse_10_mA = 2,
    pulse_25_mA = 3,
    pulse_50_mA = 4,
    pulse_75_mA = 5,
    pulse_100_mA = 6,
    pulse_125_mA = 7,
};

enum class PROXIMITY_RESOLUTION
{
    res_8_bit = 0x00,
    res_9_bit = 0x08,
    res_10_bit = 0x10,
    res_11_bit = 0x18,
};

enum class PROXIMITY_MEASUREMENT_RATE
{
    rate_6_ms = 1,
    rate_12_ms = 2,
    rate_25_ms = 3,
    rate_50_ms = 4,
    rate_100_ms = 5,
    rate_200_ms = 6,
    rate_400_ms = 7,
};

enum class REGISTERS
{
    reg_main_ctrl = 0x00,
    reg_proximity_sensor_led = 0x01,
    reg_proximity_sensor_pulses = 0x02,
    reg_proximity_sensor_rate = 0x03,
    reg_proximity_data = 0x08,
};

/*
enum class REGISTERS_FULL
{


  MAIN_CTRL=0x00,
  PS_LED =0x01,
  PS_PULSES =0x02,
  PS_MEAS_RATE=0x03,
  LS_MEAS_RATE=0x04,
  LS_Gain=0x05,
  PART_ID=0x06,
  MAIN_STATUS=0x07,
  PS_DATA_0=0x08,
  PS_DATA_1=0x09,
  LS_DATA_IR_0=0x0A,
  LS_DATA_IR_1=0x0B,
  LS_DATA_IR_2=0x0C,
  LS_DATA_GREEN_0=0x0D,
  LS_DATA_GREEN_1=0x0E,
  LS_DATA_GREEN_2=0x0F,
  LS_DATA_BLUE_0=0x10,
  LS_DATA_BLUE_1=0x11,
  LS_DATA_BLUE_2=0x12,
  LS_DATA_RED_0=0x13,
  LS_DATA_RED_1=0x14,
  LS_DATA_RED_2=0x15,
  INT_CFG=0x19,
  INT_PST=0x1A,
  PS_THRES_UP_0=0x1B,
 PS_THRES_UP_1=0x1C,
 PS_THRES_LOW_0=0x1D,
 PS_THRES_LOW_1=0x1E,
 PS_CAN_0=0x1F,
 PS_CAN_1=0x20,
 LS_THRES_UP_0=0x21,
 LS_THRES_UP_1=0x22,
 LS_THRES_UP_2=0x23,
 LS_THRES_LOW_0=0x24,
 LS_THRES_LOW_1=0x25,
 LS_THRES_LOW_2=0x26,
 LS_THRES_VAR=0x27,
};
*/

enum class CTRL_FIELDS
{
    proximity_sensor_enable = 0x01,
    light_sensor_enable = 0x02,
    rgb_mode = 0x04
};


proximity_sensor::proximity_sensor(void):
the_i2c_interface(i2c_address)
{

}


void proximity_sensor::setup(void)
{

    the_i2c_interface.setup();

    enable_proximity_sensor_only();

    const auto led_pulse_frequency = static_cast<uint8_t>(LED_PULSE_FREQUENCY::f_60_kHz);
    const auto led_current =  static_cast<uint8_t>(LED_CURRENT::pulse_100_mA);
    const auto n_pulses =  static_cast<uint8_t>(32);

    configure_proximity_sensor_led(led_pulse_frequency, led_current, n_pulses);


    const auto prox_res =  static_cast<uint8_t>(PROXIMITY_RESOLUTION::res_11_bit);
    const auto prox_rate =  static_cast<uint8_t>(PROXIMITY_MEASUREMENT_RATE::rate_50_ms);

    configure_proximity_sensor(prox_res, prox_rate);
}


void proximity_sensor::enable_proximity_sensor_and_color_sensor(void)
{
    uint8_t merged_data= ( static_cast<uint8_t>(CTRL_FIELDS::rgb_mode) |
        static_cast<uint8_t>(CTRL_FIELDS::light_sensor_enable) |
        static_cast<uint8_t>(CTRL_FIELDS::proximity_sensor_enable));

    write_register(REGISTERS::reg_main_ctrl, merged_data );

}


void proximity_sensor::enable_proximity_sensor_only(void)
{

    uint8_t merged_data=static_cast<uint8_t>(CTRL_FIELDS::proximity_sensor_enable);

    write_register(REGISTERS::reg_main_ctrl, merged_data );

}


void proximity_sensor::configure_proximity_sensor_led(uint8_t pulse_freq, uint8_t led_curr, uint8_t n_pulses)
{
    const uint8_t merged_data=pulse_freq | led_curr;

    write_register(REGISTERS::reg_proximity_sensor_led, merged_data);
    write_register(REGISTERS::reg_proximity_sensor_pulses, n_pulses);
}


void proximity_sensor::configure_proximity_sensor(uint8_t measurement_resolution, uint8_t measurement_rate)
{
    const uint8_t merged_data=measurement_resolution | measurement_rate;

    write_register(REGISTERS::reg_proximity_sensor_rate, merged_data);
}


uint32_t proximity_sensor::get_proximity()
{


  // thi is an 11 bit value so we w
  
    return read_11_bit_register(static_cast<uint8_t>(REGISTERS::reg_proximity_data));
}


void proximity_sensor::write_register(register_t reg, uint8_t data)
{
    return the_i2c_interface.write_byte(static_cast<uint8_t>(reg), data);
}


uint16_t proximity_sensor::read_11_bit_register(register_t reg)
{
    uint8_t raw[2];
    const int n_bytes=2;

    the_i2c_interface.read_bytes(static_cast<uint8_t>(reg), raw, n_bytes);

    return to_11_bit(raw);
}


