#include <A15_motors.h>

A15_motors motors(6, 9, 10, 11);

void setup(){
  motors.setSpeed(180);
  motors.setSmooth(5);
}

void loop(){
  for(int i = 0; i < 4; i++){
    motors.smoothGo(FW);
    motors.smoothBrake(FW);
    motors.smoothGo(L);
    motors.smoothBrake(L);
  }
}
