#include <Servo.h>

Servo myservo;
int servoPin = 5; // Pin D1 (GPIO 5) is used to control the servo

void setup() {
  myservo.attach(servoPin); // Attach the servo to pin D1
  Serial.begin(9600); // Start serial communication
}

void loop() {
  if (Serial.available() > 0) {
    int deviation = Serial.parseInt(); // Read the incoming value
    deviation = constrain(deviation, -90, 90); // Constrain the value to -90 to 90 degrees
    myservo.write(deviation + 90); // Move the servo to the specified angle
  }
}