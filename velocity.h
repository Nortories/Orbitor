#pragma once
#include "angle.h"
#include <iostream>
using namespace std;

class Velocity
{
public:

	Velocity() : dx(0), dy(0)
	{
		setDx(dx);
		setDy(dy);
	}
	
	Velocity(double vel, const Angle& ang) {
		this->dx = -vel * cos(ang.getRadians());
		this->dy = vel * sin(ang.getRadians());
	};
	Velocity(double dx, double dy) {
		this->dx = dx;
		this->dy = dy;
	};

	double getDx() const { return dx; };
	double getDy() const { return dy; };

	void setDx(double dx) { this->dx = dx; };
	void setDy(double dy) { this->dy = dy; };

	void addDx(double dx) { this->dx += dx; };
	void addDy(double dy) { this->dy += dy; };

	void add(Velocity velocity) {
		this->dx = this->dx + velocity.dx;
		this->dy = this->dy + velocity.dy;
	};

private:
	double dx;
	double dy;
};

