#pragma once

#include <iostream>
#include <string>
#include "position.h"
#include "fragments.h"

using namespace std;

class Object
{
public:
		//default constructor

		Object() : type(""), position(), hasFragment(true), hasCollide(true), angle(0.0), time(0.0), radius(0), dx(0.0), dy(0.0), ddx(0.0), ddy(0.0), mass(0), hitPoints(1) {}
		
		//non-default constructor
		Object(string type, Position position, bool hasFragment, bool hasCollide, float angle, float time, int radius, float dx, float dy, float ddx, float ddy, int mass, int hitPoints) 
		: type(type), position(position), hasFragment(hasFragment), hasCollide(hasCollide), angle(angle), time(time), radius(radius), dx(dx), dy(dy), ddx(ddx), ddy(ddy), mass(mass), hitPoints(hitPoints) 
		{}
		
		//getters

		string getType() const { return type; }
		Position getPosition() const { return position; }
		bool getHasFragment() const { return hasFragment; }
		bool getHasCollide() const { return hasCollide; }
		float getAngle() const { return angle; }
		float getTime() const { return time; }
		int getRadius() const { return radius; }
		float getDx() const { return dx; }
		float getDy() const { return dy; }
		float getDdx() const { return ddx; }
		float getDdy() const { return ddy; }
		int getMass() const { return mass; }
		int getHitPoints() const { return hitPoints; }
		bool getHasCollision() const { return hasCollision; }
		
		//setters
		void setType(string type) { this->type = type; }
		void setPosition(Position position) { this->position = position; }
		void setHasFragment(bool hasFragment) { this->hasFragment = hasFragment; }
		void setHasCollide(bool hasCollide) { this->hasCollide = hasCollide; }
		void setAngle(float angle) { this->angle = angle; }
		void setTime(float time) { this->time = time; }
		void setRadius(int radius) { this->radius = radius; }
		void setDx(float dx) { this->dx = dx; }
		void setDy(float dy) { this->dy = dy; }
		void setDdx(float ddx) { this->ddx = ddx; }
		void setDdy(float ddy) { this->ddy = ddy; }
		void setMass(int mass) { this->mass = mass; }
		void setHitPoints(int hitPoints) { this->hitPoints = hitPoints; }
		void setHasCollision(bool hasCollision) { this->hasCollision = hasCollision; }

		//member functions
		void fragment(){}
		void update() {}
		void hit() {}
		void destroy() {}
		void draw() {}


		private:
		//member variables

		string type;
		Position position;
		Fragment fragments;
		bool hasFragment;
		bool hasCollide;
		float angle;
		float time;
		int radius;
		float dx;
		float dy;
		float ddx;
		float ddy;
		int mass;
		int hitPoints;
		bool hasCollision = true;


};