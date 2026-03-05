#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int ledPin = 8;    // digital pin 8
const int proximityPin = 7; // digital pin 7
const int servoPin = 6; // digital pin 6

const int initialPos = 72; // servo initial position
const int endPos = 180;    // servo end position

int state = HIGH;   // keep the proximity state
bool flag = false; // keep the old proximity state

void setup() {
  pinMode(ledPin, OUTPUT);      // Set led pin as output
  pinMode(proximityPin, INPUT); // Set proximity pin as input

  myservo.write(initialPos);    // rotate the servo at the initial position
  myservo.attach(servoPin);     // attaches the servo on the servo pin
}

void loop() {
  state = digitalRead(proximityPin); // reads the state of the proximity sensor

  if (state == LOW && !flag) {
    flag = true;
    digitalWrite(ledPin, HIGH); // Turn led ON
    myservo.write(endPos);      // rotate the servo out
    delay(1000);

    myservo.write(initialPos);  // rotate the servo in
    delay(1000);
  } else if (state == HIGH && flag) {
    flag = false;
    digitalWrite(ledPin, LOW);  // Turn led OFF
  }
  delay(100);
}