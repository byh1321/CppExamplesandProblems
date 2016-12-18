#include<iostream>
#include<cstring>
using namespace std;

class Person
{
private:
	char *name;
	int age;
public:
	Person(char *myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
	}
	Person& operator=(const Person &copy)
	{
		delete[] name;
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy_s(name, len, copy.name);
		age = copy.age;
		return *this;
	}
	/*Person(Person &copy)
	{
		//delete[] name;
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy_s(name, len, copy.name);
		age = copy.age;
	}*/

	//	위 방식은 생성할 때에만 사용 가능
	
	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	~Person()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};

void main()
{
	Person man1("Lee dong woo", 29);
	//Person man2(man1);
	Person man2("Yoon Ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
}