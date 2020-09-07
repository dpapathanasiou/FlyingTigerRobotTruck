#include "ardu_motor.h"
#include "hc_sr04.h"
#include "lm393_mic.h"

const int echoPin = 7;
const int trigPin = 8;
float distance;

const int audioPin = A0;
int sound;

void setup() {
  Serial.begin(9600);
  setupArdumotor();
  setupHCSR04(echoPin, trigPin); // repeat with different pins for multiple sensors
  pinMode(LED_BUILTIN, OUTPUT);  // highlight sound detection
}

void loop() {
  // an example of reading from the sensors,
  // then starting and stopping the motors
  // TODO: extend these with more "intelligent" controls
  
  distance = getHCSR04Distance(echoPin, trigPin);
  Serial.print("Distance (cm) = ");
  Serial.println(distance, DEC);
  delay(200);

  sound = readMicrophone(audioPin);
  digitalWrite(LED_BUILTIN, sound);
  delay(10);

  driveArdumotor(MOTOR_A, FORWARD, 255);
  driveArdumotor(MOTOR_B, FORWARD, 255);
  delay(1000);
  stopArdumotor(MOTOR_A);
  stopArdumotor(MOTOR_B);
}
