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
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	int operator-(int number)
	{
		return -number;
	}
	Point operator-()
	{
		Point tmppos(-xpos, -ypos);
		return tmppos;
	}
	Point operator~()
	{
		Point tmppos(ypos, xpos);
		return tmppos;
	}
};

void main()
{
	Point pos(1, 2);
	int num1 = 3;
	int num2 = -num1;
	cout << num2 << endl;
	Point pos2 = -pos;
	pos2.ShowPosition();
	Point pos3 = ~pos;
	pos3.ShowPosition();
	pos.ShowPosition();
}