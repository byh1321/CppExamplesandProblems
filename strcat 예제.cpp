//C언어 표준 라이브러리 함수 가이드
//erron_t  strcat_s ( char * dest,size_t size, const char * source ); 문자열을 합하는 함수
//문자열을 합한 후에 합한 문자열 출력

#include <assert.h>
#include <string.h>
#include <stdio.h>

void ehstrcat_s(char *dest, size_t size, const char *source)
{
	int len = strlen(dest);//dest 문자열 길이 계산
	assert(size > (len + strlen(source)));//size는 dest 문자열 길이 + source 문자열 길이보다 커야 함
	strcpy_s(dest + len, size - len, source);//dest+len 위치에 source 문자열 복사    
}
int main(void)
{
	char stra[100] = "12345678";
	char strb[10] = "9";
	char strc[100] = "1234";
	char strd[10] = "abcd";

	//strcat 함수 이용
	printf("%s + %s =", stra, strb);
	strcat_s(stra, 10, strb);
	printf("%s\n", stra);

	//ehstrcat 함수 이용
	printf("%s + %s =", strc, strd);
	ehstrcat_s(strc, sizeof(strc), strd);
	printf("%s\n", strc);
	return 0;
}