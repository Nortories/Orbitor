#include "part.h"
#include "object.h"

using namespace std;

// Returns nothing by default, but can be overridden by derived classes to include its parts.
list<Part*> Object::getPartPieces()
{
	list<Part*> parts;
	return parts;
}

void Object::explode(list<Object*>* simsObjList)
{
	list<Part*> spaceJunk = getPartPieces();
	cout << "Got junk" << endl;
	float offset = (2 * M_PI) / spaceJunk.size();
	int partNum = 0;

	// for (auto& part : debris) is a range based for loop. It will loop through all the parts in the list.
	// The & is used to pass the part by reference, so we can modify the actual part in the list instead of a copy.
	for (auto& part : spaceJunk)
	{
		cout << "Exploding part" << endl;
		// Set the parts angle to a offset and by the number of parts.
		// This will spread the parts out in a circle, hopfuly.
		part->tossPart(offset * partNum);
		// Push the part into the list of objects.
		simsObjList->push_back(part);
		// Increment the part number for the next time we loop, this will help spread the parts on deystory.
		partNum++;
	}
}