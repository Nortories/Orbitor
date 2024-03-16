#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
class TestShip;
class Test;

class Angle
{
public:
	friend class TestShip;
	friend class TestAngle;

	Angle() : radians(0.00) {};
	Angle(double radians) { this->radians = radians; };

	void setRadians(double radians);
	void setDegrees(double degrees);
	void setDxDy(double dx, double dy);
	void setUp() { this->radians = (M_PI / 2); };
	void setDown() { this->radians = ((3 * M_PI) / 2); };
	void setLeft() { this->radians = M_PI; };
	void setRight() { this->radians = 0; };
	void rotate(double radians);
	double getDegrees() const;
	double getRadians() const;
	double getDx() const { return 0.00; };
	double getDy() const { return 0.00; };
private:
	double radiansToDegrees() const;
	void normalizeRadians();

	double radians;
};

