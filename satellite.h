#pragma once
#define _USE_MATH_DEFINES
#include "velocity.h"
#include "position.h"
#include "angle.h"
#include "uiDraw.h"
#include <math.h>
#include <cmath>
#include <list>
using namespace std;

class TestShip;
class Part;

class Satellite
{
public:
	friend class TestShip;

	Satellite() : angularVelocity(0), dead(false), radius(0)
	{
		// Stub
	}

	Satellite(const Velocity& vel, const Position& pos, const Angle& angle)
	{
		this->velocity = vel;
		this->pos = pos;
		this->angle = angle;
	}

	float getRadius()      const { return radius; };
	bool isDead()          const { return dead;   };
	Position getPosition() const { return pos;    };
	void kill();

	// Virtual functions
	virtual void draw(ogstream* gout) {};
	virtual void destroy(list<Satellite*>* satellites); // Takes satellites as param
	void move();
	virtual void input();
	bool isColliding(Satellite* other);
	bool isCollidingEarth();
protected:
	float getGravity(const Position& pos);
	Angle getDirection() const;
	Angle getDirectionGravity() const;
	void updateVelocity(float aGravity, float time);
	void updatePosition(float time);
	virtual list<Part*> getDebris();

	Velocity velocity;
	Position pos;
	Angle angle;
	float angularVelocity;
	bool dead;
	float radius;
};
