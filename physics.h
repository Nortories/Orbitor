#include <cmath>
#include <iostream> // Include for cout
#include "object.h"
#define PHYSICS_H

#define SEC_PER_FRAME 48

using namespace std;

class Physics
{
public:
    float calculateDistance(float x, float y) {
        return sqrt(x * x + y * y);
    }

    float calculateAngle(float x, float y) {
        return atan2(y, x); // atan2 parameters are typically (y, x)
    }

    float calculateDDX(float gravity, float angleRadians) {
        return gravity * sin(angleRadians);
    }

    float calculateDDY(float gravity, float angleRadians) {
        return gravity * cos(angleRadians);
    }

    float calculateDX(float dx, float ddx, float time) {
        return dx + ddx * time;
    }

    float calculateDY(float dy, float ddy, float time) {
        return dy + ddy * time;
    }

    float calculateRadius(float x, float y) {
        return 0;
	}

    // Pass Object by reference to modify its properties directly
    void calculateNewPos(Object& obj) {
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
    bool isCollision(Object& obj1, Object& obj2) {
        // Implement collision logic
        return false;
    }
};