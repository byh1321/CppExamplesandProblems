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
		cout << "BBang!" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff);
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot()
	{
		if (pistol == NULL)
		{
			cout << "Hut BBANG!" << endl;
		}
		else
			pistol->Shot();
	}
	~Police()
	{
		delete pistol;
	}
};

Police::Police(int bnum, int bcuff=1)
{
	if (bnum > 0)
	{
		pistol = new Gun(bnum);
	}
	else
		pistol = NULL;
	return;
}

void main()
{
	Police pman1(5, 3);
	pman1.Shot();
	pman1.PutHandcuff();

	Police pman2(0, 3);
	pman2.Shot();
	pman2.PutHandcuff();

	Police pman3(3);
	pman3.Shot();
	pman3.PutHandcuff();
}