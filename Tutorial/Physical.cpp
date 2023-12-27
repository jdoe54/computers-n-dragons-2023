#include "Physical.h"

Physical::Physical(int x, int y) {
	Physical::coords[0] = x;
	Physical::coords[1] = y;
}

void Physical::setCoord(int x, int y) {
	Physical::coords[0] = x;
	Physical::coords[1] = y;
}

