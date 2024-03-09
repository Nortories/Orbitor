#pragma once

#include <cmath>
#include <iostream> // Include for cout
#include "object.h"
#include "config.h"
#define PHYSICS_H

using namespace std;

class Physics
{
public:

    //TIME

    /******************************************************************
    * @brief  Calculate the time dilation base on the hours of the 
    * day of current planet
    * @return double
    ******************************************************************/
    double getTimeDilation() {
        double tb = HOURS_DAY*60;
        return tb;
    }
    /******************************************************************
    * @brief Calculate the time per frame base on the time dilation
    * @return time per frame as double
    ******************************************************************/
    double getTimePerFrame() {
        double tb = getTimeDilation();
        double timePerFrame = tb / FPS;
        return timePerFrame;        
	}

    // EARTH

    /******************************************************************
    * @brief Calculate the rotation speed of the planet (Earth)
    * @return rotation speed as double
    ******************************************************************/
    double rotationSpeed() {
        double rSpeed = ((2 * M_PI) / FPS) * ((getTimeDilation() / EARTH_FULL_ROTATION));
        return rSpeed;
    }

    /******************************************************************
    * @brief magnitude of acceleration due to gravity at an altitude
    * @return magnitude of acceleration
    * @param height above the earth in meters
    ******************************************************************/
    double gravityEquation(double height) {
        double acceleration = GRAVITY * pow((RADIUS_OF_EARTH / (RADIUS_OF_EARTH + height)), 2);
        return acceleration;
    }

    /******************************************************************
    * @brief Calculate the height above the Earth
    * @return height as double
    * @param x horizontal position of the satellite where the center of the earth is 0
    * @param y vertical position of the satellite where the center of the earth is 0
    ******************************************************************/
    double heightAboveEarth(double x, double y) {
		double height = sqrt(pow(x, 2) + pow(y, 2)) - RADIUS_OF_EARTH;
		return height;
	}

    /******************************************************************
    * @brief Find the angle of the satellite in relation to the center of the earth
    * @return angle as double
    * @param x horizontal position of the satellite in meters
    * @param y vertical position of the satellite in meters
    ******************************************************************/
    double directionOfGravityPull(double x, double y) {
		double angle = atan2(0 - 0, x - y);
		return angle;
    }

    /******************************************************************
    * @brief Calculate the horizontal component of the acceleration
    * @return ddx as double
    * @param totalAcceleration as double
    * @param angleRadians as double
    ******************************************************************/
    double horizontalComponentDDX(double totalAcceleration, double angleRadians) {
		double ddx = totalAcceleration * sin(angleRadians);
		return ddx;
	}

    /******************************************************************
    * @brief Calculate the vertical component of the acceleration
    * @return ddy as double
    * @param totalAcceleration as double
    * @param angleRadians as double
    ******************************************************************/
    double verticalComponentDDY(double totalAcceleration, double angleRadians) {
        double ddy = totalAcceleration * cos(angleRadians);
        return ddy;
    }

    // MOTION

    /******************************************************************
    * @brief Law of inertia
    * @return final velocity as double
    * @param initialDistance as double
    * @param initialVelocity as double
    * @param time as double
    ******************************************************************/
    double motionConstantVelocity(double initialDistance, double velocity, double time) {
		double finalDistance = initialDistance + velocity * time;
		return finalDistance;
	}

    /******************************************************************
    * @brief Calculate the horizontal position
    * @return gpsX as double
    * @param x as double horizontal position
    * @param dx as double horizontal velocity
    * @param time as double
    ******************************************************************/
    double horizontalPositionConstantVelocity(double x, double dx, double time) {
        double gpsX = x + dx * time;
        return gpsX;
	}

    /******************************************************************
    * @brief Calculate the vertical position
    * @return gpsY as double
    * @param y as double vertical position
    * @param dy as double vertical velocity
    * @param time as double
    ******************************************************************/
    double verticalPositionConstantVelocity(double y, double dy, double time) {
		double gpsY = y + dy * time;
		return gpsY;
    }
    
    /******************************************************************
    * @brief Calculate the distance
    * @return distance in meters (m) as double
    * @param starting as double
    * @param velocity as double
    * @param time as double
    * @param acceleration as double
    ******************************************************************/
    double distanceFormula(double startingDistance, double velocity, double time, double acceleration) {
		double finalDistance = startingDistance + velocity * time + 0.5 * acceleration * pow(time, 2);
		return finalDistance;
	}

    /******************************************************************
    * @brief Calculate velocity
    * @return final velocity as double
    * @param velocity as double
    * @param acceleration as double
    * @param time as double
    ******************************************************************/
    double velocityConstantAcceleration(double velocity, double acceleration, double time) {
		double finalVelocity = velocity + acceleration * time;
		return finalVelocity;
	}

    /******************************************************************
    * @brief Calculate the horizontal position
    * @return gpsX as double
    * @param x as double horizontal position
    * @param dx as double horizontal velocity
    * @param ddx as double horizontal acceleration
    * @param time as double
    ******************************************************************/
    double horizontalDistanceFormula(double x, double dx, double ddx, double time) {
		double gpsX = x + dx * time + 0.5 * ddx * pow(time, 2);
		return gpsX;
	}

    /******************************************************************
    * @brief Calculate the vertical position
    * @return gpsY as double
    * @param y as double vertical position
    * @param dy as double vertical velocity
    * @param ddy as double vertical acceleration
    * @param time as double
    ******************************************************************/
    double verticalDistanceFormula(double y, double dy, double ddy, double time) {
        double gpsY = y + dy * time + 0.5 * ddy * pow(time, 2);
        return gpsY;
    }

    /******************************************************************
    * @brief Calculate the horizontal velocity
    * @return velocity as double
    * @param dx as double horizontal velocity
    * @param ddx as double horizontal acceleration
    * @param time as double
    ******************************************************************/
    double horizontalVelocity(double dx, double ddx, double time) {
		double velocity = dx + ddx * time;
		return velocity;
	}



    double calculateDistance(double x, double y) {
        return sqrt(x * x + y * y);
    }

    double calculateAngle(double x, double y) {
        return atan2(y, x); // atan2 parameters are typically (y, x)
    }

    double calculateDDX(double gravity, double angleRadians) {
        return gravity * sin(angleRadians);
    }

    double calculateDDY(double gravity, double angleRadians) {
        return gravity * cos(angleRadians);
    }

    double calculateDX(double dx, double ddx, double time) {
        return dx + ddx * time;
    }

    double calculateDY(double dy, double ddy, double time) {
        return dy + ddy * time;
    }

    double calculateRadius(double x, double y) {
        return 0;
	}

    // Pass Object by reference to modify its properties directly
    void calculateNewPos(Object obj) {
        // Uncomment and correct your calculation logic as needed
        /*
        double angleRadians = calculateAngle(obj.getPosition().getMetersX(), obj.getPosition().getMetersY());
        double ddx = calculateDDX(obj.getGravity(), angleRadians);
        double ddy = calculateDDY(obj.getGravity(), angleRadians);
        double dx = calculateDX(obj.getDX(), ddx, SEC_PER_FRAME);
        double dy = calculateDY(obj.getDY(), ddy, SEC_PER_FRAME);
        double gpsX = obj.getPosition().getMetersX() + dx * SEC_PER_FRAME + 0.5 * ddx * pow(SEC_PER_FRAME, 2);
        double gpsY = obj.getPosition().getMetersY() + dy * SEC_PER_FRAME + 0.5 * ddy * pow(SEC_PER_FRAME, 2);
        obj.setPosition(gpsX, gpsY);
        */
        std::cout << "calculateNewPos" << endl;
    }

    // Pass Objects by reference to avoid unnecessary copying
    bool isCollision(Object obj1, Object obj2) {
        // Implement collision logic
        return false;
    }

    private:
		Config config;
};