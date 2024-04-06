#pragma once
#include "part.h"
#include "fragment.h"


class HubbleComputer : public Part
{
public:
	HubbleComputer(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
	{
		this->radius = HUBBLE_COMPUTER_RADIUS;
	};

   void draw(ogstream* gout);

   list<Part*> getPartPieces();
};
