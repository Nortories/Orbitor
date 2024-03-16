#include "part.h"
#include "object.h"

using namespace std;


list<Part*> Object::getParts()
{
	list<Part*> parts;
	return parts;
}

void Object::destroy(list<Object*>* objList)
{
	list<Part*> debri = getParts();
	float offset = (2 * M_PI) / debri.size();
	int partNum = 0;

	// for (auto& part : debris) is a range based for loop. It will loop through all the parts in the list.
	// The & is used to pass the part by reference, so we can modify the actual part in the list instead of a copy.
	for (auto& part : debri)
	{

		// Set the parts angle to a offset and by the number of parts.
		// This will spread the parts out in a circle, hopfuly.
		part->throwPart(offset * partNum);

		// Push the part into the list of objects.
		objList->push_back(part);

		// Increment the part number for the next time we loop, this will help spread the parts on deystory.
		partNum++;
	}
}