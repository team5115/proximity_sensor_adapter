#include <Arduino.h>

// Define  Serial for using the Arduino nano's programming port

// the PB5 macro seems to give the correct LED
// for the nano the builtin LED is on pin 13
#define PIN_LED 13

//#define USE_SERIAL_PORT

void setup()
{
  #ifdef USE_SERIAL_PORT
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  #endif

  // initialize digital pin PIN_LED as an output.
  pinMode(PIN_LED, OUTPUT);
}

void loop()
{
  const int sleep_time_ms=200;
  for (int i=0; i<3 ;i++)
  {

    digitalWrite(PIN_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
#ifdef USE_SERIAL_PORT
    Serial.println("HIGH");   // send the state to the serial monitor
#endif
    
    delay(sleep_time_ms);
    

    digitalWrite(PIN_LED, LOW);    // turn the LED off by making the voltage LOW

#ifdef USE_SERIAL_PORT
    Serial.println("LOW");
#endif
    
    delay(sleep_time_ms);
  }

  
  delay(sleep_time_ms*3);
}
