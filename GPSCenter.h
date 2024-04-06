#pragma once
#include "part.h"
#include "fragment.h"


class GPSCenter : public Part
{
	public:
	GPSCenter(const Position & pos, const Velocity & velocity, const Angle & angle) : Part(pos, velocity, angle)
	{
	this->radius = GPS_CENTER_RADIUS;
	};

	void draw(ogstream* gout);

   list<Part*> getPartPieces();
};
