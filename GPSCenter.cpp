#include "GPSCenter.h"

void GPSCenter::draw(ogstream* gout)
{
   gout->drawGPSCenter(position, this->angle.getRadians());
}

list<Part*> GPSCenter::getPartPieces()
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
