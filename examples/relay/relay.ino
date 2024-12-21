#include <A15_motors.h>

A15_relay relay1(13);
A15_relay relay2(0);
A15_relay relay3(1);

void setup(){
}

void loop(){
  relay1.work(200);
  relay2.work(500);
  relay3.work(1000);
}
