#include"9_Point.h"

Point::Point(int x, int y) : xpos(x), ypos(y)
{}

ostream& operator<<(ostream& os, const Point& pos)
{
	cout << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

