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
	Police(Police& ref)
	{
		handcuffs = ref.handcuffs;
		if (ref.pistol > 0)
		{
			pistol = new Gun(*ref.pistol);
		}
		else
			pistol = NULL;
	}
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
	Police& operator=(Police& ref)
	{
		handcuffs = ref.handcuffs;
		if (ref.pistol > 0)
		{
			pistol = new Gun(*ref.pistol);
		}
		else
			pistol = NULL;
		return *this;
	}
	void ShowInfo()
	{
		cout << "pistol : " << pistol->Returnbnum() << endl;
		cout << "handcuffs : " << handcuffs << endl;
	}
	~Police()
	{
		delete pistol;
	}
};

Police::Police(int bnum, int bcuff) : handcuffs(bcuff)
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
	Police pman2 = pman1;
	Police pman3(0,0);
	pman3 = pman1;
	pman1.ShowInfo();
	pman2.ShowInfo();
	pman3.ShowInfo();
}