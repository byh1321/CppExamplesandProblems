#include<iostream>
using namespace std;

class Person
{
public:
	void sleep()
	{
		cout << "Sleep" << endl;
	}
};

class Student : public Person
{
public:
	void Study()
	{
		cout << "Study" << endl;
	}
};

class ParTimeStudent : public Student
{
public:
	void Work()
	{
		cout << "Work" << endl;
	}
};

void main()
{
	Person* ptr1 = new Student();
	Person* ptr2 = new ParTimeStudent();
	Student* ptr3 = new ParTimeStudent();
	ptr1->sleep();
	ptr2->sleep();
	ptr3->Study();
	delete ptr1;
	delete ptr2;
	delete ptr3;
}
