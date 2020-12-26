#include <StepperMotor.h>
#define Y_STEP_SIZE 16

StepperMotor y_motor(D5,D6,D7,D8);
StepperMotor winding_motor(D1,D2,D3,D4);
int countConnectedDevices = 0;

int schritte = 1024;
int step_duration = 1000;
int max_y = 272;
int y = 0;
int direction_value = -1;


void setup(){
  // Initialize motors
  y_motor.setStepDuration(step_duration);
  winding_motor.setStepDuration(step_duration);
}

void loop(){
  // Move the winding motor
  winding_motor.step(schritte);

  // Move the y-axis motor
  if(y < max_y){
    y += Y_STEP_SIZE;
  } else {
    direction_value = direction_value * -1;
    y = Y_STEP_SIZE;
  }
  y_motor.step(direction_value * Y_STEP_SIZE);
}
