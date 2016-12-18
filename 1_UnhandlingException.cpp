#include<iostream>
using namespace std;

void main()
{
	int num1, num2;
	cout << "µÎ °³ÀÇ ¼ýÀÚ ÀÔ·Â: ";
	cin >> num1 >> num2;

	cout << "³ª´°¼ÀÀÇ ¸ò : " << num1 / num2 << endl;
	cout << "³ª¹µ¼ÀÀÇ ³ª¸ÓÁö : " << num1%num2 << endl;
}