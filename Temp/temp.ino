int pin_TEMP = A4;
int pin_DC_A = 5;
int pin_DC_B = 6;
void setup(){
  pinMode(pin_TEMP, INPUT);
  pinMode(pin_DC_A, OUTPUT);
  pinMode(pin_DC_B, OUTPUT);
  pinMode(pin_TEMP, INPUT);
  while(!Serial);
}


void loop() {
  long int Temp, ADC_data;
  //Reads the analog value of temperature sensor as 10-bit digital value
  ADC_data=analogRead(pin_TEMP);
  //Convert digital value to temperature value
  //Temp=Voltage[V]*100
  Temp = ADC_data * 100 * 5/ 1023;
  //Outputs "ADC Data: " serially
  Serial.print("ADC_data:");
  //Output the measured value of temperature sensor serially
  Serial.print(ADC_data);
  //Outputs ", Temp :" serially
  Serial.print(", Temp :");
  //Outputs temperature value serially
  Serial.print(Temp);
  //outputs "[C]" serially
  Serial.println("[C]");
  delay(500);
  if(Temp<31)
  {
    forwardRotation(100);
  }
  else if(Temp>31)
  {
    reverseRotation(100);
  }
  else{
    Stop();
    }
    delay(100);
  }
  void forwardRotation(int Speed){
    analogWrite(pin_DC_A, Speed);
    digitalWrite(pin_DC_B, 0);
  }
  void reverseRotation(int Speed){
    analogWrite(pin_DC_B, Speed);
    digitalWrite(pin_DC_A, 0);
  }
  void Stop(void){
    digitalWrite(pin_DC_A, 0);
    digitalWrite(pin_DC_B, 0);
  }
