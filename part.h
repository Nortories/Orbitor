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

    void setRadians(float radians) {
		this->angle.setRadians(radians);
	};

    void throwPart(float throwPartAngle) {
		this->velocity.add(Velocity(random(5000, 9000), Angle(throwPartAngle)));
		// move the PART 5 times to make sure it doesn't get stuck
		for (int i = 0; i < 5; i++) {
			move();
		}
	};
};

