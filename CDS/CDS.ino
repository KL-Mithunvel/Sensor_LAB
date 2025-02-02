// Save the pin number of Light Sensor
int pin_CDS = A1;
void setup() {
// Serial Setting : Baud rate 115200, data 8bit, no parity, stop 1bit
Serial.begin(115200); // same as Serial.begin(115200, SERIAL_8N1)
// Set the pin of the light sensor as an input pin
pinMode(pin_CDS, INPUT);
//Wait until the serial port is connected
while(!Serial);
}
void loop() {
unsigned int ADC_data;
// Read the analog value of the light sensor as a digital value
// The higher the digital value, the brighter the light
ADC_data = analogRead(pin_CDS);
// Outputs "ADC Data : " serially
Serial.print("ADC Data : ");
// Outputs the ADC value in serial Serial.println(ADC_data);
delay(500);
}


part 2

// Save the pin number of Light Sensor
int pin_CDS = A1;
// Save the pin number of LED0
int pin_LED0 = 5;
void setup() {
// Set the pin of the light sensor as an input pin
pinMode(pin_CDS, INPUT);
// Set LED0 pin as output pin
pinMode(pin_LED0, OUTPUT);
}
void loop() {
uint16_t ADC_data;
// Read the analog value of the light sensor as a digital value
// The higher the digital value, the brighter the light
ADC_data = analogRead(pin_CDS);
// If the value measured by light sensor is less than 512, turn on LED0
if(ADC_data < 512)
{
// Output HIGH to LED0 pin (LED0 ON)
digitalWrite(pin_LED0, 1);
}
// If the value measured by light sensor is greater than or equal to 512,
turn off LED0
else
{
// Output LOW to LED0 pin (LED0 OFF)
digitalWrite(pin_LED0, 0);
}
delay(100);
}
