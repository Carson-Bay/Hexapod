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
Vector Leg::find_end_point() const {

	Vector end_point = this->origin_to_coxa + this->coxa_to_femur
									+ this->femur_to_tibia + this->tibia_to_foot;
	return end_point;
}

// Mutators
 bool Leg::move(Vector vec){

 }

private:

 Vector Leg::update_coxa_to_femur(){
	 double x = cos(this->coxa_motor.read()) * this->coxa_len;
	 double y = sin(this->coxa_motor.read()) * this->coxa_len;
	 double z = 0;

 }

 Vector Leg::update_femur_to_tibia(){

 }

 Vector Leg::update_tibia_to_foot(){

 }
 //return normal vector of the plane of the leg
 Vector Leg::get_norm_from_plane() const{
	 // May need checks if the norm vector is the right way around
	 // (As cross prooduct is not commutative)
	 Vector femur_to_coxa = -1 * this->coxa_to_femur;
	 Vector norm = this->femur_to_coxa % this->femur_to_tibia;
	 // May not need normalize component
	 return norm.normalize();

 }
 // Return angle between vector and plane using plane's normal vector
 double Leg::get_angle_plane_vector(Vector norm, Vector vect) const{
	 // I am using acos however if it is faster we can do
	 // asin and cross product instead
	 // 180/pi switches to degrees
	 double angle = (180 / pi) * acos((norm * vect)
	                 /(norm.magnitude() * vect.magnitude()));

	 // Find complement of angle because
	 // angle between vector and norm is complement to vector and plane
	 return 90 - angle;
 }
