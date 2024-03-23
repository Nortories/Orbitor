#include "gps.h"
#include "object.h"
#include "GPSCenter.h"
#include "GPSLeft.h"
#include "GPSRight.h"

GPS::GPS(float posX, float posY, float velX, float velY) : Object()
{
	this->position.setMeters(posX, posY);
	this->velocity.setDx(velX);
	this->velocity.setDy(velY);
	radius = GPS_RADIUS;
}

void GPS::draw(ogstream* gout)
{
	gout->drawGPS(position, getDirection().getRadians());
}

list<Part*> GPS::getPartPieces()
{
	list<Part*> pieces;

	Fragment* fragment1 = new Fragment(position, velocity, Angle(0));
	Fragment* fragment2 = new Fragment(position, velocity, Angle(0));
	Fragment* fragment3 = new Fragment(position, velocity, Angle(0));
	Fragment* fragment4 = new Fragment(position, velocity, Angle(0));

	GPSCenter* center = new GPSCenter(position, velocity, Angle(0));
	GPSRight* right = new GPSRight(position, velocity, Angle(0));
	GPSLeft* left = new GPSLeft(position, velocity, Angle(0));

	pieces.push_back(fragment1);
	pieces.push_back(fragment2);
	pieces.push_back(fragment3);
	pieces.push_back(fragment4);
	pieces.push_back(center);
	pieces.push_back(right);
	pieces.push_back(left);

	return pieces;
}
