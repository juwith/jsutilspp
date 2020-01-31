#include <iostream>
#include <vector>

/**
 * @file vector.cpp
 * @author Jusang Maeng (jusang6900@gmail.com)
 * @date 2020.01.29
 * @brief vector examples
 * @see http://www.cplusplus.com/reference/vector/vector/
 */

using namespace std;

//three function below will same work.
//printVect(T &vect) is also possible, but memory will copy every using.
//that's why use '&(address)'
template <typename T>
static void printVect(vector<T> &vect)
{
	cout << "elements : {";
	for(typename vector<T>::size_type i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << ", ";
	}
	cout << "}" << endl;
}

template <typename T>
static void printVect_itr(vector<T> &vect)
{
	cout << "iterator, elements : {";
	for(typename vector<T>::iterator itr = vect.begin(); itr != vect.end();++itr)
	{
		cout << *itr << ", ";
	}
	cout << "}" << endl;
}

template <typename T>
static void printVect_range(vector<T> &vect)
{
	cout << "range based loop, elements : {";

	//user also can use below style, but it will be a copy of the current array element
	// for (int elem : vect)

	//read only :
	// for(const auto &elem : vect)
	for(const auto &elem : vect)
	{
		cout << elem << ", ";
		//the factor assign in every for loop. (elem = vec[i])
	}
	cout << "}" << endl;
}


int main()
{
	int myiarr[] = {5,3,2,6,7,9};
	vector<int> first(myiarr, myiarr+3); // 0~2 array, {5,3,2}
	printVect(first);

	vector<int> vect;
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);
	vect.push_back(4);

	cout << "===================print test!!" << endl;
	printVect(vect);
	printVect_itr(vect);
	printVect_range(vect);
	cout << "===================end of print test!!" << endl;

	cout << "pop back" << endl;
	vect.pop_back(); // pop : 4 , vector is {1,2,3}
	printVect(vect);

	cout << "vect.at(1) : " << vect.at(1) << endl; // vector is {1,2,3}, at(0) 1, at(1) 2, ...
	cout << "vect front : " << vect.front() << endl; // vector is {1,2,3}, front() is 1
	cout << "vect back : " << vect.back() << endl; // vector is {1,2,3}, back() is 3

	cout << "insert 50 at first" << endl;
	vect.insert(vect.begin(),50); // insert 50, vector is {50, 1,2,3}
	printVect(vect);
	cout << "erase end" << endl;
	vect.erase(vect.end()-1); // earse last, vector is {50, 1,2}
	printVect(vect);
	
	cout << "swap with 11,12,13" << endl;
	vector<int> vect2 = {11,12,13}; // vect is {50,1,2}, vect2 is {11,12,13}
	vect.swap(vect2); // vect is {11,12,13}, vect2 is {50,1,2}

	cout << "swaped elements";
	printVect(vect);
	cout << "original elements";
	printVect(vect2);

	return 0;
}
