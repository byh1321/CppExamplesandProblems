/*
*	�����̸�		:	NormalAccount.h
*	�ۼ���			:	������
*	������Ʈ ����	:	[2016.07.20] ���Ϲ��� 0.7
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