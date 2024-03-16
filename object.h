#pragma once

#include <iostream>
#include <string>
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "angle.h"
#include <list>
#include "part.h"
#include "config.h"

using namespace std;

class Object
{
public:
	//default constructor
	Object() : angle(0), radius(0), angularVelocity(0), destroyed(false), hitPoints(0), mass(0) {
		this->type = "none";
		this->velocity = Velocity(0, 0);
		this->position = Position(0, 0);
	}

	//min constructor
	Object(string type, Velocity& velocity, Position& position, Angle& angle) {
		this->type = type;
		this->velocity = velocity;
		this->position = position;
		this->angle = angle;
		this->radius = 0;
		this->angularVelocity = 0;
		this->destroyed = false;
		this->hitPoints = 0;
		this->mass = 0;
	}

	//everything constructor
	Object(string type, Velocity velocity, Position position, Angle angle, float radius, float angularVelocity, bool destroyed, int hitPoints, float mass) {
		this->type = type;
		this->velocity = velocity;
		this->position = position;
		this->angle = angle;
		this->radius = radius;
		this->angularVelocity = angularVelocity;
		this->destroyed = destroyed;
		this->hitPoints = hitPoints;
		this->mass = mass;
	}


	//getters
	string getType() const { return type; }
	Velocity getVelocity() const { return velocity; }
	Position getPosition() const { return position; }
	Angle getAngle() const { return angle; }
	float getRadius() const { return radius; }
	float getAngularVelocity() const { return angularVelocity; }
	bool getIsDestroyed() const { return destroyed; }
	int getHitPoints() const { return hitPoints; }
	float getMass() const { return mass; }


	//setters
	void setType(string type) { this->type = type; }
	void setVelocity(Velocity velocity) { this->velocity = velocity; }
	void setPosition(Position position) { this->position = position; }
	void setAngle(Angle angle) { this->angle = angle; }
	void setRadius(float radius) { this->radius = radius; }
	void setAngularVelocity(float angularVelocity) { this->angularVelocity = angularVelocity; }
	void setIsDestroyed(bool destroyed) { this->destroyed = destroyed; }
	void setHitPoints(int hitPoints) { this->hitPoints = hitPoints; }
	void setMass(float mass) { this->mass = mass; }

	//member functions
	virtual void draw(ogstream* gout) {/*override and draw self*/}

	void triggerDestruction() 
	{ destroyed = true; }

	virtual void destroy(list<Object*>* obj)
	{
		list<Part*> debris = getParts();
		float offset = (2 * M_PI) / debris.size();
		int partNum = 0;

		// auto is a keyword that tells the compiler to figure out the 
		// type of the variable at compile time. This is needed because
		// the list class does not have a type. It is a template class.
		for (auto& part : debris)
		{

		// The kick method is a method of the part class. It sets the
		// velocity of the part so that it will move in a circle around
		// the center of the object.
		part->kick(offset * partNum);

		// push_back is a method of the list class.
		// It adds part to the end of the list so that it can be drawn.
		// Oject-> is needed to access the list of parts in the Object class.
		obj->push_back(part);
		partNum++;
		}
	}

	void update(float time, float gravity) {

		float newX = position.getMetersX() + (velocity.getDx() * time);
		float newY = position.getMetersY() + (velocity.getDy() * time);
		position.setMetersX(newX);
		position.setMetersY(newY);

		float gravityDirection = atan2(position.getMetersX(), position.getMetersY());

		float ddx = gravity * sin(gravityDirection);
		float ddy = gravity * cos(gravityDirection);

		float newDx = velocity.getDx() + (ddx * time);
		float newDy = velocity.getDy() + (ddy * time);

		velocity.setDx(newDx);
		velocity.setDy(newDy);
	}

	void move()
	{
		float aGravity = getGravity(position);
		updateVelocity(aGravity, FPS);
		updatePosition(FPS);
		angle.rotate(this->angularVelocity);
	}
	bool hit(Object* obj)
	{
		float distance = sqrt((position.getMetersX() - obj->position.getMetersX()) * (position.getMetersX() - obj->position.getMetersX()) +
			(position.getMetersY() - obj->position.getMetersY()) * (position.getMetersY() - obj->position.getMetersY()));
		float hitBox = (radius + obj->radius) * 128000;
		if (distance < hitBox)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool earthCrash()
	{
		float distance = sqrt((position.getMetersX() - 0) * (position.getMetersX() - 0) +
			(position.getMetersY() - 0) * (position.getMetersY() - 0));
		float radii = (radius + 128000) + RADIUS_OF_EARTH;
		if (distance < radii)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


protected:
	//member functions
	float getGravity(const Position& pos)
	{
		// First get the height from earth.
		float height = sqrt((pos.getMetersX() * pos.getMetersX()) + (pos.getMetersY() * pos.getMetersY())) - RADIUS_OF_EARTH;
		// Then calculate the gravity at that height.
		float gravity = GRAVITY * ((RADIUS_OF_EARTH / (RADIUS_OF_EARTH + height)) * (RADIUS_OF_EARTH / (RADIUS_OF_EARTH + height)));
		return gravity;
	};

	Angle getDirection() const
	{
		return Angle(atan2(velocity.getDx(), velocity.getDy()));
	};

	Angle getDirectionGravity() const
	{
		return Angle(atan2(position.getMetersX(), position.getMetersY()));
	};

	void updateVelocity(float aGravity, float time);
	void updatePosition(float time);

	virtual list<Part*> getParts()
	{
		list<Part*> parts;
		return parts;
	};

	//member variables
	string type;
	Velocity velocity;
	Position position;
	Angle angle;
	float radius;
	float angularVelocity;
	bool destroyed;
	int hitPoints;
	float mass;

};