#include <iostream>
#include <list>

/**
 * @file list.cpp
 * @author Jusang Maeng (jusang6900@gmail.com)
 * @date 2020.01.29
 * @brief list examples
 * @see http://www.cplusplus.com/reference/list/list/
 */


using namespace std;

template <typename T>
static void printList_itr(list<T> &lst)
{
	cout << "iterator, elements : {";
	for(typename list<T>::iterator itr = lst.begin(); itr != lst.end();++itr)
	{
		cout << *itr << ", ";
	}
	cout << "}" << endl;
}

template <typename T>
static void printList_range(list<T> &lst)
{
	cout << "elements : {";
	for(const auto& elem : lst)
	{
		cout << elem << ", ";
	}
	cout << "}" << endl;
}

int main()
{
	list<int> lst;

	lst.push_back(4);
	lst.push_back(2);
	lst.push_back(1);
	lst.push_back(3);

	cout << "===================print test!!" << endl;
	printList_itr(lst);
	printList_range(lst);
	cout << "===================end of print test!!" << endl;

	cout << "push front" << endl;
	lst.push_front(5);
	printList_range(lst);

	cout << "pop front" << endl;
	lst.pop_front();
	printList_range(lst);

	cout << "pop back" << endl;
	lst.pop_back();
	printList_range(lst);

	cout << "sort" << endl;
	lst.sort();
	printList_range(lst);

	list<string> strLst;
	strLst.push_back("melon");
	strLst.push_back("apple");
	strLst.push_back("banana");
	strLst.push_back("Melon");
	strLst.push_back("Apple");
	strLst.push_back("Banana");

	cout << "string list" << endl;
	printList_range(strLst);

	cout << "string list sort" << endl;
	strLst.sort();
	printList_range(strLst);

	return 0;
}
