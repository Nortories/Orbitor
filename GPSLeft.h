#pragma once
#include "part.h"
#include "fragment.h"


class GPSLeft : public Part
{
public:
	GPSLeft(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
	{
		this->radius = GPS_LEFT_RADIUS;
	};

   void draw(ogstream* gout);

   list<Part*> getPartPieces();
};
