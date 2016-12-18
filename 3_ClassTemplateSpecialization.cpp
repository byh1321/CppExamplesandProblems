#include<iostream>
#include<cstring>
using namespace std;

template <class T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0);
	void ShowPosition() const;
};

template <class T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y)
{}

template <class T>
void Point<T>::ShowPosition() const
{
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}

template <class T>
class SimpleDataWrapper
{
private:
	T mdata;
public:
	SimpleDataWrapper(T data) : mdata(data)
	{	}
	void ShowDataInfo(void)
	{
		cout << "Data: " << mdata << endl;
	}
};

template <>
class SimpleDataWrapper <char*>
{
private:
	char* mdata;
public:
	SimpleDataWrapper(char* data)
	{
		mdata = new char[strlen(data) + 1];
		strcpy_s(mdata, strlen(data) + 1, data);
	}
	void ShowDataInfo(void)
	{
		cout << "String : " << mdata << endl;
		cout << "Length : " << strlen(mdata) << endl;
	}
	~SimpleDataWrapper()
	{
		delete[] mdata;
	}
};

template <>
class SimpleDataWrapper <Point<int>>
{
private:
	Point<int> mdata;
public:
	SimpleDataWrapper(int x, int y) : mdata(x, y)
	{}
	void ShowDataInfo()
	{
		mdata.ShowPosition();
	}
};

void main()
{
	SimpleDataWrapper<int> iwrap(170);
	iwrap.ShowDataInfo();
	SimpleDataWrapper<char*> swrap("Class Template Specialization");
	swrap.ShowDataInfo();
	SimpleDataWrapper<Point<int>> poswrap(3, 7);
	poswrap.ShowDataInfo();
}