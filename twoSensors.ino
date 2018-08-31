const int pingPin1 = 8;
const int pingPin2 = 7;

void setup()
{
Serial.begin(9600);
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
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

