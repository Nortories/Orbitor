#pragma once
#include "part.h"
#include "fragment.h"


class HubbleRight : public Part
{
public:
	HubbleRight(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
	{
		this->radius = HUBBLE_RIGHT_RADIUS;
	};

	void draw(ogstream* gout);

   list<Part*> getPartPieces();
};
