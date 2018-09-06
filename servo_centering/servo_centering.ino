/*  
 *   Code to operate the MMP-5 with a Sabertooth Motor Controller set to R/C mode
 *   The Sabertooth expects to receive a "center" or "stop" position first (as if the R/C 
 *   joystick was in the neutral position.
 *   Then it expect to receive the end limits.
 *   If this code is not executed when the controller is powered up, the MMP-5 may move
 *   eratically or not at all
 *   COL Lisa A. Shay
 */

#include <Servo.h> 
 
Servo rightServo;  // create servo object to control a servo 
Servo leftServo;                // twelve servo objects can be created on most boards
 
int i = 0;      // loop counter
const int dur = 2;  // counter duration 2 is the minimun setting to 
                    // produce reliable results.  Increase to 25 if 
                    // the motor controller behaves eratically.
 
void setup() 
{ 
  rightServo.attach(10);   // attaches the servo on pin 10 to the servo object 
  leftServo.attach(11);
  //This is one of the servo ports on the Parallax shield. Others are 11, 12, and 13
  
  for (i = 0; i < dur; i++ ){ 
    rightServo.writeMicroseconds(1500);    // motor stop 
    leftServo.writeMicroseconds(1500);    // motor stop 
    delay(15); 
  }
  
  for (i = 0; i< dur; i++){
     rightServo.writeMicroseconds(1000);     // full speed in one direction
     leftServo.writeMicroseconds(1000);
     delay(15);  
  } 
  
  for (i = 0; i< dur; i++){
    rightServo.writeMicroseconds(2000);   // full speed in the other direction
    leftServo.writeMicroseconds(2000);
    delay(15);
  }  
  
  for (i = 0; i < dur; i++ ){ 
  rightServo.writeMicroseconds(1500);    // motor stop 
  leftServo.writeMicroseconds(1500);
  delay(15); 
  }

  
// test that code did what it was supposed to do (omit or replace with your algorithm)
/*
  for (i = 0; i< dur*100; i++){
     rightServo.writeMicroseconds(1250);     // half speed in one direction backwards
     leftServo.writeMicroseconds(1250);
     delay(15);  
  }
  
  for (i = 0; i< dur*100; i++){
     rightServo.writeMicroseconds(1750);     // half speed in one direction forwards
     leftServo.writeMicroseconds(1750);
     delay(15);  
  }*/
  
  forward(120);
  motorStop(20);
  turnRight(20);
  motorStop(20);
  turnLeft(20);
  
  motorStop(1);
  
} 
 
void loop() 
{ 

} 

void turnRight(int len){
  for (i = 0; i< dur*len; i++){
     rightServo.writeMicroseconds(1250);     // Clockwise 45 degrees 
     leftServo.writeMicroseconds(1750);
     delay(15);  
  }
}

void turnLeft(int len){
  for (i = 0; i< dur*len; i++){
     rightServo.writeMicroseconds(1750);     // counterclockwise 45 degrees
     leftServo.writeMicroseconds(1250);
     delay(15);  
  }
}

void motorStop(int len){
  for (i = 0; i < dur*len; i++ ){ 
    rightServo.writeMicroseconds(1500);    // motor stop 
    leftServo.writeMicroseconds(1500);
  delay(15); 
  }
}
  
void forward(int len){
  for (i = 0; i < dur*len; i++ ){ 
    rightServo.writeMicroseconds(2000);    // motor stop 
    leftServo.writeMicroseconds(2000);
  delay(15); 
  }
}

