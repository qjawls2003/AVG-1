
#include <Servo.h> 
 
Servo rightServo;  // create servo object to control a servo 
Servo leftServo;                // twelve servo objects can be created on most boards
int i = 0;      // loop counter
const int dur = 2;
const int pingPin1 = 8;
const int pingPin2 = 7;



void setup()
{
Serial.begin(9600);
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

  //forward(120);
  //motorStop(20);
  //turnRight(20);
  //motorStop(20);
  //turnLeft(20);
  
  //motorStop(1);
  
}

void loop()
{
long duration1, duration2, cm1, cm2;
pinMode(pingPin1,OUTPUT);
digitalWrite(pingPin1,LOW);
delayMicroseconds(2);
digitalWrite(pingPin1,HIGH);
delayMicroseconds(5);
digitalWrite(pingPin1,LOW);
pinMode(pingPin1,INPUT);
duration1= pulseIn(pingPin1,HIGH);


pinMode(pingPin2,OUTPUT);
digitalWrite(pingPin2,LOW);
delayMicroseconds(2);
digitalWrite(pingPin2,HIGH);
delayMicroseconds(5);
digitalWrite(pingPin2,LOW);
pinMode(pingPin2,INPUT);
duration2= pulseIn(pingPin2,HIGH);


cm1=microsecondsToCentimeters(duration1);
cm2=microsecondsToCentimeters(duration2);
Serial.print(cm1);
Serial.print(" cm ");
Serial.print(cm2);
Serial.print(" cm ");
Serial.println();
delay(100);

if (cm2>60){
  forward(20);
}
else {
  motorStop(20);
}

if (cm1<60 and cm2<60){
    turnLeft(10);
  }


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
    rightServo.writeMicroseconds(1650);    // motor stop 
    leftServo.writeMicroseconds(1650);
  delay(15); 
  }
}

void reverse(int len){
  for (i = 0; i < dur*len; i++ ){ 
    rightServo.writeMicroseconds(1250);    // motor stop 
    leftServo.writeMicroseconds(1250);
  delay(15); 
  }
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

