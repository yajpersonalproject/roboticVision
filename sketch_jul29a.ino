#include <Servo.h>

Servo claw, lifter, xRot;
String entry;

void setup()
{
  claw.attach(5);
  lifter.attach(4);
  xRot.attach(3);
  Serial.begin(9600);
  
}

void grablift(){
  delay(2000);
  claw.write(0);
  delay(1000);
  claw.write(180);
  delay(1000);
  lifter.write(0);
  delay(1000);
}

void loop()
{
  xRot.write(90);
  delay(1000);;
  while(Serial.available()){
    lifter.write(0);
    delay(2000);
    lifter.write(110);
    entry = Serial.readString(); 
    int cy = entry.toInt();
    int moveangle = map(cy, 0, 480, 0, 180);
    delay(2000);
    xRot.write(moveangle);
    grablift();
  }
 }

 
