#include "vector_custom.h"
#include <Arduino.h>

Vector::Vector(){
  this->storage_[0] = 0;
  this->storage_[1] = 0;
  this->storage_[2] = 0;
}

Vector::Vector(double element_1, double element_2, double element_3){
    this->storage_[0] = element_1;
    this->storage_[1] = element_2;
    this->storage_[2] = element_3;
}


Vector::Vector(const Vector& other) {
    this->storage_[0] = other.get_x();
    this->storage_[1] = other.get_y();
    this->storage_[2] = other.get_z();
}

// Accessors
// Print contents of Vector to serial
void Vector::print() const {
    Serial.print("X: ");
    Serial.print(this->get_x());
    Serial.print(" Y: ");
    Serial.print(this->get_y());
    Serial.print(" Z: ");
    Serial.println(this->get_z());
}

// return element at index
double Vector::peek(int INDEX) const {
    if(INDEX < 0 || INDEX > 2){
        Serial.println("ERROR: Index out of range");
        return 0;
    }
    else{
        return this->storage_[INDEX];
    }
}

// Return x component (index 0)
double Vector::get_x() const {
    return this->storage_[0];
}

// Return y component (index 1)
double Vector::get_y() const {
    return this->storage_[1];
}

// Return z component (index 2)
double Vector::get_z() const {
    return this->storage_[2];
}

// Total magnitude
double Vector::magnitude() const {
    return sqrt(pow(this->get_x(), 2) + pow(this->get_y(), 2) + pow(this->get_z(), 2));
}

// Magnitude in 2d over two specified directions
double Vector::magnitude(int INDEX_1, int INDEX_2) const {
    return sqrt(pow(this->storage_[INDEX_1], 2) + pow(this->storage_[INDEX_2], 2));
}

// Returns normalized version of vector
Vector Vector::normalize() const {
    double mag = this->magnitude();
    if(mag <= 0.0001){
        Serial.println("ERROR: Normalized Zero Vector");
        Vector temp;
        return temp;
    }
    Vector temp = *this / mag;
    return temp;
}

Vector Vector::rotate(double angle) const{
    double x = this->get_x();
    double y = this->get_y();
    double z = this->get_z();
    double new_x = cos(angle)*x - sin(angle)*y;
	double new_y = sin(angle)*x + cos(angle)*y;
    return Vector(new_x, new_y, z);
}

// Mutators
// Set element at index
void Vector::set(int INDEX, double val) {
    if(INDEX < 0 || INDEX > 2){
        Serial.println("ERROR: Index out of range");
    }
    this->storage_[INDEX] = val;
}

// Set x component (index 0)
void Vector::set_x(double val) {
    this->storage_[0] = val;
}

// Set y component (index 1)
void Vector::set_y(double val) {
    this->storage_[1] = val;
}

// Set z component (index 2)
void Vector::set_z(double val) {
    this->storage_[2] = val;
}

// Operators
// Equality check
bool Vector::operator==(const Vector& other) const{
    return this->storage_[0] == other.get_x() &&
    this->storage_[1] == other.get_y() &&
    this->storage_[2] == other.get_z();
}

// Addition
Vector Vector::operator+(const Vector& other) const {
    double x = this->get_x() + other.get_x();
    double y = this->get_y() + other.get_y();
    double z = this->get_z() + other.get_z();
    Vector temp(x, y, z);
    return temp;
}

void Vector::operator+=(const Vector& other) {
    this->storage_[0] = this->get_x() + other.get_x();
    this->storage_[1] = this->get_y() + other.get_y();
    this->storage_[2] = this->get_z() + other.get_z();
}

// Subtraction
Vector Vector::operator-(const Vector& other) const {
    double x = this->get_x() - other.get_x();
    double y = this->get_y() - other.get_y();
    double z = this->get_z() - other.get_z();
    Vector temp(x, y, z);
    return temp;
}

void Vector::operator-=(const Vector& other) {
    this->storage_[0] = this->get_x() - other.get_x();
    this->storage_[1] = this->get_y() - other.get_y();
    this->storage_[2] = this->get_z() - other.get_z();
}

// Scalar multiplication
Vector Vector::operator*(const int scalar) const {
    double x = this->get_x() * scalar;
    double y = this->get_y() * scalar;
    double z = this->get_z() * scalar;
    Vector temp(x, y, z);
    return temp;
}

Vector Vector::operator*(const double scalar) const {
    double x = this->get_x() * scalar;
    double y = this->get_y() * scalar;
    double z = this->get_z() * scalar;
    Vector temp(x, y, z);
    return temp;
}

void Vector::operator*=(const int scalar) {
    this->storage_[0] = this->get_x() * scalar;
    this->storage_[1] = this->get_y() * scalar;
    this->storage_[2] = this->get_z() * scalar;
}

void Vector::operator*=(const double scalar) {
    this->storage_[0] = this->get_x() * scalar;
    this->storage_[1] = this->get_y() * scalar;
    this->storage_[2] = this->get_z() * scalar;
}

// Dot product
double Vector::operator*(const Vector& other) const {
    return (this->get_x() * other.get_x()) +
           (this->get_y() * other.get_y()) +
           (this->get_z() * other.get_z());
}

// Scalar Division
Vector Vector::operator/(const int scalar) const {
    if(scalar == 0){
        Serial.println("ERROR: Divide by zero");
        Vector temp;
        return temp;
    }
    double x = this->get_x() / scalar;
    double y = this->get_y() / scalar;
    double z = this->get_z() / scalar;
    Vector temp(x, y, z);
    return temp;
}

Vector Vector::operator/(const double scalar) const {
    if(abs(scalar) <= 0.0001){
        Serial.println("ERROR: Divide by zero");
        Vector temp;
        return temp;
    }
    double x = this->get_x() / scalar;
    double y = this->get_y() / scalar;
    double z = this->get_z() / scalar;
    Vector temp(x, y, z);
    return temp;
}

void Vector::operator/=(const int scalar) {
    if(scalar == 0){
        Serial.println("ERROR: Divide by zero");
    }
    this->storage_[0] = this->get_x() / scalar;
    this->storage_[1] = this->get_y() / scalar;
    this->storage_[2] = this->get_z() / scalar;
}
void Vector::operator/=(const double scalar) {
    if(abs(scalar) <= 0.0001){
        Serial.println("ERROR: Divide by zero");
    }
    this->storage_[0] = this->get_x() / scalar;
    this->storage_[1] = this->get_y() / scalar;
    this->storage_[2] = this->get_z() / scalar;
}

// Cross Product
Vector Vector::operator%(const Vector& other) const {
    double x = (this->get_y() * other.get_z()) - (this->get_z() * other.get_y());
    double y = (this->get_z() * other.get_x()) - (this->get_x() * other.get_z());
    double z = (this->get_x() * other.get_y()) - (this->get_y() * other.get_x());
    Vector temp(x, y, z);
    return temp;
}

// Scalar Power
// DONT DIVIDE BY TWO INTS AND EXPECT A DOUBLE YOU APE
Vector Vector::operator^(const int exponent) const {
    double x = pow(this->get_x(), exponent);
    double y = pow(this->get_y(), exponent);
    double z = pow(this->get_z(), exponent);
    Vector temp(x, y, z);
    return temp;
}

Vector Vector::operator^(const double exponent) const {
    double x = pow(this->get_x(), exponent);
    double y = pow(this->get_y(), exponent);
    double z = pow(this->get_z(), exponent);
    Vector temp(x, y, z);
    return temp;
}

void Vector::operator^=(const int exponent) {
    this->storage_[0] = pow(this->get_x(), exponent);
    this->storage_[1] = pow(this->get_y(), exponent);
    this->storage_[2] = pow(this->get_z(), exponent);
}

void Vector::operator^=(const double exponent) {
    this->storage_[0] = pow(this->get_x(), exponent);
    this->storage_[1] = pow(this->get_y(), exponent);
    this->storage_[2] = pow(this->get_z(), exponent);
}
