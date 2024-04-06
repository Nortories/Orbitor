#pragma once
#include "part.h"
#include "fragment.h"

class StarLinkBody : public Part
{
public:
	StarLinkBody(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
	{
		this->radius = STARLINK_BODY_RADIUS;
	};

	void draw(ogstream* gout);

   list<Part*> getPartPieces();
};
