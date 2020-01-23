#include <iostream>

using namespace std;

/**
 * example template val
 */
template<int i>
struct C
{
	enum { RES = i };
};

/**
 * example template class
 */
template <typename T>
class MyData
{
	T data;

public:
	MyData() {};
	MyData(T data) { this->data = data; };
	void setData(T data) { this->data = data; }
	T getData()	{	return data; }
	void printData();
};

template <typename T>
void MyData<T>::printData()
{
	cout << "your data is : " << this->data << endl;
}

/**
 * example variadic template function
 */
template <typename T>
void print(T arg)
{
	cout << arg << endl;
}

template <typename T, typename... Types>
void print(T arg, Types... args)
{
	cout << arg;
	print(args ...);
}

int main()
{
	cout << "C<2> is " << C<2>::RES << endl;

	cout << "heap class" << endl;
	MyData<int>* pMyd = new MyData<int>(8);
	pMyd->printData();
	cout << "set data from 8 to 5" << endl;
	pMyd->setData(5);
	pMyd->printData();
	delete pMyd;

	cout << endl;

	cout << "stack class" << endl;
	MyData<char> myd = MyData<char>();
	myd.setData('c');
	myd.printData();
	cout << "get data : " << myd.getData() << endl;

	string str("abc");
	print(str,123,"test");

}
