#pragma once
#include "Object.h"


class Bullet : public Object
{
public:
	Bullet(const Velocity& vel, const Position& pos, const Angle& ang)
	{
		this->position = pos;
		this->velocity = vel;
		this->angle = ang;
		range = BULLET_RANGE;
		radius = 1;
	};
	void draw(ogstream* gout) {
		gout->drawProjectile(position);

		range--;
		if (range <= 0)
		{
			triggerDestruction();
		}
	};

private:
	int range;
};