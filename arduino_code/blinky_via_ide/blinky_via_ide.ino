
// Define  Serial for using the Arduino Zero's programming port
//#define Serial Serial5

void setup() {
  // put your setup code here, to run once:
// initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

void loop() {

  for (int i=1;i<3;i++)
  {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("HIGH");   // send the state to the serial monitor
  delay(200);    
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  Serial.println("LOW");
  delay(200);
  }

  
// wait for two second
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("HIGH");   // send the state to the serial monitor
  delay(2000);              // wait for two second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  Serial.println("LOW");
  delay(500);
}
