#define trigPin1 9
#define echoPin1 8
#define LED_first_ping 22

#define trigPin2 10
#define echoPin2 11
#define LED_second_ping 24

long duration, distance, UltraSensor1, UltraSensor2;
char data;
String SerialData="";

void setup()
{
Serial.begin(9600);
pinMode(trigPin1,OUTPUT);
pinMode(echoPin1,INPUT);
pinMode(LED_first_ping, OUTPUT);
pinMode(trigPin2,OUTPUT);
pinMode(echoPin2,INPUT);
pinMode(LED_second_ping, OUTPUT);
digitalWrite(LED_first_ping,LOW);
digitalWrite(LED_second_ping,LOW);
}
void loop()
{
SonarSensor(trigPin1,echoPin1);
UltraSensor1=distance;
SonarSensor(trigPin2,echoPin2);
UltraSensor2=distance;

while(Serial.available())
{
  delay(10);
  data=Serial.read();
  SerialData+=data;
}

if(SerialData=="display distance")
{
Serial.println("distance measured by the first sensor: ");
Serial.print(UltraSensor1);
Serial.print(" cm");
Serial.println("distance measured by the second sensor: ");
Serial.print(UltraSensor2);
Serial.print(" cm");
}

SerialData="";
if(UltraSensor1 <=10)
{
  digitalWrite(LED_first_ping,HIGH);
}
else
{
  digitalWrite(LED_first_ping,LOW);
}

if(UltraSensor2 <=10)
{
  digitalWrite(LED_first_ping,HIGH);
}
else
{
  digitalWrite(LED_first_ping,LOW);
}
}

void SonarSensor(int trigPinSensor, int echoPinSensor)
{
digitalWrite(trigPinSensor,LOW);
delayMicroseconds(2);
digitalWrite(trigPinSensor,HIGH);
delayMicroseconds(10);
digitalWrite(trigPinSensor,LOW);

duration=pulseIn(echoPinSensor,HIGH);
distance=(duration/2)/29.1;
}

