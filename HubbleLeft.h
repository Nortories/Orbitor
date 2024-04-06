#pragma once
#include "part.h"
#include "fragment.h"


class HubbleLeft : public Part
{
public:
	HubbleLeft(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
	{
		this->radius = HUBBLE_LEFT_RADIUS;
	};

   void draw(ogstream* gout);

   list<Part*> getPartPieces();
};
