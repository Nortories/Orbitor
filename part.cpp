#include "part.h"

void Part::setRadians(float radians)
{
   this->angle.setRadians(radians);
}

void Part::tossPart(float throwPartAngle)
{
   this->velocity.add(Velocity(random(5000, 9000), Angle(throwPartAngle)));
   // move the PART 5 times to make sure it doesn't get stuck
   for (int i = 0; i < 10; i++) {
      updatePosition();
   }
}
