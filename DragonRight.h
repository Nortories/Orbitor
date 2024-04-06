#pragma once
#include "part.h"
#include "fragment.h"

class DragonRight : public Part
{
public:
	DragonRight(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
	{
		this->radius = DRAGON_RIGHT_RADIUS;
	};

	void draw(ogstream* gout);

   list<Part*> getPartPieces();
};
