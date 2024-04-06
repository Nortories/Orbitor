#pragma once
#include "part.h"
#include "fragment.h"


class GPSRight : public Part
{
public:
	GPSRight(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
	{
		this->radius = GPS_RIGHT_RADIUS;
	};

   void draw(ogstream* gout);

   list<Part*> getPartPieces();
};
