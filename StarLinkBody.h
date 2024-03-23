#pragma once
#include "part.h"
#include "fragment.h"

class StarLinkBody : public Part
{
public:
	StarLinkBody(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
	{
		this->radius = STARLINK_BODY_RADIUS;
	};

	void draw(ogstream* gout) {
		gout->drawStarlinkBody(position, this->angle.getRadians());
	};

	list<Part*> getPartPieces()
	{
		list<Part*> pieces;

		Fragment* fragment1 = new Fragment(position, velocity, Angle(0));
		Fragment* fragment2 = new Fragment(position, velocity, Angle(0));
		Fragment* fragment3 = new Fragment(position, velocity, Angle(0));

		pieces.push_back(fragment1);
		pieces.push_back(fragment2);
		pieces.push_back(fragment3);

		return pieces;
	}
};