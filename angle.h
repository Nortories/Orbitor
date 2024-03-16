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
	Angle(float radians) { this->radians = radians; };

	void setRadians(float radians);
	void setDegrees(float degrees);
	void setDxDy(float dx, float dy);
	void setUp() { this->radians = (M_PI / 2); };
	void setDown() { this->radians = ((3 * M_PI) / 2); };
	void setLeft() { this->radians = M_PI; };
	void setRight() { this->radians = 0; };
	void rotate(float radians);
	float getDegrees() const;
	float getRadians() const;
	float getDx() const { return 0.00; };
	float getDy() const { return 0.00; };
private:
	float radiansToDegrees() const;
	void normalizeRadians();

	float radians;
};

