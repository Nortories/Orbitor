#include "angle.h"
#include <iostream>
using namespace std;

void Angle::normalizeRadians()
{
	if (this->radians > 2 * M_PI)
	{
		this->radians -= 2 * M_PI;
	}
	else if (this->radians < 0)
	{
		this->radians += 2 * M_PI;
	}
}

void Angle::setRadians(double radians)
{ 
	this->radians = radians;
	normalizeRadians();
}

void Angle::setDegrees(double degrees)
{
	this->radians = degrees * (M_PI / 180);
	normalizeRadians();
}

void Angle::setDxDy(double dx, double dy)
{
	this->radians = atan2(dy, dx);
	normalizeRadians();
}

double Angle::getDegrees() const
{
	return(radiansToDegrees());
}

double Angle::getRadians() const
{
	return(this->radians);
}

double Angle::radiansToDegrees() const
{
	return(this->radians * (180 / M_PI));
}
void Angle::rotate(double radians)
{
	this->radians += radians;
	normalizeRadians();
}

