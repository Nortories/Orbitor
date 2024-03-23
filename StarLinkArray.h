#pragma once
#include "part.h"
#include "fragment.h"

class StarLinkArray : public Part
{
public:
	StarLinkArray(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
	{
		this->radius = STARLINK_ARRAYT_RADIUS;
	};

	void draw(ogstream* gout) {
		gout->drawStarlinkArray(position, this->angle.getRadians());
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