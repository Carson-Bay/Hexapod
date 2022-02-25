#ifndef LEG_H
#define LEG_H

#include "Arduino.h"
#include "Servo_c.h"
#include "vector_custom.h"

class Leg(){

private:

	Vector origin_to_coxa;
	Vector coxa_to_femur;
	Vector femur_to_tibia;
	Vector tibia_to_foot;

	Servo_c coxa_motor;
	Servo_c femur_motor;
	Servo_c tibia_motor;

	double coxa_len;
	double femur_len;
	double tibia_len;



public:


};


#endif
