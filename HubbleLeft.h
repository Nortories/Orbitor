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

	void draw(ogstream* gout) {
		gout->drawHubbleLeft(position, this->angle.getRadians());
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