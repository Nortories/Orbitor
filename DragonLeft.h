#pragma once
#include "part.h"
#include "fragment.h"

class DragonLeft : public Part
{
public:
	DragonLeft(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
	{
		this->radius = DRAGON_LEFT_RADIUS;
	};

	void draw(ogstream* gout);

   list<Part*> getPartPieces();
};
