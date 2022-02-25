#ifndef VECTOR_H
#define VECTOR_H

#include "Arduino.h"

const int VECTOR_MAX_SIZE = 3;


class Vector {

  private:
    // Storage array for vector info
    double storage_ [VECTOR_MAX_SIZE];

  public:
    // Constructors and Destructors
    // Empty default constructor
    Vector();
    // Parametric constructor of vector
    Vector(double element_1, double element_2, double element_3);
    // Copy constructor
    Vector(const Vector& other);

    // Accessors
    // Print contents of Vector to serial
    void print() const;

    // return element at index
    double peek(int INDEX) const;

    // Return x component (index 0)
    double get_x() const;

    // Return y component (index 1)
    double get_y() const;

    // Return z component (index 2)
    double get_z() const;

    // Total magnitude
    double magnitude() const;

    // Magnitude in 2d over two specified directions
    double magnitude(int INDEX_1, int INDEX_2) const;

    // Returns normalized version of vector
    Vector normalize() const;

    // Mutators
    // Set element at index
    void set(int INDEX, double val);

    // Set x component (index 0)
    void set_x(double val);

    // Set y component (index 1)
    void set_y(double val);

    // Set z component (index 2)
    void set_z(double val);

    // CAN ADD SINGLE ADDITION ETC FUNCTIONS TO ONE ELEMENT LATER MAYBE who knows

    // Operators
    // Equality check
    bool operator==(const Vector& other) const;

    // Addition
    Vector operator+(const Vector& other) const;
    void operator+=(const Vector& other);

    // Subtraction
    Vector operator-(const Vector& other) const;
    void operator-=(const Vector& other);

    // Scalar multiplication
    Vector operator*(const int scalar) const;
    Vector operator*(const double scalar) const;
    void operator*=(const int scalar);
    void operator*=(const double scalar);

    // Dot product
    double operator*(const Vector& other) const;

    // Scalar Division
    Vector operator/(const int scalar) const;
    Vector operator/(const double scalar) const;
    void operator/=(const int scalar);
    void operator/=(const double scalar);

    // Cross Product
    Vector operator%(const Vector& other) const;

    // Scalar Power
    Vector operator^(const int exponent) const;
    Vector operator^(const double exponent) const;
    void operator^=(const int exponent);
    void operator^=(const double exponent);
};

#endif
