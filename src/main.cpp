#include <Arduino.h>
#include <Servo.h>

Servo turretservo;
Servo gripservo;

void setup() {

  turretservo.attach(22);
  //gripservo.attach(46);
}


double theta1(double theta_s, double theta_e, double tf) {

  double a0, a1, a2, a3;
  static unsigned long ts;
  static double endt;
  static double thet;
  double t;


  if (endt != theta_e) {
    ts = millis();
    endt = theta_e;
  }

  a0 = theta_s;
  a1 = 0;
  a2 = 3 / (tf * tf) * (theta_e - theta_s);
  a3 = -2 / (tf * tf * tf) * (theta_e - theta_s);

  t = (double)(millis() - ts) / 1000;

  if (t <= tf){
    thet = a0 + a1 * t + a2 * t * t + a3 * t * t * t;
  }

  return thet;
}

double theta2(double theta_s, double theta_e, double tf) {

  double a0, a1, a2, a3;
  static unsigned long ts;
  static double endt;
  static double thet;
  double t;

  if (endt != theta_e) {
    ts = millis();
    endt = theta_e;
  }

  a0 = theta_s;
  a1 = 0;
  a2 = 3 / (tf * tf) * (theta_e - theta_s);
  a3 = -2 / (tf * tf * tf) * (theta_e - theta_s);
  t = (double)(millis() - ts) / 1000;

  if (t <= tf) {
    thet = a0 + a1 * t + a2 * t * t + a3 * t * t * t;
  }

  return thet;

}

double ang, ang2;
int state = 1;

void loop() {

  if (state == 1)  {

    ang = theta1(0, 90, 2);
    // ang2 = theta2(0, 180, 3);

  }

  if (state == 2)  {
    ang = theta1(90, 0, 5);
    // ang2 = theta2(180, 0, 10);
  }

  if (ang > 89.8) state = 2;
  if (ang < 1) state = 1;

  turretservo.write(ang);

  // gripservo.write(180 - ang2);

}