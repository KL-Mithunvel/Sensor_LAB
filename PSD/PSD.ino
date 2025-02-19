#include <Servo.h>
int pin_S = 13;
int pin_PSD = A0;
Servo SERVO;


void setup() {
    Serial.begin(115200);
    pinMode(pin_PSD,INPUT);
    SERVO.attach(pin_S);
    while(!Serial);
}

void loop() {
  long int Dist, ADC_data, Volt;
  char *message;
  ADC_data = analogRead(pin_PSD);
  Dist = 10000 / (ADC_data*434*5/1023-46);
  if(Dist>80){
    Dist=80;
  }
  else if(Dist<10){
    Dist=10;
  }
  if(Dist<15){
    SERVO.write(0);
    message="Tap is open";
  }
  else{
    SERVO.write(180);
     message="Tap is Closed";
  }
  Serial.print("ADC Data:");
  Serial.print(ADC_data);
  Serial.print(", Dist:");
  Serial.print(Dist);
  Serial.print("[Cm] , ");
  Serial.println(message);
  delay(500);

}
