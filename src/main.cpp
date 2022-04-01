#include <Arduino.h>
#include "servo_custom.h"
#include "vector_custom.h"
#include "leg.h"

Servo_c coxa;
Servo_c femur;
Servo_c tibia;

void setup() {
  // put your setup code here, to run once:
  Servo_c coxa = Servo_c(-60, 60);
  Servo_c femur = Servo_c(-60, 60);
  Servo_c tibia = Servo_c(-90, 90);

  coxa.attach(9);
  femur.attach(10);
  tibia.attach(11);

  coxa.write(0);
  femur.write(0);
  tibia.write(0);

  while(1){
	  coxa.write(0);
	  femur.write(0);
	  tibia.write(0);
	  delay(1000);


	  coxa.write(50);
	  femur.write(50);
	  tibia.write(50);
	  delay(1000);
  }
}
