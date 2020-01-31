#include <iostream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector

/**
 * @file algorithm.cpp
 * @author Jusang Maeng (jusang6900@gmail.com)
 * @date 2020.01.29
 * @brief algorithm examples
 * @see http://www.cplusplus.com/reference/algorithm/
 */

using namespace std;

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

bool isOdd(int i) { return ((i%2)==1); }
int main()
{
	int myints[] = {32,71,12,45,26,80,53,33};
	vector<int> myvector(myints, myints+8);
	printVect(myvector);

	cout << "sort element where is from 4th to 1st" <<endl;
	sort(myvector.begin(), myvector.begin()+4);
	printVect(myvector);

	cout << "sort element where is from 8th to 5th" <<endl;
	sort(myvector.begin()+4, myvector.end());
	printVect(myvector);


	vector<int> vect;
	vect.push_back(20);
	vect.push_back(10);
	vect.push_back(10);
	vect.push_back(50);
	vect.push_back(30);

	cout << "new vector" << endl;
	printVect(vect);
	cout << "algorithm remove 10" <<endl;
	vect.erase(remove(vect.begin(), vect.end(), 10), vect.end());
	printVect(vect);


	vector<int> vect2;
	vect2.push_back(5);
	vect2.push_back(7);
	vect2.push_back(4);
	vect2.push_back(8);
	vect.push_back(13);
	cout << "new vector" << endl;
	printVect(vect2);
	cout << "algorithm remove odd" <<endl;
	vect2.erase(remove_if(vect2.begin(), vect2.end(), isOdd), vect2.end());
	printVect(vect2);


	int intarr[] = {7,3,4,1,2,3,4,6,7,8,9};
	int narr = sizeof(intarr)/sizeof(int);
	vector<int> vect3(intarr,intarr+narr);
	cout << "new vector" << endl;
	printVect(vect3);
	
	vector<int>::iterator low;
	//key is 5, if vector has key value, low will be 5.
	//but vector has not key value, this function will find value closer with key value. (it will be more than key value.)
	low=lower_bound(vect3.begin(), vect3.end(), 5);
	cout << "low " << *low <<endl; //it can't find key value(5). it will find 6 instead of 5.


	vector<int>::iterator findvect;
	findvect = find(vect3.begin(), vect3.end(), 8);
	cout << "find 8 : " << *findvect << endl;

	return 0;
}
