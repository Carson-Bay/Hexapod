#include "Arduino.h"
#include <Servo.h>


// Constructors
Servo_c::Servo_c(){
	this->servo = Servo());
	this->min_range = 0;
	this->max_range = 300;
};

// Parametric constructor
Servo_c::Servo_c(Servo servo, int min_range, int max_range){
	this->servo = servo;
	this->min_range = min_range;
	this->max_range = max_range;
};

// Accessors
double Servo_c::read() const {
	double angle = this->servo.read();
	double converted_angle = 300 * angle / 180;
	return converted_angle;
};

// Mutators
bool Servo_c::write(double angle){
	if(angle >= this->min_range && angle <= this->max_range){
		int microseconds = round(((2000/300) * angle) + 500);
		this->servo.writeMicroseconds(microseconds);
		return true;
	}
	else{return false;}
};

void Servo_c::attach(uint pin){
	this->servo.attach(pin);
};
