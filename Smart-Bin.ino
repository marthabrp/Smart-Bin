#include <Servo.h>

int distancia = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_9;

void setup()
{
  servo_9.attach(9);

}

void loop()
{
  distancia = 0.01723 * readUltrasonicDistance(7, 6);
  servo_9.write(0);
  delay(3000); // Wait for 3000 millisecond(s)
  while (distancia <= 20) {
    servo_9.write(180);
    delay(3000); // Wait for 3000 millisecond(s)
    distancia = 0.01723 * readUltrasonicDistance(7, 6);
  }
}
