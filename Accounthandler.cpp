/*
*	파일이름		:	AccountHandler.cpp
*	작성자			:	변영훈
*	업데이트 정보	:	[2016.07.20] 파일버전 0.7
*/
#include"AccountHandler.h"
#include"BankingCommonDec1.h"
#include"NormalAccount.h"
#include"HighCreditAccount.h"
#include"Account.h"
#include"Accountarray.h"

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
	int acctype = 0;
	int tmp = 0;
	int accountid;

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
			MakeNormalAccount(accountid);
		}
		else if (acctype == 2)
		{
			MakeCreditAccount(accountid);
		}
	}
}

void AccountHandler::MakeNormalAccount(int accid)
{
	int accountid = accid;
	char customername[Name_Length];
	int balance;
	int interest;

	cout << "이 름 : ";
	cin >> customername;
	cout << "입금액 : ";
	cin >> balance;
	cout << "이자율 : ";
	cin >> interest;
	cout << endl;
	accary[accnum++] = new NormalAccount(accountid, balance, customername, interest);
}

void AccountHandler::MakeCreditAccount(int accid)
{
	int accountid = accid;
	char customername[Name_Length];
	int balance;
	int interest;
	int trustlevel;

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
