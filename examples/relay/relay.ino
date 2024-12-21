#include <A15Motors.h>

A15Relay relay1(13);
A15Relay relay2(0);
A15Relay relay3(1);

void setup(){
}

void loop(){
  relay1.work(200);
  relay2.work(500);
  relay3.work(1000);
}
