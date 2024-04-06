#include "GPSLeft.h"

void GPSLeft::draw(ogstream* gout)
{
   gout->drawGPSLeft(position, this->angle.getRadians());
}

list<Part*> GPSLeft::getPartPieces()
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
