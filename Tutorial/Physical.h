#pragma once
using namespace std;

class Physical
{
	int coords[2];
	bool collision = false;

	public:

		bool getCollision(void) {
			return collision;
		}

		int* getCoord(void) {
			return coords;
		}

		Physical(int x, int y);
};



