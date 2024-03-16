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
	
	Velocity(float vel, const Angle& ang) {
		this->dx = -vel * cos(ang.getRadians());
		this->dy = vel * sin(ang.getRadians());
	};
	Velocity(float dx, float dy) {
		this->dx = dx;
		this->dy = dy;
	};

	float getDx() const { return dx; };
	float getDy() const { return dy; };

	void setDx(float dx) { this->dx = dx; };
	void setDy(float dy) { this->dy = dy; };

	void addDx(float dx) { this->dx += dx; };
	void addDy(float dy) { this->dy += dy; };

	void add(Velocity velocity) {
		this->dx = this->dx + velocity.dx;
		this->dy = this->dy + velocity.dy;
	};

private:
	float dx;
	float dy;
};

