#include<iostream>
#include<cstring>
using namespace std;

class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(char* _title, char* _isbn, int _price) : price(_price)
	{
		title = new char[strlen(_title) + 1];
		isbn = new char[strlen(_isbn) + 1];
		strcpy_s(title, strlen(_title) + 1, _title);
		strcpy_s(isbn, strlen(_isbn) + 1, _isbn);
	}
	void ShowBookInfo()
	{
		cout << "책 제목\t: " << title << endl;
		cout << "isbn\t: " << isbn << endl;
		cout << "책 제목\t: " << price << endl;
	}
	char* Returntitle()
	{
		return title;
	}
	char* Returnisbn()
	{
		return isbn;
	}
	int Returnprice()
	{
		return price;
	}
	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book
{
private:
	char* DRMKey;
public:
	EBook(char* _title, char* _isbn, int _price, char* _DRMKey)
		: Book(_title, _isbn, _price)
	{
		DRMKey = new char[strlen(_DRMKey) + 1];
		strcpy_s(DRMKey, strlen(_DRMKey) + 1, _DRMKey);
	}
	void ShowEBookInfo()
	{
		cout << "책 제목\t: " << Returntitle() << endl;
		cout << "isbn\t: " << Returnisbn() << endl;
		cout << "가격\t: " << Returnprice() << endl;
		cout << "DRMKey\t: " << DRMKey << endl;
	}
	~EBook()
	{
		delete[] DRMKey;
	}
};

void main()
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i9kiw");
	ebook.ShowEBookInfo();
	return;
}