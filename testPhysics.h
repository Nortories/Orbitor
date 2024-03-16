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


		// acceleration calculations
		testCalculateDDX();
		testCalculateDDY();
		// velocity calculations
		testCalculateDX();
		testCalculateDY();
		// angle calculations
		testCalculate0Angle();
		testCalculate90Angle();
		testCalculate180Angle();
		testCalculate270Angle();
		cout << "Physics tests passed" << endl;
	}

private:
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
		assert(ddx == 8.41471004f);
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
		assert(ddy == 5.40302324f);
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
		assert(angle == 1.57079637f);
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
			angle = physics.calculateAngle(1000.0, 50.0);
		}
		catch (const std::exception&)
		{
			assert(false);
		}
		//verify
		assert(angle == 0.0499583967f);
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
		assert(angle == -1.57079637f);
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
		assert(angle == 3.14159274f);
	}
	private:
		Physics p;
		double tb = p.getTimeDilation();
};