#pragma once
#include "part.h"
#include "fragment.h"

class DragonCenter : public Part
{
public:
	DragonCenter(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
	{
		this->radius = DRAGON_CENTER_RADIUS;
	};

	void draw(ogstream* gout) {
		gout->drawCrewDragonCenter(position, this->angle.getRadians());
	};

	list<Part*> getPartPieces()
	{
		list<Part*> pieces;

		Fragment* fragment1 = new Fragment(position, velocity, Angle(0));
		Fragment* fragment2 = new Fragment(position, velocity, Angle(0));
		Fragment* fragment3 = new Fragment(position, velocity, Angle(0));
		Fragment* fragment4 = new Fragment(position, velocity, Angle(0));

		pieces.push_back(fragment1);
		pieces.push_back(fragment2);
		pieces.push_back(fragment3);
		pieces.push_back(fragment4);

		return pieces;
	}
};