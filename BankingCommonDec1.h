/*
*	파일이름		:	BankingCommonDec1.h
*	작성자			:	변영훈
*	업데이트 정보	:	[2016.07.20] 파일버전 0.7
*/

#ifndef _BANKING_COMMON_H__
#define _BANKING_COMMON_H__

#include<iostream>
#include<cstring>

#define Name_Length 20
using namespace std;

enum { MAKEACCOUNT, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

enum { LEVEL_A = 1, LEVEL_B = 2, LEVEL_C = 3 };

#endif