/*
*	파일이름		:	AccountHandler.h
*	작성자			:	변영훈
*	업데이트 정보	:	[2016.08.02] 파일버전 0.8
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