/***********************************************************************
 * Heaader File:
 *    Test : TestObjects
 * Author:
 *    Joshua & Kai
 * Summary:
 *    This is the test driver for the physics class. It is responsible
 *    for testing the Physics class. 
 ************************************************************************/
#pragma once

#include "physics.h"
#include "object.h"
#include "position.h"
#include <cassert>

class TestPhysics
{
public:
	void run() const {

		// positional calculations
		testCalculateNewPosBase();
		testCalculateNewPosConstantAcceleration();
		// acceleration calculations
		testCalculateDDX();
		testCalculateDDY();
		// velocity calculations
		testCalculateDX();
		testCalculateDY();
		// angle calculations
		testCalculateRadius();
		testCalculate0Angle();
		testCalculate90Angle();
		testCalculate180Angle();
		testCalculate270Angle();
		// check object collition
		testObjectCollide();
		testObjectCollideRadius();
		testObjectCollideOutsideRadius();
		
	}

private:
	/***************************************************
	 *	Test Physics calculateNewPos(object)
	 *  With the object at (0,1000) and the earth at (0,0)
	 *  the object should move towards the earth and be pulled
	 *  by gravity.
	 ***************************************************/
	void testCalculateNewPosBase() const {
		//setup
		Physics physics;
		Object earth("earth", Position(0.0, 0.0), false, true, 1.0, 1.0, 100, 0.0, 0.0, 0.0, 0.0, 10000, 9999);
		Object obj;
		Position newPos(0,1000);
		obj.setPosition(newPos);
		//verify setup
		assert(earth.getPosition().getMetersX() == 0.0);
		assert(earth.getPosition().getMetersY() == 0.0);
		assert(obj.getPosition().getMetersX() == 0);
		assert(obj.getPosition().getMetersY() == 1000);
		//execute
		try
		{
			physics.calculateNewPos(obj);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify
		assert(obj.getPosition().getMetersX() == 0);
		// TODO: Check math1
		assert(obj.getPosition().getMetersY() == 995.1);
	}

	/***************************************************
	 *	Test Physics calculateNewPos(object)
	 *  With the object at (0,1000) and const acceleration of ddx=10
	 *  the earth at (0,0) the object should move towards the earth 
	 *  at a constant acceleration, and be pulled by gravity.
	 ***************************************************/
	void testCalculateNewPosConstantAcceleration() const {
		//setup
		Physics physics;
		Object earth("earth", Position(0.0, 0.0), false, true, 1.0, 1.0, 100, 0.0, 0.0, 10.0, 0.0, 10000, 9999);
		Object obj;
		Position newPos(0, 1000);
		obj.setPosition(newPos);
		//verify setup
		assert(earth.getPosition().getMetersX() == 0.0);
		assert(earth.getPosition().getMetersY() == 0.0);
		assert(obj.getPosition().getMetersX() == 0);
		assert(obj.getPosition().getMetersY() == 1000);
		assert(obj.getDdx() == 10.0);
		//execute
		try
		{
			physics.calculateNewPos(obj);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify
		// TODO: Check math2
		assert(obj.getPosition().getMetersX() == 10);
		assert(obj.getPosition().getMetersY() == 995.1);
	}

	/***************************************************
	*	Test Physics calculateddx()
	***************************************************/
	void testCalculateDDX() const {
		//setup
		Physics physics;
		float ddx;
		//execute
		try
		{
		ddx = physics.calculateDDX(10.0, 1.0);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify
		assert(ddx == 8.41);
	}

	/***************************************************
	*	Test Physics calculateDDY()
	***************************************************/
	void testCalculateDDY() const {
		//setup
		Physics physics;
		float ddy;
		//execute
		try
		{
			ddy = physics.calculateDDY(10.0, 1.0);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify
		assert(ddy == 5.4);
	}

	/***************************************************
	* Test Physics calculateDX()
	* ***************************************************/
	void testCalculateDX() const {
		//setup
		Physics physics;
		float dx;
		//execute
		try
		{
			dx = physics.calculateDX(0.0, 10.0, 1.0);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify
		assert(dx == 10.0);
	}

	/***************************************************
	* Test Physics calculateDY()
	***************************************************/
	void testCalculateDY() const {
		//setup
		Physics physics;
		float dy;
		//execute
		try
		{
			dy = physics.calculateDY(0.0, 10.0, 1.0);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify
		assert(dy == 10.0);
	}

	/***************************************************
	* Test Physics calculateRadius()
	***************************************************/
	void testCalculateRadius() const {
		//setup
		Physics physics;
		float radius;
		//execute
		try
		{
			radius = physics.calculateRadius(0.0, 1000.0);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify
		assert(radius == 1.5708);
	}
	/***************************************************
	* Test calculateAngle() 0 degrees from center
	***************************************************/
	void testCalculate0Angle() const {
		//setup
		Physics physics;
		float angle;
		//execute
		try
		{
			angle = physics.calculateAngle(0.0, 1000.0);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify
		assert(angle == 0.0);
	}

	/***************************************************
	* Test calculateAngle() 90 degrees from center
	***************************************************/
	void testCalculate90Angle() const {
		//setup
		Physics physics;
		float angle;
		//execute
		try
		{
			angle = physics.calculateAngle(1000.0, 0.0);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify
		assert(angle == 90);
	}

	/***************************************************
	* Test calculateAngle() 180 degrees from center
	***************************************************/
	void testCalculate180Angle() const {
		//setup
		Physics physics;
		float angle;
		//execute
		try
		{
			angle = physics.calculateAngle(0.0, -1000.0);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify
		assert(angle == 180);
	}

	/***************************************************
	* Test calculateAngle() 270 degrees from center
	***************************************************/
	void testCalculate270Angle() const {
		//setup
		Physics physics;
		float angle;
		//execute
		try
		{
			angle = physics.calculateAngle(-1000.0, 0.0);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify
		assert(angle == 270);
	}

	/***************************************************
	* Test objectCollide() base case
	***************************************************/
	void testObjectCollide() const {
		//setup
		Physics physics;
		Object obj1("obj1", Position(0.0, 0.0), false, true, 1.0, 1.0, 100, 0.0, 0.0, 0.0, 0.0, 10000, 9999);
		Object obj2("obj2", Position(0.0, 0.0), false, true, 1.0, 1.0, 100, 0.0, 0.0, 0.0, 0.0, 10000, 9999);
		//execute
		assert(physics.isCollision(obj1, obj2) == true);
		//verify
		assert(obj1.getHitPoints() == 9998);
		assert(obj2.getHitPoints() == 9998);
	}
	/***************************************************
	* Test objectCollide() within radius of object
	***************************************************/
	void testObjectCollideRadius() const {
		//setup
		Physics physics;
		Object obj1("obj1", Position(100.0, 0.0), false, true, 1.0, 1.0, 100, 0.0, 0.0, 0.0, 0.0, 10000, 9999);
		Object obj2("obj2", Position(0.0, 0.0), false, true, 1.0, 1.0, 100, 0.0, 0.0, 0.0, 0.0, 10000, 9999);
		//execute
		assert(physics.isCollision(obj1, obj2) == true);
		//verify
		assert(obj1.getHitPoints() == 9998);
		assert(obj2.getHitPoints() == 9998);
	}
	/***************************************************
	* Test objectCollide() outside radius of object
	***************************************************/
	void testObjectCollideOutsideRadius() const {
		//setup
		Physics physics;
		Object obj1("obj1", Position(100.0, 0.0), false, true, 1.0, 1.0, 100, 0.0, 0.0, 0.0, 0.0, 10000, 9999);
		Object obj2("obj2", Position(-100.0, 0.0), false, true, 1.0, 1.0, 100, 0.0, 0.0, 0.0, 0.0, 10000, 9999);
		//execute
		assert(physics.isCollision(obj1, obj2) == false);
		//verify
		assert(obj1.getHitPoints() == 9999);
		assert(obj2.getHitPoints() == 9999);
	}

	/***************************************************
	* Test objectCollide() outside radius of object then collide after object update
	***************************************************/
	void testObjectCollideOutsideRadiusThenCollide() const {
		//setup
		Physics physics;
		Object obj1("obj1", Position(100.0, 0.0), false, true, 1.0, 1.0, 100, 0.0, 0.0, -10.0, 0.0, 10000, 9999);
		Object obj2("obj2", Position(-100.0, 0.0), false, true, 1.0, 1.0, 100, 0.0, 0.0, 10.0, 0.0, 10000, 9999);
		//execute
		assert(physics.isCollision(obj1, obj2) == false);
		//verify
		assert(obj1.getHitPoints() == 9999);
		assert(obj2.getHitPoints() == 9999);
		//execute
		obj1.update();
		obj2.update();
		assert(physics.isCollision(obj1, obj2) == true);
		//verify
		assert(obj1.getHitPoints() == 9998);
		assert(obj2.getHitPoints() == 9998);

	}
	private:
		Physics p;
		double tb = p.getTimeDilation();
};