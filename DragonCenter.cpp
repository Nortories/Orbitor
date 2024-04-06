#include "DragonCenter.h"

void DragonCenter::draw(ogstream* gout)
{
   gout->drawCrewDragonCenter(position, this->angle.getRadians());
}

list<Part*> DragonCenter::getPartPieces()
{
   list<Part*> pieces;

   Fragment* fragment1 = new Fragment(position, velocity, Angle(0));
   Fragment* fragment2 = new Fragment(position, velocity, Angle(0));
   Fragment* fragment3 = new Fragment(position, velocity, Angle(0));
   Fragment* fragment4 = new Fragment(position, velocity, Angle(0));

   pieces.push_back(fragment1);
   pieces.push_back(fragment2);
   pieces.push_back(fragment3);
   pieces.push_back(fragment4);

   return pieces;
}
