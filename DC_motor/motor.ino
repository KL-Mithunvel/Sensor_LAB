int pin_DC_A=5;
int pin_DC_B=6;
void setup(){
  pinMode(pin_DC_A, OUTPUT);
  pinMode(pin_DC_B, OUTPUT);}
void loop(){
  int Speed_value;
  for(Speed_value=0;Speed_value<170;Speed_value++){
    forwardRotation(Speed_value);
    delay(20);}
    
  Stop();
  delay(7000);
  
  for(Speed_value=200;Speed_value<0;Speed_value--){
    reverseRotation(Speed_value);
    delay(20);}
  Stop();
  delay(7000);
}

void forwardRotation(int Speed)
{
  analogWrite(pin_DC_A,Speed);
  digitalWrite(pin_DC_B,0);
}
void reverseRotation(int Speed)
{
  analogWrite(pin_DC_B,Speed);
  digitalWrite(pin_DC_A,0);
}
void Stop(void)
{
  digitalWrite(pin_DC_A,0);
  digitalWrite(pin_DC_B,0);
}

