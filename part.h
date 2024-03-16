#pragma once
#include "object.h"
class Part :
    public Object
{
public:
    Part() {};
    Part(const Position& pos, const Velocity& velocity, const Angle& angle) {
		this->velocity = velocity;
		this->angle = angle;
		this->position = pos;
		this->angularVelocity = random(-.25, .25);
	};

    void setRadians(float radians) {
		this->angle.setRadians(radians);
	};

    void kick(float kickAngle) {
		this->velocity.add(Velocity(random(5000, 9000), Angle(kickAngle)));
		move();
		move();
		move();
		move();
		move();
	};
};

