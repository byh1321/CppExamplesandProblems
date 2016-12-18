#include<iostream>
using namespace std;

template <class T>
void SwapData(T& num1, T& num2)
{
	T tmp;
	tmp = num1;
	num1 = num2;
	num2 = tmp;
}

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{	}
	void ShowPosition() const
	{
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}
};

void main()
{
	Point po1(3, 4);
	Point po2(5, 6); 
	po1.ShowPosition();
	po2.ShowPosition();
	SwapData<Point>(po1, po2);
	po1.ShowPosition();
	po2.ShowPosition();
}