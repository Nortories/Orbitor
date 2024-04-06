#include "DragonLeft.h"

void DragonLeft::draw(ogstream* gout)
{
   gout->drawCrewDragonLeft(position, this->angle.getRadians());
}

list<Part*> DragonLeft::getPartPieces()
{
   list<Part*> pieces;

   Fragment* fragment1 = new Fragment(position, velocity, Angle(0));
   Fragment* fragment2 = new Fragment(position, velocity, Angle(0));

   pieces.push_back(fragment1);
   pieces.push_back(fragment2);

   return pieces;
}
