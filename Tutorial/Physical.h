#pragma once
using namespace std;

class Physical
{
	int coords[2];
	bool collision = false;

	public:

		Physical(int x, int y);
		Physical() = default;
		bool getCollision(void) { return collision; }
		int* getCoord(void) { return coords; }
		void setCoord(int x, int y);
		
};



