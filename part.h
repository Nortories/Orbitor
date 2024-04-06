#pragma once
#include "object.h"

// Object base class is undefined because
class Part : public Object
{
public:
    Part() {};
    Part(const Position& pos, const Velocity& velocity, const Angle& angle) {
		this->velocity = velocity;
		this->angle = angle;
		this->position = pos;
		this->angularVelocity = random(-.25, .25);
	};

    void setRadians(float radians);

    void tossPart(float throwPartAngle);
};

