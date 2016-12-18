#include<iostream>
#include<cstring>
using namespace std;

class FriendInfo
{
private:
	char *name;
	int age;
public:
	FriendInfo(char* _name, int _age) : age(_age)
	{
		int len = strlen(_name) + 1;
		name = new char[len];
		strcpy_s(name, len, _name);
		cout << "Base class constructor worked!!" << endl;
	}
	void ShowMyFriendInfo()
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}
	~FriendInfo()
	{
		delete[]name;
		cout << "Base class destructor worked!!" << endl;
	}
};

class MyFriendDetailInfo : public FriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(char* _addr, char* _phone, char* _name, int age)
		: FriendInfo(_name, age)
	{
		int len1 = strlen(_addr) + 1;
		int len2 = strlen(_phone) + 1;
		addr = new char[len1];
		phone = new char[len2];
		strcpy_s(addr, len1, _addr);
		strcpy_s(phone, len2, _phone);
		cout << "Derived class constructor worked!!" << endl;
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "�ּ�: " << addr << endl;
		cout << "��ȭ: " << phone << endl << endl;
	}
	~MyFriendDetailInfo()
	{
		cout << "Derived class destructor worked!!" << endl;
		delete[]addr;
		delete[]phone;
	}
};

void main()
{
	MyFriendDetailInfo kim("����", "010-1234-5678", "�达", 20);
}