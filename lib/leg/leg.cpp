#include "leg.h"
#include "Arduino.h"
#include "Servo_custom.h"
#include "vector_custom.h"

const double PI = 3.1459

// Constructors
// Default constructor (p much just here to stop errors)
// Any of the value are subject to change if need be
Leg::Leg() {
	this->origin_to_coxa = Vector(0, 0, 0);
	this->coxa_rotation = 0;

	//Initialize Servos
	this->coxa_motor = Servo_c();
	this->femur_motor = Servo_c();
	this->tibia_motor = Servo_c();

	this->coxa_motor.attach(9);
	this->femur_motor.attach(10);
	this->tibia_motor.attach(11);

	// Updates internal vectors from member to member
	this->update_coxa_to_femur();
	this->update_femur_to_tibia();
	this->update_tibia_to_foot();
};

// Parametric Constructors
Leg::Leg(Vector origin_to_coxa, int coxa_pin,
		int femur_pin, int tibia_pin, double coxa_rotation) {

		// Vector from Origin (center of bot) to coxa
		// Helps convert from hexapod space to leg space
		// Hexapod space has all the points relative to the center of the bot
		// And where the bot is facing
		// Leg space has the origin at the center of the coxa and rotates the leg
		// to have its home position at 0 deg (positive x)
		this->origin_to_coxa = origin_to_coxa;
		//Coxa rotation determines how many degrees the home position is rotated
		//in relation to the hexapod
		this->coxa_rotation = coxa_rotation;

		//Initialize Servos
		this->coxa_motor = Servo_c();
		this->femur_motor = Servo_c();
		this->tibia_motor = Servo_c();

		this->coxa_motor.attach(coxa_pin);
		this->femur_motor.attach(femur_pin);
		this->tibia_motor.attach(tibia_pin);

		// Updates internal vectors from member to member
		this->update_coxa_to_femur();
		this->update_femur_to_tibia();
		this->update_tibia_to_foot();

};

// Accessors
// Returns position of foot in hexapod space
// TODO THIS CURRENTLY DOES NOT TAKE INTO ACCOUNT THE BASE ROTATION OF COXA: this->coxa_rotation
Vector Leg::find_end_point() const {

	Vector end_point = this->coxa_to_femur + this->femur_to_tibia + this->tibia_to_foot;
	// convert_to_hexapod_space(endpoint);
	return end_point;
}

// Mutators
 bool Leg::move(Vector vec) {
	 return true;
 }


// Updates the vectors from member to member (tail to tip)
// These vectors will be in Leg Space
// These functions currently dont take into account the geometry of the members themselves
 void Leg::update_coxa_to_femur() { // TO DO
	 double x = cos(this->coxa_motor.read()) * this->coxa_len;
	 double y = sin(this->coxa_motor.read()) * this->coxa_len;
	 double z = 0;

 }

 void Leg::update_femur_to_tibia() { // TO DO

 }

 void Leg::update_tibia_to_foot() { // TO DO

 }

// TODO need to rotate point around origin after translation by
// negatative this->coxa_rotation degrees
// Converts input point from hexapod to leg space
// Will have to write a backwards conversion for leg to hexapod space
Vector Leg::hexapod_to_leg(const Vector& point) const {
	Vector new_point = point - this->origin_to_coxa;
	// Z component of vector stays constant as we are rotating around the z-axis
	double x = new_point.get_x();
	double y = new_point.get_y();
	new_point.set_x(cos(-this->coxa_rotation)*x - sin(-this->coxa_rotation)*y);
	new_point.set_y(sin(-this->coxa_rotation)*x + cos(-this->coxa_rotation)*y);
	return new_point;
}

Vector Leg::leg_to_hexapod(const Vector& point) const {
	Vector new_point = point - this->origin_to_coxa;
	// Z component of vector stays constant as we are rotating around the z-axis
	double x = new_point.get_x();
	double y = new_point.get_y();
	new_point.set_x(cos(this->coxa_rotation)*x - sin(this->coxa_rotation)*y);
	new_point.set_y(sin(this->coxa_rotation)*x + cos(this->coxa_rotation)*y);

	new_point += this->origin_to_coxa;

	return new_point;
}

 //return normal vector of the plane of the leg
 Vector Leg::get_norm_from_plane() const {
	 // May need checks if the norm vector is the right way around
	 // (As cross product is not commutative)
	 // Norm is in CCW direction around the bot
	 Vector femur_to_coxa = this->coxa_to_femur * -1;
	 Vector norm = this->femur_to_tibia % femur_to_coxa;
	 // May not need normalize component
	 return norm.normalize();

 }



 // Return angle between vector and plane using plane's normal vector
 double Leg::get_angle_plane_vector(const Vector& norm, const Vector& vect) const {
	 // I am using acos however if it is faster we can do
	 // asin and cross product instead
	 // 180/pi switches to degrees
	 double angle = (180 / PI) * acos((norm * vect)
	                 /(norm.magnitude() * vect.magnitude()));

	 // Find complement of angle because
	 // angle between vector and norm is complement to vector and plane
	 return 90 - angle;
 }


 double * point_to_angles(const Vector& point) const {
	 // Do IK math to return angles

	 // Find coxa angle
	 Vector norm = get_norm_from_plane();
	 double coxa_angle = get_angle_plane_vector(norm, point);

	 // Find tibia angle
	 Vector new_femur_to_foot = // TO DO SHAWN
	 double tibia_angle = acos((femur_len^2 + tibia_len^2 - new_femur_to_foot.magnitude()^2) / (2 * femur_len * tibia_len));

	 // Find femur angle
	 double femur_angle = asin(new_femur_to_foot.magnitude() * sin(femur_angle) / sin(tibia_angle));


 }
