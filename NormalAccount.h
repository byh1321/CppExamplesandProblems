/*
*	파일이름		:	NormalAccount.h
*	작성자			:	변영훈
*	업데이트 정보	:	[2016.07.20] 파일버전 0.7
*/
#ifndef _NORMAL_ACCOUNT_H__
#define _NORMAL_ACCOUNT_H__

class NormalAccount : public Account
{
private:
	double interest;
public:
	NormalAccount(int _AccountID, int _Balance, char* _CustomerName, double _interest)
		: Account(_AccountID, _Balance, _CustomerName), interest(_interest)
	{
		//empty
	}
	virtual void Deposit(int money)
	{
		Account::Deposit((int)(money*(1 + interest/100)));
	}
};

#endif