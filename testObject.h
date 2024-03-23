/***********************************************************************
 * Heaader File:
 *    Test : TestObjects
 * Author:
 *    Joshua & Kai
 * Summary:
 *    This is the unit test for the object class it tests all the 
 *    member functions and member variables of the object class
 ************************************************************************/
#pragma once

#include <iostream>
#include "object.h"
#include "velocity.h"
#include "angle.h"
#include <cassert>
#include <string>
#include "config.h"
#include "uiDraw.h"
#include "uiInteract.h"

using namespace std;


class TestObject
{
public:
	void run() const
	{
		// Constructor
		testConstructorDefault();
		//// Setters
		testSetters();
		//// Update
		testUpdateAtRest();
		testUpdateWithGravity();
		testUpdateInMotion();
		testCollision();
		testDraw();
		testDestructionTrigger();
		testDestroy();
		testHP();
	}
private:

	/***************************************************
	 *	Test Object default constructor
	 ***************************************************/
	void testConstructorDefault() const {
		//setup
		//exercise
		Object obj;
		//verify
		assert(obj.getType() == "none");
		assert(obj.getVelocity().getDx() == 0.0);
		assert(obj.getVelocity().getDy() == 0.0);
		assert(obj.getPosition().getMetersX() == 0.0);
		assert(obj.getPosition().getMetersY() == 0.0);
		assert(obj.getAngle().getDegrees() == 0.0);
		assert(obj.getRadius() == 0.0);
		assert(obj.getAngularVelocity() == 0.0);
		assert(obj.getHitPoints() == 1);
		assert(obj.getMass() == 0);
		//teardown
		cout << "Constructor default test passed" << endl;
	}

//	/***************************************************
//	* Test Object setters, object has member variables:
//	***************************************************/
	void testSetters() const {
		//setup
		Object obj;
		//exercise
		try
		{
			obj.setType("gps3");
			obj.setVelocity(Velocity(1.0, 1.0));
			obj.setPosition(Position(1.0, 1.0));
			obj.setAngle(Angle(90.0));
			obj.setRadius(1);
			obj.setAngularVelocity(1.0);
			obj.setHitPoints(1);
			obj.setMass(1);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify
		assert(obj.getType() == "gps3");
		assert(obj.getVelocity().getDx() == 1.0);
		assert(obj.getVelocity().getDy() == 1.0);
		assert(obj.getPosition().getMetersX() == 1.0);
		assert(obj.getPosition().getMetersY() == 1.0);
		assert(obj.getRadius() == 1);
		assert(obj.getAngularVelocity() == 1.0);
		assert(obj.getHitPoints() == 1);
		assert(obj.getMass() == 1);
		//teardown
		cout<< "Setters test passed"<<endl;
	}

//	/***************************************************
//	* Test Object update() falling with gravity
//	***************************************************/
	void testUpdateWithGravity() const {
		//setup
		// Object in the top left of the screen (x/y 1000) not moving
		Object obj(Velocity(0,0), Position(1000.0, 1000.0),Angle(0));
		//verify setup
		assert(obj.getType() == "none");
		assert(obj.getPosition().getMetersX() == 1000.0);
		assert(obj.getPosition().getMetersY() == 1000.0);
		assert(obj.getAngle().getDegrees() == 0.0);
		//cout << "Obj starting pos: " << obj.getPosition().getMetersX()<<" : "<< obj.getPosition().getMetersY() << endl;
		//exercise
		try
		{
			obj.update(1, GRAVITY);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify exercise
		assert(obj.getType() == "none");
		// falling because of gravity
		assert(obj.getPosition().getMetersX() == 993.06561279296875);
		assert(obj.getPosition().getMetersY() == 993.06561279296875);
		//cout << "Obj after update pos: " << obj.getPosition().getMetersX() << " : " << obj.getPosition().getMetersY() << endl;
		cout << "Update with gravity test passed" << endl;
		//teardown
	}

	//	/***************************************************
//	* Test Object update() with object at rest
//	***************************************************/
	void testUpdateAtRest() const {
		//setup
		// Object in the top left of the screen (x/y 1000) not moving
		Object obj(Velocity(0, 0), Position(1000.0, 1000.0), Angle(0));
		//verify setup
		assert(obj.getType() == "none");
		assert(obj.getPosition().getMetersX() == 1000.0);
		assert(obj.getPosition().getMetersY() == 1000.0);
		assert(obj.getAngle().getDegrees() == 0.0);
		//cout << "Obj starting pos: " << obj.getPosition().getMetersX() << " : " << obj.getPosition().getMetersY() << endl;
		//exercise
		try
		{
			obj.update(1, GRAVITY);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify exercise
		assert(obj.getType() == "none");
		// falling because of gravity
		assert(obj.getPosition().getMetersX() == 993.06561279296875);
		assert(obj.getPosition().getMetersY() == 993.06561279296875);
		//cout << "Obj after update pos: " << obj.getPosition().getMetersX() << " : " << obj.getPosition().getMetersY() << endl;
		cout << "Update at rest test passed" << endl;
		//teardown
	}

//	/***************************************************
//	* Test Object update() with one object in motion
//	***************************************************/
	void testUpdateInMotion() const {
		//setup
		Object obj(Velocity(100, 100), Position(1000.0, 1000.0), Angle(0));
		//verify setup
		assert(obj.getType() == "none");
		assert(obj.getPosition().getMetersX() == 1000.0);
		assert(obj.getPosition().getMetersY() == 1000.0);
		assert(obj.getAngle().getDegrees() == 0.0);
		//cout << "Obj starting pos: " << obj.getPosition().getMetersX() << " : " << obj.getPosition().getMetersY() << endl;
		//exercise
		try
		{
			obj.update(1, GRAVITY);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify exercise
		assert(obj.getType() == "none");
		//not x/y 1100 because of gravity is pulling
		assert(obj.getPosition().getMetersX() == 1093.0656738281250);
		assert(obj.getPosition().getMetersY() == 1093.0656738281250);
		//cout << "Obj after update pos: " << obj.getPosition().getMetersX() << " : " << obj.getPosition().getMetersY() << endl;
		cout << "Update in motion test passed" << endl;
		//teardown
	}	

//	/***************************************************
//	* Test Object hit function
//	***************************************************/
	void testCollision() const {
		//setup

		Object obj1(Velocity(100, 100), Position(1000.0, 1000.0), Angle(0));
		Object obj2(Velocity(100, 100), Position(1000.0, 1000.0), Angle(0));
		Object obj3(Velocity(100, 100), Position(1000.0, 1000.0), Angle(0));
		// does not collide with any of the above
		Object obj4(Velocity(100, 100), Position(0, 0), Angle(0));

		//verify setup
		//exercise
		assert(obj1.isHit(&obj2) == true);
		assert(obj1.isHit(&obj3) == true);
		assert(obj2.isHit(&obj3) == true);
		assert(obj2.isHit(&obj1) == true);
		assert(obj3.isHit(&obj1) == true);
		assert(obj3.isHit(&obj2) == true);
		assert(obj1.isHit(&obj4) == false);
		assert(obj2.isHit(&obj4) == false);
		assert(obj3.isHit(&obj4) == false);
		assert(obj4.isHit(&obj1) == false);
		assert(obj4.isHit(&obj2) == false);
		assert(obj4.isHit(&obj3) == false);

		cout << "Collision test passed" << endl;
		//verify exercise
		//teardown
	}

//	/***************************************************
//	* Test Object draw function
//	* This function is void and does not return anything
//	* Test will verify that the function does not throw an error
//	* Needs manual verification
//	***************************************************/
	void testDraw() const {
		//setup
		Position ptUpperRight;
		ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
		ptUpperRight.setPixelsX(1000.0);
		ptUpperRight.setPixelsY(1000.0);
		Position pt;
		ogstream gout(pt);
		Object obj;
		//exercise
		try
		{
			obj.draw(&gout);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify exercise
		//teardown
		cout << "Draw testdraw drawCrewDragon passed" << endl;
	}

//	/***************************************************
//	* Test Object DestructionTrigger function
//	***************************************************/
	void testDestructionTrigger() const {
		//setup
		Object obj;
		//verify setup
		assert(obj.isDead() == false);
		//exercise
		try
		{
			obj.triggerDestruction();
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify exercise
		//manually verify fragment is drawn on screen
		assert(obj.isDead() == true);
		//teardown
		cout << "Destruction trigger test passed" << endl;
	}

//	/***************************************************
//	* Test Object destroy function
//	***************************************************/
	void testDestroy() const {
		//setup
		list<Object*> Objects;
		Object part;
		Objects.push_back(&part);
		Object mainObj;
		//verify setup
		assert(Objects.size() == 1);
		//exercise
		try
		{
			mainObj.explode(&Objects);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify exercise
		assert(Objects.size() == 1);
		//teardown
		cout << "Destroy test passed" << endl;
	}

//	/***************************************************
//	* Test Object destroy on hit HP = 0
//	***************************************************/
	void testHP() const {
		Object obj1(Velocity(100, 100), Position(1000.0, 1000.0), Angle(0));
		Object obj2(Velocity(100, 100), Position(1000.0, 1000.0), Angle(0));
		Object obj3(Velocity(100, 100), Position(1000.0, 1000.0), Angle(0));
		// does not collide with any of the above
		Object obj4(Velocity(100, 100), Position(0, 0), Angle(0));

		//verify setup
		assert(obj1.getHitPoints() == 1);
		assert(obj2.getHitPoints() == 1);
		assert(obj3.getHitPoints() == 1);
		assert(obj4.getHitPoints() == 1);
		assert(obj1.isHit(&obj2) == true);
		assert(obj1.isHit(&obj3) == true);
		assert(obj2.isHit(&obj3) == true);
		assert(obj2.isHit(&obj1) == true);
		assert(obj3.isHit(&obj1) == true);
		assert(obj3.isHit(&obj2) == true);
		assert(obj1.isHit(&obj4) == false);
		assert(obj2.isHit(&obj4) == false);
		assert(obj3.isHit(&obj4) == false);
		assert(obj4.isHit(&obj1) == false);
		assert(obj4.isHit(&obj2) == false);
		assert(obj4.isHit(&obj3) == false);
		//exercise
		obj1.isHit(&obj2);
		obj2.isHit(&obj1);
		obj4.isHit(&obj1);

		//verify exercise

		assert(obj1.getHitPoints() <= 0);
		assert(obj2.getHitPoints() <= 0);
		assert(obj4.getHitPoints() == 1);
		//teardown
		cout << "Collision HP passed" << endl;
	}
};