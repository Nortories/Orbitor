#pragma once

#include <iostream>
#include "object.h"
#include "game.h"
#include <cassert>
#include <string>

using namespace std;


class TestObject
{
public:
	void run() const
	{
		// Constructor
		testConstructorDefault();
		// Getters
		testGetters();
		// Setters
		testSetters();
		// Update
		testUpdateAtRest();
		testUpdateInMotion();
		testUpdateAcceleration();
		// Hit
		testCollision();
		// Draw
		testDraw();
		// Fragment
		testFragment();
		// Destroy
		testDestroy();
		testDestroyOnHit();
		testNotDestroyOnHit();

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
		assert(obj.getType() == "");
		assert(obj.getPosition().getMetersX() == 0.0);
		assert(obj.getPosition().getMetersY() == 0.0);
		assert(obj.getHasFragment() == true);
		assert(obj.getHasCollide() == true);
		assert(obj.getAngle() == 0.0);
		assert(obj.getTime() == 0.0);
		assert(obj.getRadius() == 0);
		assert(obj.getDx() == 0.0);
		assert(obj.getDy() == 0.0);
		assert(obj.getDdx() == 0.0);
		assert(obj.getDdy() == 0.0);
		assert(obj.getMass() == 0);
		assert(obj.getHitPoints() == 1);
		//teardown
	}

	/***************************************************
	 *	Test Object constructor creates object with default values
	 ***************************************************/
	void testConstructorNonDefault() const {
		//setup
		//exercise
		Object obj("type", Position(1.0, 1.0), true, true, 1.0, 1.0, 1, 1.0, 1.0, 1.0, 1.0, 1, 1);
		//verify
		assert(obj.getType() == "type");
		assert(obj.getPosition().getMetersX() == 1.0);
		assert(obj.getPosition().getMetersY() == 1.0);
		assert(obj.getHasFragment() == true);
		assert(obj.getHasCollide() == true);
		assert(obj.getAngle() == 1.0);
		assert(obj.getTime() == 1.0);
		assert(obj.getRadius() == 1);
		assert(obj.getDx() == 1.0);
		assert(obj.getDy() == 1.0);
		assert(obj.getDdx() == 1.0);
		assert(obj.getDdy() == 1.0);
		assert(obj.getMass() == 1);
		assert(obj.getHitPoints() == 1);
		//teardown
	}

	/***************************************************
	 * Test Object getters, object has member variables:
	 ***************************************************/
	void testGetters() const {
		//setup
		Object obj("type", Position(1.0, 1.0), true, true, 1.0, 1.0, 1, 1.0, 1.0, 1.0, 1.0, 1, 1);
		//exercise
		//verify
		assert(obj.getType() == "type");
		assert(obj.getPosition().getMetersX() == 1.0);
		assert(obj.getPosition().getMetersY() == 1.0);
		assert(obj.getHasFragment() == true);
		assert(obj.getHasCollide() == true);
		assert(obj.getAngle() == 1.0);
		assert(obj.getTime() == 1.0);
		assert(obj.getRadius() == 1);
		assert(obj.getDx() == 1.0);
		assert(obj.getDy() == 1.0);
		assert(obj.getDdx() == 1.0);
		assert(obj.getDdy() == 1.0);
		assert(obj.getMass() == 1);
		assert(obj.getHitPoints() == 1);
		//teardown
	}

	/***************************************************
	* Test Object setters, object has member variables:
	***************************************************/
	void testSetters() const {
		//setup
		Object obj;
		//exercise
		try
		{
			obj.setType("type");
			obj.setPosition(Position(1.0, 1.0));
			obj.setHasFragment(true);
			obj.setHasCollide(true);
			obj.setAngle(1.0);
			obj.setTime(0.0);
			obj.setRadius(1);
			obj.setDx(1.0);
			obj.setDy(1.0);
			obj.setDdx(1.0);
			obj.setDdy(1.0);
			obj.setMass(1);
			obj.setHitPoints(1);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify
		assert(obj.getType() == "type");
		assert(obj.getPosition().getMetersX() == 1.0);
		assert(obj.getPosition().getMetersY() == 1.0);
		assert(obj.getHasFragment() == true);
		assert(obj.getHasCollide() == true);
		assert(obj.getAngle() == 1.0);
		assert(obj.getTime() == 0.0); 
		assert(obj.getRadius() == 1);
		assert(obj.getDx() == 1.0);
		assert(obj.getDy() == 1.0);
		assert(obj.getDdx() == 1.0);
		assert(obj.getDdy() == 1.0);
		assert(obj.getMass() == 1);
		assert(obj.getHitPoints() == 1);
		//teardown
	}

	/***************************************************
	* Test Object update() with object at rest
	***************************************************/
	void testUpdateAtRest() const {
		//setup
		// Object in the top left of the screen (x/y 1000) not moving with 100kg mass
		Object obj("type", Position(1000.0, 1000.0), true, true, 0.0, 0.0, 10, 0.0, 0.0, 0.0, 0.0, 100, 1);
		//verify setup
		assert(obj.getType() == "type");
		assert(obj.getPosition().getMetersX() == 1000.0);
		assert(obj.getPosition().getMetersY() == 1000.0);
		assert(obj.getHasFragment() == true);
		assert(obj.getHasCollide() == true);
		assert(obj.getAngle() == 0.0);
		assert(obj.getTime() == 0.0);
		assert(obj.getRadius() == 10);
		assert(obj.getDx() == 0.0);
		assert(obj.getDy() == 0.0);
		assert(obj.getDdx() == 0.0);
		assert(obj.getDdy() == 0.0);
		assert(obj.getMass() == 100);
		assert(obj.getHitPoints() == 1);
		//exercise
		try
		{
			obj.update();
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify exercise
		assert(obj.getType() == "type");
		assert(obj.getPosition().getMetersX() == 1000.0);
		assert(obj.getPosition().getMetersY() == 1000.0);
		assert(obj.getHasFragment() == true);
		assert(obj.getHasCollide() == true);
		assert(obj.getAngle() == 0.0);
		assert(obj.getTime() == 1.0); // assuming 1 second has passed
		assert(obj.getRadius() == 10);
		assert(obj.getDx() == 0.0);
		assert(obj.getDy() == 0.0);
		assert(obj.getDdx() == 0.0);
		assert(obj.getDdy() == 0.0);
		assert(obj.getMass() == 100);
		assert(obj.getHitPoints() == 1);
		//teardown
	}

	/***************************************************
	* Test Object update() with one object in motion
	***************************************************/
	void testUpdateInMotion() const {
		//setup
		// Object in the top left of the screen (x/y 1000) moving down/left at 10m per update with 10m/s^2 acceleration and 100kg mass
		Object obj("type", Position(1000.0, 1000.0), true, true, 0.0, 0.0, 10, -10.0, -10.0, -10.0, -10.0, 100, 1);
		//verify setup
		assert(obj.getType() == "type");
		assert(obj.getPosition().getMetersX() == 1000.0);
		assert(obj.getPosition().getMetersY() == 1000.0);
		assert(obj.getHasFragment() == true);
		assert(obj.getHasCollide() == true);
		assert(obj.getAngle() == 0.0);
		assert(obj.getTime() == 0.0);
		assert(obj.getRadius() == 10);
		assert(obj.getDx() == -10.0);
		assert(obj.getDy() == -10.0);
		assert(obj.getDdx() == -10.0);
		assert(obj.getDdy() == -10.0);
		assert(obj.getMass() == 100);
		assert(obj.getHitPoints() == 1);
		//exercise
		try
		{
			obj.update();
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify exercise
		assert(obj.getType() == "type");
		assert(obj.getPosition().getMetersX() == 990.0);
		assert(obj.getPosition().getMetersY() == 990.0);
		assert(obj.getHasFragment() == true);
		assert(obj.getHasCollide() == true);
		assert(obj.getAngle() == 0.0);
		assert(obj.getTime() == 1.0); // assuming 1 second has passed
		assert(obj.getRadius() == 10);
		assert(obj.getDx() == -20.0);
		assert(obj.getDy() == -20.0);
		assert(obj.getDdx() == -10.0);
		assert(obj.getDdy() == -10.0);
		assert(obj.getMass() == 100);
		assert(obj.getHitPoints() == 1);
		
		//teardown
	}	

	/***************************************************
	* Test Object update() with one object not in motion but with acceleration
	***************************************************/
	void testUpdateAcceleration() const {
		//setup
		// Object in the top left of the screen (x/y 1000) not moving with 10m/s^2 acceleration and 100kg mass
		Object obj("type", Position(1000.0, 1000.0), true, true, 0.0, 0.0, 10, 0.0, 0.0, 10.0, 10.0, 100, 1);
		//verify setup
		assert(obj.getType() == "type");
		assert(obj.getPosition().getMetersX() == 1000.0);
		assert(obj.getPosition().getMetersY() == 1000.0);
		assert(obj.getHasFragment() == true);
		assert(obj.getHasCollide() == true);
		assert(obj.getAngle() == 0.0);
		assert(obj.getTime() == 0.0);
		assert(obj.getRadius() == 10);
		assert(obj.getDx() == 0.0);
		assert(obj.getDy() == 0.0);
		assert(obj.getDdx() == 10.0);
		assert(obj.getDdy() == 10.0);
		assert(obj.getMass() == 100);
		assert(obj.getHitPoints() == 1);
		//exercise
		try
		{
			obj.update();
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify exercise
		assert(obj.getType() == "type");
		assert(obj.getPosition().getMetersX() == 1010.0);
		assert(obj.getPosition().getMetersY() == 1010.0);
		assert(obj.getHasFragment() == true);
		assert(obj.getHasCollide() == true);
		assert(obj.getAngle() == 0.0);
		assert(obj.getTime() == 1.0); // assuming 1 second has passed
		assert(obj.getRadius() == 10);
		assert(obj.getDx() == 0.0);
		assert(obj.getDy() == 0.0);
		assert(obj.getDdx() == 10.0);
		assert(obj.getDdy() == 10.0);
		assert(obj.getMass() == 100);
		assert(obj.getHitPoints() == 1);
		//teardown
	}

	/***************************************************
	* Test Object hit function
	***************************************************/
	void testCollision() const {
		//setup
		Object obj;
		//verify setup
		assert(obj.getHitPoints() == 1);
		//exercise
		try
		{
			obj.hit();
		}
		catch (const std::exception&)
		{

		}
		//verify exercise
		assert(obj.getHitPoints() == 0);
		//teardown
	}

	/***************************************************
	* Test Object draw function
	* This function is void and does not return anything
	* Test will verify that the function does not throw an error
	* Needs manual verification
	***************************************************/
	void testDraw() const {
		//setup
		Object obj;
		//exercise
		try
		{
		obj.draw();
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify exercise
		//teardown
	}

	/***************************************************
	* Test Object fragment function
	***************************************************/
	void testFragment() const {
		//setup
		Object obj;
		//verify setup
		assert(obj.getHasFragment() == false);
		//exercise
		try
		{
			obj.fragment();
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify exercise
		//manually verify fragment is drawn on screen
		assert(obj.getHasFragment() == true);
		//teardown
	}

	/***************************************************
	* Test Object destroy function
	***************************************************/
	void testDestroy() const {
		//setup
		//dummyGame creates a object inside it's member var array
		class dummyGame : public Game {
			public:
				Object obj;
			//dummyGame array of objects
				Object objects[1] = { obj };
		};

		dummyGame game;
		//verify setup
		assert(game.obj.getHitPoints() == 1);
		//exercise
		try
		{
			game.obj.destroy();
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify exercise
		assert(sizeof(game.objects) == 0);
		//teardown
	}

	/***************************************************
	* Test Object destroy on hit HP = 0
	***************************************************/
	void testDestroyOnHit() const {
		//setup
		//dummyGame creates a object inside it's member var array
		class dummyGame : public Game {
		public:
			Object obj;
			//dummyGame array of objects
			Object objects[1] = { obj };
		};

		dummyGame game;
		//verify setup
		assert(game.objects[0].getHitPoints() == 1);
		//exercise
		try
		{
			game.objects[0].hit();
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify exercise
		assert(sizeof(game.objects) == 0);
	}

	/***************************************************
	* Test Object !destroy on hit HP = 1
	***************************************************/
	//setup
	void testNotDestroyOnHit() const {


		//dummyGame creates a object inside it's member var array
	class dummyGame : public Game {
	public:
		Object obj;
		//dummyGame array of objects
		Object objects[1] = { obj };
	};

	dummyGame game;
	game.objects[0].setHitPoints(2);
	//verify setup
	assert(game.objects[0].getHitPoints() == 2);
	//exercise
	try
	{
		game.objects[0].hit();
	}
	catch (const std::exception&)
	{
		assert(false);
	}
	//verify exercise
	assert(sizeof(game.objects) == 0);
	}
};