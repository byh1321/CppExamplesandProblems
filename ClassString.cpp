#include<iostream>
#include<cstring>
using namespace std;

class String
{
private:
	char* str;
	int len;
public:
	String()
	{
		len = 0;
		str = NULL;
	}
	String(char* input)
	{
		len = strlen(input) + 1;
		str = new char[len];
		strcpy_s(str, len, input);
	}
	String(String& input) : len(input.Returnlen())
	{
		str = new char[input.Returnlen()];
		strcpy_s(str, len, input.ReturnString());
	}
	String& operator=(String& input)
	{
		str = new char[input.Returnlen()];
		len = input.Returnlen();
		strcpy_s(str, input.Returnlen(), input.ReturnString());
		return *this;
	}
	String operator+(String& input)
	{
		char* tmp=new char[input.Returnlen()+len];
		strcpy_s(tmp, len, str);
		strcat_s(tmp, input.Returnlen()+len-1, input.ReturnString());
		
		String tmpstr(tmp);
		delete[]tmp;
		return tmpstr;
	}
	String& operator+=(String& input)
	{
		char* tmp = new char[input.Returnlen() + len-1];
		strcpy_s(tmp, len, str);
		strcat_s(tmp, input.Returnlen()+len-1, input.str);

		String tmpstr(tmp);
		delete[]tmp;
		return tmpstr;
	}
	bool operator==(String& input)
	{
		return strcmp(str, input.ReturnString()) ? false : true;
	}
	char* ReturnString() const
	{
		return str;
	}
	int Returnlen() const
	{
		return len;
	}
	friend ostream& operator<<(ostream& os, String& output)
	{
		os << output.ReturnString();
		return os;
	}
	friend istream& operator>>(istream& is, String& input)
	{
		char str[100];
		is >> str;
		input = String(str);
		return is;
	}
	~String()
	{
		if(str!=NULL)
			delete[] str;
	}
};

void main()
{
	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	String str4;
	cout << "문자열 입력 : ";
	cin >> str4;
	cout << "입력한 문자열 : " << str4 << endl;
}