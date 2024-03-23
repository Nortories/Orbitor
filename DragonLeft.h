#pragma once
#include "part.h"
#include "fragment.h"

class DragonLeft : public Part
{
public:
	DragonLeft(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
	{
		this->radius = DRAGON_LEFT_RADIUS;
	};

	void draw(ogstream* gout) {
		gout->drawCrewDragonLeft(position, this->angle.getRadians());
	};

	list<Part*> getPartPieces()
	{
		list<Part*> pieces;

		Fragment* fragment1 = new Fragment(position, velocity, Angle(0));
		Fragment* fragment2 = new Fragment(position, velocity, Angle(0));

		pieces.push_back(fragment1);
		pieces.push_back(fragment2);

		return pieces;
	}
};