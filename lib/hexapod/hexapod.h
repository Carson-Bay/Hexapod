#ifndef HEXAPOD_H
#define HEXAPOD_H

#include "Arduino.h"
#include "Servo_c.h"
#include "vector_custom.h"
#include "leg.h"

class Hexapod {

private:

  Leg legs [6];

  // array of points of points move the legs to a rest position
  const Vector rest_point [6];

  // array of points of points move the legs to a crouch position
  const Vector crouch_point [6];

public:

  // Constructor
  Hexapod();
  // TO DO Parametric Constructor
  Hexapod();
  // Copy constructor
  Hexapod(const Hexapod& other);

  // Accessors

  // Mutators

  bool move_forward();

  bool move_backward();

  bool move_right();

  bool move_left();

};

#endif
