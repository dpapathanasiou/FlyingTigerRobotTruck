#ifndef ARDU_MOTOR_H_
#define ARDU_MOTOR_H_

// based on example sketch at https://learn.sparkfun.com/tutorials/ardumoto-kit-hookup-guide#example-code

#define FORWARD 1
#define REVERSE 0

#define MOTOR_A 0
#define MOTOR_B 1

#define DIRA 2  // Direction control for motor A
#define PWMA 3  // PWM control (speed) for motor A
#define DIRB 4  // Direction control for motor B
#define PWMB 11 // PWM control (speed) for motor B

extern void setupArdumotor() {
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}

void spin(int directionPin, int speedPin, byte dir, byte spd) {
  digitalWrite(directionPin, dir); // direction [FORWARD, REVERSE]
  analogWrite (speedPin,     spd); // speed (0-255)
}

extern void driveArdumotor(byte motor, byte dir, byte spd) {
  if (motor == MOTOR_A) {
    spin(DIRA, PWMA, dir, spd);
  }
  if (motor == MOTOR_B) {
    spin(DIRB, PWMB, dir, spd);
  }
}

extern void stopArdumotor(byte motor) {
  driveArdumotor(motor, 0, 0);
}

#endif // ARDU_MOTOR_H_
