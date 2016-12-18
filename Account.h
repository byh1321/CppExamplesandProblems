/*
*	파일이름		:	Account.h
*	작성자			:	변영훈
*	업데이트 정보	:	[2016.08.04] 파일버전 0.8
*/
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int AccountID;
	int Balance;
	char* CustomerName;
public:
	Account(int _AccountID, int _Balance, char* _CustomerName);
	Account(const Account& copy);
	int ReturnAccountID() const;
	int ReturnBalance() const;
	char* ReturnCustomerName() const;
	Account& operator=(const Account& ref);
	void WithDraw(int money);
	virtual void Deposit(int money);
	~Account();
};
#endif