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
