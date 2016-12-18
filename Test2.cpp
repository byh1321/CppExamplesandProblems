#include <iostream>
using namespace std;
class Point
{
private:
	int x;
	int y;
public:
	Point() : x(0), y(0) {}
	Point(int init_x, int init_y) {
		x = init_x;
		y = init_y;
	}
	int get_x() { return x; }
	int get_y() { return y; }
	void set(int x, int y) {
		x = x;
		y = y;
	}
	void print() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
	/*Point operator+(Point newpoint)
	{
		Point tmp(x + newpoint.x,y+newpoint.y);
		return tmp;
	}*/
	friend Point operator+(Point point1, Point point2);
};

Point operator+(Point point1, Point point2)
{
	Point tmp(point1.x + point2.x, point1.y + point2.y);
	return tmp;
}

void main()
{
	Point a(3, 5);
	Point b(4, 7);
	Point c = a + b;
	c.print();
}