#include <iostream>
#include <deque>

/**
 * @file deque.cpp
 * @author Jusang Maeng (jusang6900@gmail.com)
 * @date 2020.01.29
 * @brief deque(double ended queue) examples
 * @see http://www.cplusplus.com/reference/deque/deque/
 */

using namespace std;

template <typename T>
static void printDq(T &dq)
{
	cout << "elements : {";
	for(deque<int>::size_type i = 0; i < dq.size(); i++)
	{
		cout << dq[i] << ", ";
	}
	cout << "}" << endl;
}

template <typename T>
static void printDq_itr(T &dq)
{
	cout << "iterator, elements : {";
	for(deque<int>::iterator itr = dq.begin(); itr != dq.end();++itr)
	{
		std::cout << *itr << ", ";
	}
	cout << "}" << endl;
}

template <typename T>
static void printDq_range(T &dq)
{
	cout << "range based loop, elements : {";
	for (int elem : dq)
	{
		cout << elem << ", ";
	}
	cout << "}" << endl;
}

int main()
{
	deque<int> dq;

	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	dq.push_back(4);

	cout << "===================print test!!" << endl;
	printDq(dq);
	printDq_itr(dq);
	printDq_range(dq);
	cout << "===================end of print test!!" << endl;

	cout << "pop front" << endl;
	dq.pop_front();
	printDq(dq);

	cout << "push front 5" << endl;
	dq.push_front(5);
	printDq(dq);

	cout << "insert 50" << endl;
	dq.insert(dq.begin(),50);
	printDq(dq);
	

	return 0;
}
