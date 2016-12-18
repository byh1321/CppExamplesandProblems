#include<iostream>
#include<cstring>
#define Name_Length 20
using namespace std;

enum { MAKEACCOUNT, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

enum { LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};

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
	virtual void Deposit(int money)
	{
		Balance += money;
	}
	~Account()
	{
		delete[] CustomerName;
	}
};

class NormalAccount : public Account
{
private:
	int interest;
public:
	NormalAccount(int _AccountID, int _Balance, char* _CustomerName, int _interest)
		: Account(_AccountID, _Balance, _CustomerName), interest(_interest)
	{
		//empty
	}
	virtual void Deposit(int money)
	{
		Account::Deposit((int)(money*(1+interest/100)));
	}
};

class HighCreditAccount : public NormalAccount
{
private:
	int trustlevel;
public:
	HighCreditAccount(int _AccountID, int _Balance, char* _CustomerName, int _interest, int _trustlevel)
		: NormalAccount(_AccountID, _Balance, _CustomerName, _interest), trustlevel(_trustlevel)
	{
		//empty
	}
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);
		switch (trustlevel)
		{	
		case LEVEL_A:
			Account::Deposit(money * 7 / 100);
		case LEVEL_B:
			Account::Deposit(money * 4 / 100);
		case LEVEL_C:
			Account::Deposit(money * 2 / 100);
		}
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
	cout << "1. 계좌계설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택 : ";
}

void AccountHandler::MakeAccount()
{
	int acctype=0;
	int accountid;
	char customername[Name_Length];
	int balance;
	int interest;
	int trustlevel;
	int tmp = 0;

	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택 : ";
	cin >> acctype;
	if (acctype == 1)
		cout << "[보통예금계좌 개설]" << endl;
	else if (acctype == 2)
		cout << "[신용신뢰계좌 개설]" << endl;
	else
	{
		cout << "잘못 입력하셨습니다. 다시 시도해주세요." << endl;
		return;
	}
		cout << "계좌 ID : ";
	cin >> accountid;
	for (int i = 0; i < accnum; i++)
	{
		if (accountid == accary[i]->ReturnAccountID())
			tmp++;
	}
	if (tmp > 0)
	{
		cout << "동일한 ID의 계좌가 존재합니다. 다시 시도해주세요" << endl;
		return;
	}
	else
	{
		if (acctype == 1)
		{
			cout << "이 름 : ";
			cin >> customername;
			cout << "입금액 : ";
			cin >> balance;
			cout << "이자율 : ";
			cin >> interest;
			cout << endl;
			accary[accnum++] = new NormalAccount(accountid, balance, customername,interest);
		}
		else if (acctype == 2)
		{
			cout << "이 름 : ";
			cin >> customername;
			cout << "입금액 : ";
			cin >> balance;
			cout << "이자율 : ";
			cin >> interest;
			cout << "신용등급(1toA, 2toB, 3toC) : ";
			cin >> trustlevel;
			cout << endl;
			accary[accnum++] = new HighCreditAccount(accountid, balance, customername, interest, trustlevel);
		}
	}
}

void AccountHandler::Deposit()
{
	int accountid;
	int money;
	bool findacc = 0;
	cout << "[입    금]" << endl;
	cout << "계좌 ID : ";
	cin >> accountid;
	cout << "입금액 : ";
	cin >> money;
	for (int i = 0; i < accnum; i++)
	{
		if (accountid == accary[i]->ReturnAccountID())
		{
			accary[i]->Deposit(money);
			cout << "입금 완료" << endl;
			cout << "잔액 : " << accary[i]->ReturnBalance() << endl;
			findacc = 1;
		}
	}
	if (findacc == 0)
	{
		cout << "계좌를 발견하지 못했습니다. 메인메뉴로 돌아갑니다." << endl << endl;
	}
}

void AccountHandler::WithDraw()
{
	int accountid;
	int money;
	bool findacc = 0;
	cout << "[출    금]" << endl;
	cout << "계좌 ID : ";
	cin >> accountid;
	cout << "출금액 : ";
	cin >> money;
	for (int i = 0; i < accnum; i++)
	{
		if (accountid == accary[i]->ReturnAccountID())
		{
			if (money <= accary[i]->ReturnBalance())
			{
				accary[i]->WithDraw(money);
				cout << "출금 완료" << endl;
				cout << "잔액 : " << accary[i]->ReturnBalance() << endl;
			}
			else
				cout << "잔액이 모자랍니다. 메인 메뉴로 돌아갑니다" << endl << endl;
			findacc = 1;
		}
	}
	if (findacc == 0)
	{
		cout << "계좌를 발견하지 못했습니다. 메인메뉴로 돌아갑니다." << endl;
	}
}

void AccountHandler::Inquire()
{
	for (int i = 0; i < accnum; i++)
	{
		cout << "계좌 ID : " << accary[i]->ReturnAccountID() << endl;
		cout << "이   름 : " << accary[i]->ReturnCustomerName() << endl;
		cout << "잔   액 : " << accary[i]->ReturnBalance() << endl;
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