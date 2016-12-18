#include<iostream>
#include<cstring>
using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum)
	{
		//empty
	}
	int Returnbnum()
	{
		return bullet;
	}
	void Shot()
	{
		cout << "Bang!" << endl;
		bullet--;
	}
};

class Police : public Gun
{
private:
	int handcuffs;
public:
	Police(int bnum, int bcuff)
		: Gun(bnum), handcuffs(bcuff)
	{
		//empty
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void PrintInventory()
	{
		cout << "³²Àº ÃÑ¾Ë : " << Returnbnum() << endl;
		cout << "³²Àº ¼ö°© : " << handcuffs << endl;
	}
};

void main()
{
	Police pman(5, 3);
	pman.Shot();
	pman.PutHandcuff();
	pman.PrintInventory();
	return;
}