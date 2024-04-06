#pragma once
#include "part.h"
#include "fragment.h"


class HubbleTelescope : public Part
{
public:
	HubbleTelescope(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
	{
		this->radius = HUBBLE_TELESCOPE_RADIUS;
	};

	void draw(ogstream* gout);

   list<Part*> getPartPieces();
};
