int pin_CDS = A1;   // pin number of Light Sensor
int pin_LED0 = 5;    // pin number of LED0
void setup() {
  pinMode(pin_CDS, INPUT);       // Set  light sensor pin as an input pin

  pinMode(pin_LED0, OUTPUT);        // Set LED0 pin as output pin
  // Serial Setting : Baud rate 115200, data 8bit, no parity, stop 1bit
  Serial.begin(115200);    // same as Serial.begin(115200, SERIAL_8N1)
  while(!Serial);          //Wait until the serial port is connected
}
void loop() {
  uint16_t ADC_data;
  // Read the analog value of the light sensor as a digital value
  // The higher the digital value, the brighter the light
  ADC_data = analogRead(pin_CDS);
  Serial.print("ADC Data : ");
  Serial.println(ADC_data);    // Outputs the ADC value in serial 
  // If the value measured by light sensor is less than 512, turn on LED0
  if(ADC_data < 512){
    // Output HIGH to LED0 pin (LED0 ON)
    digitalWrite(pin_LED0, 1);}
  // If the value measured by light sensor is greater than or equal to 512,turn off LED0
  else{
    // Output LOW to LED0 pin (LED0 OFF)
    digitalWrite(pin_LED0, 0);}
delay(500);
}
