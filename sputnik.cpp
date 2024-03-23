#include "sputnik.h"
#include "object.h"

Sputnik::Sputnik() : Object()
{
	this->position = Position(SPUTNIK_POSITION_X, SPUTNIK_POSITION_Y);
	this->velocity = Velocity(SPUTNIK_VECTOR_X, SPUTNIK_VECTOR_Y);
	radius = SPUTNIK_RADIUS;
}

void Sputnik::draw(ogstream* gout)
{
	gout->drawSputnik(position, getDirection().getRadians());
}

list<Part*> Sputnik::getPartPieces()
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