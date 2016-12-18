//C��� ǥ�� ���̺귯�� �Լ� ���̵�
//erron_t  strcat_s ( char * dest,size_t size, const char * source ); ���ڿ��� ���ϴ� �Լ�
//���ڿ��� ���� �Ŀ� ���� ���ڿ� ���

#include <assert.h>
#include <string.h>
#include <stdio.h>

void ehstrcat_s(char *dest, size_t size, const char *source)
{
	int len = strlen(dest);//dest ���ڿ� ���� ���
	assert(size > (len + strlen(source)));//size�� dest ���ڿ� ���� + source ���ڿ� ���̺��� Ŀ�� ��
	strcpy_s(dest + len, size - len, source);//dest+len ��ġ�� source ���ڿ� ����    
}
int main(void)
{
	char stra[100] = "12345678";
	char strb[10] = "9";
	char strc[100] = "1234";
	char strd[10] = "abcd";

	//strcat �Լ� �̿�
	printf("%s + %s =", stra, strb);
	strcat_s(stra, 10, strb);
	printf("%s\n", stra);

	//ehstrcat �Լ� �̿�
	printf("%s + %s =", strc, strd);
	ehstrcat_s(strc, sizeof(strc), strd);
	printf("%s\n", strc);
	return 0;
}