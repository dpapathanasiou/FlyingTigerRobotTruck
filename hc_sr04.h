#ifndef HC_SR04_H_
#define HC_SR04_H_

const float v = 343.5;

extern void setupHCSR04(int echoPin, int trigPin) {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

extern float getHCSR04Distance(int echoPin, int trigPin) {
  // send sound pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  // listen for echo
  float t = pulseIn(echoPin, HIGH) / 1000.0 / 1000.0 / 2;

  // TODO: when right up against something, this
  // function computes values like 3198.6032714843
  // so return 0.0 in those circumstances

  return t * v * 100; // centimeters
}

#endif // HC_SR04_H_
