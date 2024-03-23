#include "StarShipEnterprise.h"
#include "fragment.h"
#include <math.h>
#define _USING_MATH_DEFINES

StarShipEnterprise::StarShipEnterprise()
{
	cout << "StarShipEnterprise()" << endl;
	this->velocity = Velocity(DREAM_CHASER_VECTOR_X, DREAM_CHASER_VECTOR_Y);
	this->position.setPixelsX(DREAM_CHASER_POSITION_X_PX);
	this->position.setPixelsY(DREAM_CHASER_POSITION_Y_PX);
	this->radius = DREAM_CHASER_RADIUS;
	this->thrust = false;
}

StarShipEnterprise::StarShipEnterprise(const Velocity& vel, const Position& pos, const Angle& ang, float angular)
{
	this->velocity = vel;
	this->position = pos;
	this->angle = ang;
	this->angularVelocity = 0.00;
	this->angularVelocity = angular;
	this->selfDestruct = false;
	this->radius = 5.00;
	this->thrust = false;
}

void StarShipEnterprise::flyShip()
{
	float newGravity = getGravity(position);
	update(FPS, newGravity);
	if (thrust)
	{
		Angle thrustAngle = angle.getRadians() - ((3 * M_PI )/ 2);
		velocity.add(Velocity(2 * FPS, thrustAngle));
	}
	angle.rotate(this->angularVelocity);
}

Bullet* StarShipEnterprise::fire()
{
	Velocity bulletSpeed = this->velocity;
	Position bulletPos = this->position;
	Angle bulletAngle = this->angle;
	//cout << bulletPos.getMetersX() << " " << bulletPos.getMetersY() << endl;
	bulletAngle.rotate(M_PI / 2);
	//bulletPos.addMetersX(1000000);
	//bulletPos.addMetersY(1000000);
	bulletSpeed.add(Velocity(BULLET_SPEED, bulletAngle));
	Bullet* bullet = new Bullet(bulletSpeed, bulletPos, bulletAngle);
	// move the bullet a few frames so it doesn't collide with the ship
	for (int i = 0; i < 5; i++)
	{
		bullet->updatePosition();
	}
	return bullet;
}

list<Part*> StarShipEnterprise::getParts()
{
	list<Part*> debris;
	bool addKick = true;

	Fragment* fragment1 = new Fragment(position, velocity, Angle(0));
	Fragment* fragment2 = new Fragment(position, velocity, Angle(0));

	debris.push_back(fragment1);
	debris.push_back(fragment2);

	return debris;
}


