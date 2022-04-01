#ifndef LEG_H
#define LEG_H

#include "Arduino.h"
#include "Servo_custom.h"
#include "vector_custom.h"

class Leg {

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
	const double coxa_len = 10;
	const double femur_len = 20;
	const double tibia_len = 30;

	// TO DO make a IK funtion that returns the equivalent to a vector array (probably a pointer to an array)

public:

	// Constructor
	Leg();

	// Parametric Constructors
	Leg(Vector origin_to_coxa, int coxa_pin, int femur_pin, int tibia_pin, double coxa_rotation);

	// Accessors
	Vector find_end_point() const;

	// Mutators
	bool move(Vector vec);



 private:
	 // Updates the vectors from member to member (tail to tip)
	 void update_coxa_to_femur();

	 void update_femur_to_tibia();

	 void update_tibia_to_foot();

	 // Converts input point from hexapod to leg space and vice versa
	 Vector hexapod_to_leg(const Vector& point) const;
	 Vector leg_to_hexapod(const Vector& point) const;

	 //return normal vector of the plane of the leg
	 Vector get_norm_from_plane() const;

	 // Return angle between vector and plane using plane's normal vector
	 double get_angle_plane_vector(const Vector& norm, const Vector& vect) const;

	 // return angles for each motor to move to new point
	 void point_to_angles(const Vector& point, double (&angles)[3]) const;
};


#endif
