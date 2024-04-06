#pragma once
#include "part.h"
#include "fragment.h"

class StarLinkArray : public Part
{
public:
	StarLinkArray(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
	{
		this->radius = STARLINK_ARRAYT_RADIUS;
	};

	void draw(ogstream* gout);

   list<Part*> getPartPieces();
};
