/*
*	�����̸�		:	HighCreditAccount.h
*	�ۼ���			:	������
*	������Ʈ ����	:	[2016.07.20] ���Ϲ��� 0.7
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