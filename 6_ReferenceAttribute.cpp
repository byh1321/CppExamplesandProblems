#include<iostream>
using namespace std;

class First
{
public: 
	void FirstFunc() const
	{
		cout << "FirstFunc()" << endl;
	}
	virtual void SimpleFunc() const
	{
		cout << "First's SimpleFUnc()" << endl;
	}
};

class Second : public First
{
public:
	void SecondFunc() const
	{
		cout << "SecondFunc()" << endl;
	}
	virtual void SimpleFunc() const
	{
		cout << "Second's SimpleFUnc()" << endl;
	}
};

class Third : public Second
{
public:
	void ThirdFunc() const
	{
		cout << "ThirdFunc()" << endl;
	}
	virtual void SimpleFunc() const
	{
		cout << "Third's SimpleFUnc()" << endl;
	}
};

void main()
{
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();
	
	Second &sref = obj;
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();

	First &fref = obj;
	fref.FirstFunc();
	sref.SimpleFunc();
	return;
}

