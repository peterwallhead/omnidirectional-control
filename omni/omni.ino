#define frontLeftFwdPin     2   // PWM1 output
#define frontLeftBkPin      3   // PWM2 output

#define frontRightFwdPin    4   // PWM1 output
#define frontRightBkPin     5   // PWM2 output

#define backLeftFwdPin      6   // PWM1 output
#define backLeftBkPin       7   // PWM2 output

#define backRightFwdPin     8   // PWM1 output
#define backRightBkPin      9   // PWM2 output


void setup() {
  long i;
  
  for(i=2; i<10; ++i) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  delay(3000);

  driftLeft(100);
  delay(3000);

  driftRight(100);
  delay(3000);
}

void frontLeftMotorStep(int dir, int pwmSpeed) {
  if(dir == 1) {
    analogWrite(frontLeftFwdPin, pwmSpeed);
    delay(10);
    analogWrite(frontLeftFwdPin, 0);
  } else {
    analogWrite(frontLeftBkPin, pwmSpeed);
    delay(10);
    analogWrite(frontLeftBkPin, 0);
  }
}

void frontRightMotorStep(int dir, int pwmSpeed) {
  if(dir == 1) {
    analogWrite(frontRightFwdPin, pwmSpeed);
    delay(10);
    analogWrite(frontRightFwdPin, 0);
  } else {
    analogWrite(frontRightBkPin, pwmSpeed);
    delay(10);
    analogWrite(frontRightBkPin, 0);
  }
}

void backLeftMotorStep(int dir, int pwmSpeed) {
  if(dir == 1) {
    analogWrite(backLeftFwdPin, pwmSpeed);
    delay(10);
    analogWrite(backLeftFwdPin, 0);
  } else {
    analogWrite(backLeftBkPin, pwmSpeed);
    delay(10);
    analogWrite(backLeftBkPin, 0);
  }
}

void backRightMotorStep(int dir, int pwmSpeed) {
  if(dir == 1) {
    analogWrite(backRightFwdPin, pwmSpeed);
    delay(10);
    analogWrite(backRightFwdPin, 0);
  } else {
    analogWrite(backRightBkPin, pwmSpeed);
    delay(10);
    analogWrite(backRightBkPin, 0);
  }
}


void forward(int steps) {
  long i;
  
  for(i=0; i<steps; ++i) {
    frontLeftMotorStep(-1, 255); //Forward
    backLeftMotorStep(-1, 255); //Forward
    
    frontRightMotorStep(1, 255); //Forward
    backRightMotorStep(1, 255); //Forward
  }
}

void turnLeft(int steps) {
  long i;
  
  for(i=0; i<steps; ++i) {
    frontLeftMotorStep(1, 255); //Backward
    backLeftMotorStep(1, 255); //Backward
    
    frontRightMotorStep(1, 255); //Forward
    backRightMotorStep(1, 255); //Forward
  }
}

void turnRight(int steps) {
  long i;
  
  for(i=0; i<steps; ++i) {
    frontLeftMotorStep(-1, 255); //Forward
    backLeftMotorStep(-1, 255); //Forward
    
    frontRightMotorStep(-1, 255); //Backward
    backRightMotorStep(-1, 255); //Backward
  }
}

void driftLeft(int steps) {
  long i;
  
  for(i=0; i<steps; ++i) {
    frontLeftMotorStep(1, 255); //Backward
    backLeftMotorStep(-1, 255); //Forward
    
    frontRightMotorStep(1, 255); //Forward
    backRightMotorStep(-1, 255); //Backward
  } 
}

void driftRight(int steps) {
  long i;
  
  for(i=0; i<steps; ++i) {
    frontLeftMotorStep(-1, 255); //Forward
    backLeftMotorStep(1, 255); //Backward
    
    frontRightMotorStep(-1, 255); //Backward
    backRightMotorStep(1, 255); //Forward
  } 
}
