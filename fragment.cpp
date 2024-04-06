#include "fragment.h"

void Fragment::draw(ogstream* gout)
{
   cout << "Fragment::draw"<< position << endl;
   gout->drawFragment(this->position, this->angle.getRadians());
   fragTime--;
   if (fragTime <= 0)
   {
      triggerDestruction();
   }
}
