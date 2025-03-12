const int sensor_pin = A0;
 Serial.begin(115200); }
 
void loop() {
 float moisture_percentage;
 int sensor_analog;
 sensor_analog = analogRead(sensor_pin);
 moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
 Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print(", analog = ");
 Serial.println(sensor_analog);
 delay(1000);
}
