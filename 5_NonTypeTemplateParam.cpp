#include<iostream>
using namespace std;

template <class T, int len>
class SimpleArray
{
private:
	T arr[len];
public:

	T& operator[] (int idx)
	{
		return arr[idx];
	}
	SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref)
	{
		for (int i = 0; i < len; i++)
			arr[i] = ref.arr[i];
		return *this;
	}
};

void main()
{
	
}