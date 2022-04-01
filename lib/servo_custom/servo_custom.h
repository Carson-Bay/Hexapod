#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>
#include <Servo.h>

class Servo_c {

private:

	Servo servo;
	int min_range;
	int max_range;

public:
	// Constructors
	Servo_c();

	// Parametric constructor
	Servo_c(int min_range, int max_range);

	// Accessors
	double read() const;

	// Mutators
	bool write(double angle);

	void attach(int pin);
};


#endif
