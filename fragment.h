#pragma once
#include "part.h"

class Fragment : public Part {
public:
	Fragment(const Position& pos, const Velocity& vel, const Angle& ang) : Part(pos, vel, ang)
	{
		fragTime = random(FRAGMENT_TIME_MIN, FRAGMENT_TIME_MAX);
	}
   void draw(ogstream* gout);
   
private:
	int fragTime;
};
