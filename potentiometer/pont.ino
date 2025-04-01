#include <Servo.h>
int pot=A3;
Servo myServo;
void setup()                                                           {
  pinMode(pot,INPUT);
  myServo.attach(13);
  delay(2000);

}
void loop(){
  long int Volt;
  Volt=analogRead(pot);
  Volt=map(Volt,120,500,0,180);
   
  myServo.write(Volt);
  Serial.print("Potentio value: ");
  Serial.print(analogRead(pot));
  Serial.print("  servo angle: ");
  Serial.println(Volt);
  delay(1000);
}
