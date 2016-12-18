#include<iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class BoundCheck2DIntArray
{
private:
	Point* arr;
	int collen, rowlen;
	BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) {}
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr) {}
public:
	BoundCheck2DIntArray(int _collen, int _rowlen) : collen(_collen), rowlen(_rowlen)
	{
		arr = new Point[_collen][_rowlen];
	}
	Point& operator[](int idx)
	{
		return arr[idx];
	}
	(Point[int idx1])& operator[](int idx2)
	{
		return arr[idx1][idx2];
	}
};

void main()
{
	BoundCheck2DIntArray arr2d(3, 4);
	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			arr2d[n][m] = n + m;
		}
	}
	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			cout << arr2d[n][m] << ' ';
			cout << endl;
		}
	}
}