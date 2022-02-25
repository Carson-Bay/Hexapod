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

	const double coxa_len;
	const double femur_len;
	const double tibia_len;

	// TO DO make a IK funtion that returns the equivalent to a vector array (probably a pointer to an array)



public:

	// Constructor
	Leg();

	// Parametric Constructors
	Leg(Vector origin_to_coxa, int coxa_pin, int femur_pin, int tibia_pin,
		double coxa_len, double femur_len, double tibia_len);

	// Accessors
	Vector find_end_point() const;

	// Mutators
	 bool move(Vector vec);

 private:

	 Vector update_coxa_to_femur() const;

	 Vector update_femur_to_tibia() const;

	 Vector update_tibia_to_foot() const;






};


#endif
