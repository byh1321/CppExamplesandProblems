/*
*	�����̸�		:	AccountHandler.cpp
*	�ۼ���			:	������
*	������Ʈ ����	:	[2016.07.20] ���Ϲ��� 0.7
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
	cout << "1. ���°輳" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "���� : ";
}

void AccountHandler::MakeAccount()
{
	int acctype = 0;
	int tmp = 0;
	int accountid;

	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "���� : ";
	cin >> acctype;
	if (acctype == 1)
		cout << "[���뿹�ݰ��� ����]" << endl;
	else if (acctype == 2)
		cout << "[�ſ�ŷڰ��� ����]" << endl;
	else
	{
		cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �õ����ּ���." << endl;
		return;
	}
	cout << "���� ID : ";
	cin >> accountid;
	for (int i = 0; i < accnum; i++)
	{
		if (accountid == accary[i]->ReturnAccountID())
			tmp++;
	}
	if (tmp > 0)
	{
		cout << "������ ID�� ���°� �����մϴ�. �ٽ� �õ����ּ���" << endl;
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

	cout << "�� �� : ";
	cin >> customername;
	cout << "�Աݾ� : ";
	cin >> balance;
	cout << "������ : ";
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

	cout << "�� �� : ";
	cin >> customername;
	cout << "�Աݾ� : ";
	cin >> balance;
	cout << "������ : ";
	cin >> interest;
	cout << "�ſ���(1toA, 2toB, 3toC) : ";
	cin >> trustlevel;
	cout << endl;
	accary[accnum++] = new HighCreditAccount(accountid, balance, customername, interest, trustlevel);
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
