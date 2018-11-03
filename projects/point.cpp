#include <math.h>

#include "point.h"

double Point::distance(const Point &p2)
{
	return sqrt( pow((x - p2.x),2)
		+ pow(y - p2.y,2));
}
