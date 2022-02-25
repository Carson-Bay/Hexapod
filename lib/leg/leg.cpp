#include "leg.h"
#include "Arduino.h"


// Constructor
Leg::Leg(){

};

// Parametric Constructors
Leg::Leg(Vector origin_to_coxa, int coxa_pin, int femur_pin, int tibia_pin,
	double coxa_len, double femur_len, double tibia_len){
		this->origin_to_coxa = origin_to_coxa;
		this->coxa_len = coxa_len;
		this->femur_len = femur_len;
		this->tibia_len = tibia_len;

		this->coxa_motor = Servo_c();
		this->femur_motor = Servo_c();
		this->tibia_motor = Servo_c();

		this->coxa_motor.attach(coxa_pin);
		this->femur_motor.attach(femur_pin);
		this->tibia_motor.attach(tibia_pin);
};

// Accessors
Vector Leg::find_end_point() const;
