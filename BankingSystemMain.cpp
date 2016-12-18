/*
*	파일이름		:	BankingSystemMain.cpp
*	작성자			:	변영훈
*	업데이트 정보	:	[2016.07.20] 파일버전 0.7
*/
#include"BankingCommonDec1.h"
#include"AccountHandler.h"

int main()
{
	int choicemenu = 0;
	AccountHandler AccH;
	while (1)
	{
		AccH.PrintMenu();
		cin >> choicemenu;
		switch (choicemenu - 1)
		{
		case MAKEACCOUNT:
			AccH.MakeAccount();
			break;
		case DEPOSIT:
			AccH.Deposit();
			break;
		case WITHDRAW:
			AccH.WithDraw();
			break;
		case INQUIRE:
			AccH.Inquire();
			break;
		case EXIT:
			return 0;
		}
	}
}