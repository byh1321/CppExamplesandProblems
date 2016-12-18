#include<iostream>
using namespace std;

template <class T1, class T2>
void ShowData(double num)
{
	cout << (T1)num << ", " << (T2)num << endl;
}

void main()
{
	ShowData<char, int>(65);
	ShowData<char, int>(67);
	ShowData<char, int>(68.9);
	ShowData<short, int>(69.2);
	ShowData<short, int>(70.4);
}