#include "HubbleRight.h"

void HubbleRight::draw(ogstream* gout)
{
   gout->drawHubbleRight(position, this->angle.getRadians());
}

list<Part*> HubbleRight::getPartPieces()
{
   list<Part*> pieces;

   Fragment* fragment1 = new Fragment(position, velocity, Angle(0));
   Fragment* fragment2 = new Fragment(position, velocity, Angle(0));

   pieces.push_back(fragment1);
   pieces.push_back(fragment2);

   return pieces;
}
