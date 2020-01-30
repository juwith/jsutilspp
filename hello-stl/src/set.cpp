#include <iostream>
#include <set>

/**
 * @file set.cpp
 * @author Jusang Maeng (jusang6900@gmail.com)
 * @date 2020.01.30
 * @brief set examples
 * @see http://www.cplusplus.com/reference/set/set/
 */

using namespace std;

template <typename T>
static void printSet_itr(set<T> &s)
{
	cout << "iterator, elements : {";
	for(typename set<T>::iterator itr = s.begin(); itr != s.end();++itr)
	{
		cout << *itr << ", ";
	}
	cout << "}" << endl;
}

template <typename T>
static void printSet_range(set<T> &s)
{
	cout << "elements : {";
	for (const auto& elem : s)
	{
		cout << elem << ", ";
	}
	cout << "}" << endl;
}

int main()
{
	set<int> si;

	si.insert(1);
	si.insert(5);
	si.insert(3);
	si.insert(2);
	si.insert(4);

	cout << "===================print test!!" << endl;
	printSet_itr(si);
	printSet_range(si);
	cout << "===================end of print test!!" << endl;

	cout<< "find element! '4'" << endl;
	set<int>::iterator itr = si.find(4);
	if(itr != si.end())
	{
		cout << "success to find element :" << *itr << endl;
	}
	else
	{
		cout << "fail to find element" << endl;
	}


	cout<< "find element! '10'" << endl;
	itr = si.find(10);
	if(itr != si.end())
	{
		cout << "success to find element" << *itr << endl;
	}
	else
	{
		cout << "fail to find element" << endl;
	}

	set<string> ss;

	ss.insert("melon");
	ss.insert("apple");
	ss.insert("banana");
	printSet_range(ss);

	cout<< "find element! 'melon'" << endl;
	set<string>::iterator itrs = ss.find("melon");
	if(itrs != ss.end())
	{
		cout << "success to find element : " << *itrs << endl;
	}
	else
	{
		cout << "fail to find element" << endl;
	}


	return 0;
}
