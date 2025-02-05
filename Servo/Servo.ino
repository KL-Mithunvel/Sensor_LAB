#include <Servo.h>
int pin_SERVO = 13;
Servo SERVO;

void setup(){
  SERVO.attach(pin_SERVO);
  
  SERVO.write(0);
  delay(2000);
  }

void loop(){
  unsigned char angle;
  for(angle=0;angle<=180;angle+=5){
    SERVO.write(angle);
    delay(500);
    }
   delay(1000);
     for(angle=180;angle>=90;angle-=10){
    SERVO.write(angle);
    delay(1000);
   }
   delay(1000);
   SERVO.write(0);
   delay(1000);
  } 
