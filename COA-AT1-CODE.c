#include <Servo.h>
Servo robot;
const int startBtn = 2;
const int stopBtn = 3;
const int emergencyBtn = 4;
const int greenLED = 5;
const int yellowLED = 6;
const int redLED = 7;
const int buzzer = 8;
const int pot = A0;
int speedValue;
void setup()
{
  pinMode(startBtn, INPUT_PULLUP);
  pinMode(stopBtn, INPUT_PULLUP);
  pinMode(emergencyBtn, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  robot.attach(9);
  Serial.begin(9600);
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
}
void loop()
{
  if(digitalRead(emergencyBtn)==LOW)
  {
      robot.write(90);
      digitalWrite(redLED,HIGH);
      digitalWrite(greenLED,LOW);
      digitalWrite(yellowLED,LOW);
      tone(buzzer,1000);
      Serial.println("Emergency Stop");
      delay(500);
      return;
  }
  noTone(buzzer);
  if(digitalRead(startBtn)==LOW)
  {
      speedValue = analogRead(pot);
      int angle = map(speedValue,0,1023,0,180);
      robot.write(angle);
      digitalWrite(greenLED,HIGH);
      digitalWrite(yellowLED,LOW);
      digitalWrite(redLED,LOW);
      Serial.print("Robot Running Speed = ");
      Serial.println(angle);
      delay(100);
  }
  if(digitalRead(stopBtn)==LOW)
  {
      robot.write(90);
      digitalWrite(greenLED,LOW);
      digitalWrite(yellowLED,HIGH);
      digitalWrite(redLED,LOW);
      Serial.println("Production Stopped");
      delay(300);
  }
}

