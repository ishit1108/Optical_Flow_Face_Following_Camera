int x;
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 5;
Servo Servo1; 
int dir = 90; 
void setup() {
  Servo1.attach(servoPin);
 Serial.begin(115200);
 Serial.setTimeout(1);
 Servo1.write(90);
 Serial.write('D');
}
void loop() {
 while (!Serial.available());
 x = Serial.readString().toInt();
 if (x==2)
 {
  
   //Serial.print("LEFT");
   for(int l = 0;l<2;++l)
   {
    --dir;
    if(dir<=0)
  {
    dir = 0;
  }
   Servo1.write(dir);
   delay(50);
   Serial.print("D");
   }
   
 }
if (x==1)
 {
  
   //Serial.print("RIGHT");
   for(int l = 0;l<2;++l)
   {
    ++dir;
    if(dir<=0)
  {
    dir = 0;
  }
   Servo1.write(dir);
   delay(50);
   Serial.print("D");
   }
   
 }
 if (x==3)
 {
  // Serial.print("UP");
 }
 if (x==4)
 {
  // Serial.print("DOWN");
 }
}
