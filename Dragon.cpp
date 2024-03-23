#include "Dragon.h"
#include "object.h"
#include "DragonCenter.h"
#include "DragonLeft.h"
#include "DragonRight.h"


Dragon::Dragon() : Object()
{
	this->position.setMeters(DRAGON_POSITION_X, DRAGON_POSITION_Y);
	this->velocity.setDx(DRAGON_VECTOR_X);
	this->velocity.setDy(DRAGON_POSITION_Y);
	radius = DRAGON_RADIUS;
}

void Dragon::draw(ogstream* gout)
{
	gout->drawCrewDragon(position, getDirection().getRadians());
}

list<Part*> Dragon::getPartPieces()
{
	list<Part*> pieces;

	DragonCenter* center = new DragonCenter(position, velocity, Angle(0));
	DragonRight* right = new DragonRight(position, velocity, Angle(0));
	DragonLeft* left = new DragonLeft(position, velocity, Angle(0));

	pieces.push_back(center);
	pieces.push_back(right);
	pieces.push_back(left);

	return pieces;
}