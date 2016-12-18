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
	friend ostream& operator << (ostream&, const Point&);
	friend istream& operator >> (istream&, Point&);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

istream& operator >> (istream& is, Point& pos)
{
	is >> pos.xpos;
	is >> pos.ypos;
	return is;
}

void main()
{
	Point pos1;
	cout << "x, y ��ǥ ������ �Է� : ";
	cin >> pos1;
	cout << pos1;

	Point pos2;
	cout << "x, y ��ǥ ������ �Է� : ";
	cin >> pos2;
	cout << pos2;
}