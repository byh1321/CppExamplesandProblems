#include<iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{
		//empty
	}
	void ShowPosition() const
	{
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}
	/*friend void operator+=(Point &ref1, Point &ref2)
	{
		ref1.xpos += ref2.xpos;
		ref1.ypos += ref2.ypos;
	}*/		
	//이 방식으로도 사용 가능
	void operator+=(const Point &ref)
	{
		xpos = xpos + ref.xpos;
		ypos = ypos + ref.ypos;
	}
	friend void operator-=(Point &ref1, Point &ref2)
	{
		ref1.xpos -= ref2.xpos;
		ref1.ypos -= ref2.ypos;
	}
};

void main()
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	pos1 += pos2;
	pos2 -= pos1;
	pos1.ShowPosition();
	pos2.ShowPosition();
}