/*
*	파일이름		:	HighCreditAccount.h
*	작성자			:	변영훈
*	업데이트 정보	:	[2016.07.20] 파일버전 0.7
*/

#ifndef _HIGH_CREDIT_ACCOUNT_H__
#define _HIGH_CREDIT_ACCOUNT_H__

class HighCreditAccount : public NormalAccount
{
private:
	int trustlevel;
public:
	HighCreditAccount(int _AccountID, int _Balance, char* _CustomerName, double _interest, int _trustlevel)
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
			Account::Deposit(money * 7/100);
			break;
		case LEVEL_B:
			Account::Deposit(money * 4 / 100);
			break;
		case LEVEL_C:
			Account::Deposit(money * 2 / 100);
			break;
		}
	}
};

#endif