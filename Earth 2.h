#pragma once
#include "Object.h"

class Earth : public Object
{
public:
	Earth() {
		this->position = Position(0, 0);
		radius = RADIUS_OF_EARTH;
	};
	void draw(ogstream* gout){
		gout->drawEarth(position, angleEarth);
		angleEarth += EARTH_SPIN_SPEED;
	};

private:
double angleEarth = 0;
};