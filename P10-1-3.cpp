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
	friend bool operator==(const Point &ref1, const Point &ref2)
	{
		if (ref1.xpos == ref2.xpos && ref1.ypos == ref2.ypos)
			return true;
		else
			return false;
	}
	friend bool operator!=(const Point &ref1,const Point &ref2)
	{
		return !(ref1 == ref2);
	}
};

void main()
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3(3, 4);
	cout << (pos1 == pos2) << endl;
	cout << (pos1 == pos3) << endl;
}