#include<iostream>
using namespace std;

class BaseOne
{
public:
	void SimpleFuncOne()
	{
		cout << "BaseOne" << endl;
	}
};

class BaseTwo
{
public:
	void SimpleFuncTwo()
	{
		cout << "BaseTwo" << endl;
	}
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
	void ComplexFunc()
	{
		SimpleFuncOne();
		SimpleFuncTwo();
	}
};

void main()
{
	MultiDerived mdr;
	mdr.ComplexFunc();
}