const int sensor_pin = A0; 
int red =9;
int green =10;
void setup() {
 Serial.begin(115200);
  pinMode(sensor_pin, INPUT); 
 pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);}
 
void loop() {
 
 int sensor_analog;
 sensor_analog = analogRead(sensor_pin);
 Serial.println(sensor_analog);
   if(sensor_analog < 390){
    // Output HIGH to LED0 pin (LED0 ON)
    digitalWrite(green, 1);
    digitalWrite(red, 0);}
  // If the value measured by light sensor is greater than or equal to 512,turn off LED0
  else{
    // Output LOW to LED0 pin (LED0 OFF)
    digitalWrite(green, 0);
    digitalWrite(red, 1);}
 delay(1000);
}
