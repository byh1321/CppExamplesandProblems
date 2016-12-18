/*
*	파일이름		:	Account.cpp
*	작성자			:	변영훈
*	업데이트 정보	:	[2016.08.04] 파일버전 0.8
*/
#include"Account.h"
#include"BankingCommonDec1.h"

Account::Account(int _AccountID, int _Balance, char* _CustomerName)
	: AccountID(_AccountID), Balance(_Balance)
{
	CustomerName = new char[strlen(_CustomerName) + 1];
	strcpy_s(CustomerName, strlen(_CustomerName) + 1, _CustomerName);
}
Account::Account(const Account& copy) : AccountID(copy.AccountID), Balance(copy.Balance)
{
	int len = strlen(copy.CustomerName) + 1;
	CustomerName = new char[len + 1];
	strcpy_s(CustomerName, len, copy.CustomerName);
}
int Account::ReturnAccountID() const
{
	return AccountID;
}
int Account::ReturnBalance() const
{
	return Balance;
}
Account& Account::operator=(const Account& ref)
{
	AccountID = ref.AccountID;
	Balance = ref.Balance;
	delete CustomerName;
	CustomerName = new char[strlen(ref.CustomerName) + 1];
	strcpy_s(CustomerName, strlen(ref.CustomerName) + 1, ref.CustomerName);
	return *this;
}
char* Account::ReturnCustomerName() const
{
	return CustomerName;
}
void Account::WithDraw(int money)
{
	Balance -= money;
}
void Account::Deposit(int money)
{
	Balance += money;
}
Account::~Account()
{
	delete[] CustomerName;
}