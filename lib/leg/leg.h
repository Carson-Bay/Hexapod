#ifndef LEG_H
#define LEG_H

#include "Arduino.h"
#include "Servo_custom.h"
#include "vector_custom.h"

class Leg(){

private:

	// From Center of rotations
	// Add more info later on exact ways these are measured
	Vector origin_to_coxa;
	Vector coxa_to_femur;
	Vector femur_to_tibia;
	Vector tibia_to_foot;

	Servo_c coxa_motor;
	Servo_c femur_motor;
	Servo_c tibia_motor;

	double coxa_rotation;

	// From Center of rotations
	// Add more info later on exact ways these are measured
	const double coxa_len;
	const double femur_len;
	const double tibia_len;

	// TO DO make a IK funtion that returns the equivalent to a vector array (probably a pointer to an array)

public:

	// Constructor
	Leg();

	// Parametric Constructors
	Leg(int coxa_pin, int femur_pin, int tibia_pin);

	// Update Leg parameters (position, orientation and length)
	void update_config(Vector origin_to_coxa, double coxa_len, double femur_len, double tibia_len);

	// Accessors
	Vector find_end_point() const;

	// Mutators
	 bool move(Vector vec);

 private:
	 // Updates the vectors from member to member
	 void update_coxa_to_femur();

	 void update_femur_to_tibia();

	 void update_tibia_to_foot();

	 Vector position_conversion(const Vector& point) const;

	 Vector get_norm_from_plane() const;

	 double get_angle_plane_vector(Vector norm, Vector vect) const;






};


#endif
