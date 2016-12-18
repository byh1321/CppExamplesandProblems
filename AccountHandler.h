/*
*	�����̸�		:	AccountHandler.h
*	�ۼ���			:	������
*	������Ʈ ����	:	[2016.08.02] ���Ϲ��� 0.8
*/

#ifndef _ACCOUNT_HANDLER_H__
#define _ACCOUNT_HANDLER_H__

#include"Account.h"

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
protected:
	void MakeNormalAccount(int accid);
	void MakeCreditAccount(int accid);
};
#endif