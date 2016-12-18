#include<iostream>
#include<cstring>
#define Name_Length 20
using namespace std;

enum { MAKEACCOUNT, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	int AccountID;
	int Balance;
	char* CustomerName;
public:
	Account(int _AccountID, int _Balance, char* _CustomerName)
		: AccountID(_AccountID), Balance(_Balance)
	{
		CustomerName = new char[strlen(_CustomerName) + 1];
		strcpy_s(CustomerName, strlen(_CustomerName) + 1, _CustomerName);
	}
	Account(const Account& copy) : AccountID(copy.AccountID), Balance(copy.Balance)
	{
		int len = strlen(copy.CustomerName) + 1;
		CustomerName = new char[len + 1];
		strcpy_s(CustomerName, len, copy.CustomerName);
	}
	int ReturnAccountID() const
	{
		return AccountID;
	}
	int ReturnBalance() const
	{
		return Balance;
	}
	char* ReturnCustomerName() const
	{
		return CustomerName;
	}
	void WithDraw(int money)
	{
		Balance -= money;
	}
	void Deposit(int money)
	{
		Balance += money;
	}
	~Account()
	{
		delete[] CustomerName;
	}
};

class AccountHandler
{
private:
	Account* accary[100];
	int accnum;
public:
	AccountHandler();
	void PrintMenu();
	void MakeAccount();
	void Deposit();
	void WithDraw();
	void Inquire();
	~AccountHandler();
};

AccountHandler::AccountHandler() : accnum(0)
{
	//empty
}

void AccountHandler::PrintMenu()
{
	cout << "-----Munu------" << endl;
	cout << "1. ���°輳" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "���� : ";
}

void AccountHandler::MakeAccount()
{
	int accountid;
	char customername[Name_Length];
	int balance;
	int tmp=0;

	cout << "[���°輳]" << endl;
	cout << "ID : ";
	cin >> accountid;
	for (int i = 0; i < accnum; i++)
	{
		if (accountid == accary[i]->ReturnAccountID())
			tmp++;
	}
	if(tmp>0)
		cout << "������ ID�� ���°� �����մϴ�. �ٽ� �õ����ּ���" << endl;
	else
	{
		cout << "�� �� : ";
		cin >> customername;
		cout << "�Աݾ� : ";
		cin >> balance;
		cout << endl;
		accary[accnum++] = new Account(accountid, balance, customername);
	}
}

void AccountHandler::Deposit()
{
	int accountid;
	int money;
	bool findacc = 0;
	cout << "[��    ��]" << endl;
	cout << "���� ID : ";
	cin >> accountid;
	cout << "�Աݾ� : ";
	cin >> money;
	for (int i = 0; i < accnum; i++)
	{
		if (accountid == accary[i]->ReturnAccountID())
		{
			accary[i]->Deposit(money);
			cout << "�Ա� �Ϸ�" << endl;
			cout << "�ܾ� : " << accary[i]->ReturnBalance() << endl;
			findacc = 1;
		}
	}
	if (findacc == 0)
	{
		cout << "���¸� �߰����� ���߽��ϴ�. ���θ޴��� ���ư��ϴ�." << endl << endl;
	}
}

void AccountHandler::WithDraw()
{
	int accountid;
	int money;
	bool findacc = 0;
	cout << "[��    ��]" << endl;
	cout << "���� ID : ";
	cin >> accountid;
	cout << "��ݾ� : ";
	cin >> money;
	for (int i = 0; i < accnum; i++)
	{
		if (accountid == accary[i]->ReturnAccountID())
		{
			if (money <= accary[i]->ReturnBalance())
			{
				accary[i]->WithDraw(money);
				cout << "��� �Ϸ�" << endl;
				cout << "�ܾ� : " << accary[i]->ReturnBalance() << endl;
			}
			else
				cout << "�ܾ��� ���ڶ��ϴ�. ���� �޴��� ���ư��ϴ�" << endl << endl;
			findacc = 1;
		}
	}
	if (findacc == 0)
	{
		cout << "���¸� �߰����� ���߽��ϴ�. ���θ޴��� ���ư��ϴ�." << endl;
	}
}

void AccountHandler::Inquire()
{
	for (int i = 0; i < accnum; i++)
	{
		cout << "���� ID : " << accary[i]->ReturnAccountID() << endl;
		cout << "��   �� : " << accary[i]->ReturnCustomerName() << endl;
		cout << "��   �� : " << accary[i]->ReturnBalance() << endl;
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accnum; i++)
	{
		delete accary[i];
	}
}

int main()
{
	int choicemenu = 0;
	AccountHandler AccH;
	while (1)
	{
		AccH.PrintMenu();
		cin >> choicemenu;
		switch (choicemenu - 1)
		{
		case MAKEACCOUNT:
			AccH.MakeAccount();
			break;
		case DEPOSIT:
			AccH.Deposit();
			break;
		case WITHDRAW:
			AccH.WithDraw();
			break;
		case INQUIRE:
			AccH.Inquire();
			break;
		case EXIT:
			return 0;
		}
	}
}