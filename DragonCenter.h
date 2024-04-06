#pragma once
#include "part.h"
#include "fragment.h"

class DragonCenter : public Part
{
public:
	DragonCenter(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
	{
		this->radius = DRAGON_CENTER_RADIUS;
	};

   void draw(ogstream* gout);

   list<Part*> getPartPieces();
};
