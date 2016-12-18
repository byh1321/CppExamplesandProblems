#include<iostream>
using namespace std;

class Data
{
private:
	int data;
public:
	Data(int num) : data(num)
	{
		//empty
	}
	void ShowData() const
	{
		cout << "Data : " << data << endl;
	}
	void Add(int num)
	{
		data += num;
	}
};

void main()
{
	Data obj(15);
	obj.Add(17);
	obj.ShowData();
}