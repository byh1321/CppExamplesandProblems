#include<iostream>
#include"8_PointTemplate.h"
using namespace std;

template <typename T>
Point<T>::Point(T x = 0, T y = 0) : xpos(x), ypos(y)
{}

template <typename T>
void Point<T>::ShowPosition() const
{
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}
