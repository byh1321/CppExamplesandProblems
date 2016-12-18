#include<iostream>
using namespace std;

class Rectangle
{
private:
	int x;
	int y;
public:
	Rectangle(int _x, int _y)
		: x(_x), y(_y)
	{
		//empty
	}
	void ShowAreaInfo()
	{
		cout << x*y << endl;
	}
};

class Square : public Rectangle
{
public:
	Square(int xy) : Rectangle(xy, xy)
	{
		//empty
	}
};

void main()
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return;
}