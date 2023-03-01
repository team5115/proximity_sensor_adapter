#ifndef _apds_9151_constants_h_
#define _apds_9151_constants_h_

namespace APDS_9151
{

    const int i2c_address = 0x52;

    // the enum class is a c++11 scoped enumerations these will have type
    // of the class name and will need to be cast to uint8_t
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
        reg_light_sensor_measurement_rate = 0x04,
        reg_light_sensor_gain = 0x05,
        reg_part_id = 0x06,
        reg_main_status = 0x07,
        reg_proximity_data = 0x08,
        reg_data_infrared = 0x0A,
        reg_data_green = 0x0D,
        reg_data_blue = 0x10,
        reg_data_red = 0x13

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

    enum class color_resolution_t
    {
        k20bit = 0x00,
        k19bit = 0x10,
        k18bit = 0x20,
        k17bit = 0x30,
        k16bit = 0x40,
        k13bit = 0x50,
    };

    enum class color_measurement_rate_t
    {
        k25ms = 0,
        k50ms = 1,
        k100ms = 2,
        k200ms = 3,
        k500ms = 4,
        k1000ms = 5,
        k2000ms = 7,
    };

    // This is a transformation matrix given by the chip
    // manufacturer to transform the raw RGB to CIE XYZ
    constexpr double Cmatrix[9] =
    {
        0.048112847, 0.289453437, -0.084950826,
        -0.030754752, 0.339680186, -0.071569905,
        -0.093947499, 0.072838494,  0.34024948
    };

}                                                 // end of namespace
#endif
