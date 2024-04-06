#include "GPSRight.h"

void GPSRight::draw(ogstream* gout)
{
   gout->drawGPSRight(position, this->angle.getRadians());
}

list<Part*> GPSRight::getPartPieces()
{
   list<Part*> pieces;

   Fragment* fragment1 = new Fragment(position, velocity, Angle(0));
   Fragment* fragment2 = new Fragment(position, velocity, Angle(0));
   Fragment* fragment3 = new Fragment(position, velocity, Angle(0));

   pieces.push_back(fragment1);
   pieces.push_back(fragment2);
   pieces.push_back(fragment3);

   return pieces;
}
