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
template <typename T>
static void printVect(T vect)
{
	cout << "print data of vector" << endl;
	for(vector<int>::size_type i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << endl;
	}
	cout << "end data of vector" << endl;
}

template <typename T>
static void printVect_itr(T vect)
{
	cout << "print data of vector by iterator" << endl;
	for(vector<int>::iterator itr = vect.begin(); itr != vect.end();++itr)
	{
		std::cout << *itr << std::endl;
	}
	cout << "end data of vector" << endl;
}

template <typename T>
static void printVect_range(T vect)
{
	cout << "print data of vector by range based loop" << endl;

	//user also can use below style, but it will be a copy of the current array element
	// for (int elem : vect)

	//read only :
	// for(const int &elem : vect)
	for(int &elem : vect)
	{
		cout << elem << endl;
		//the factor assign in every for loop. (elem = vec[i])
	}
	cout << "end data of vector" << endl;
}


int main()
{
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

	// vector is {1,2,3,4}
	printVect(vect); 
	vect.pop_back(); // pop : 4 , vector is {1,2,3}

	printVect(vect);

	cout << "vect.at(1) : " << vect.at(1) << endl; // vector is {1,2,3}, at(0) 1, at(1) 2, ...
	cout << "vect front : " << vect.front() << endl; // vector is {1,2,3}, front() is 1
	cout << "vect back : " << vect.back() << endl; // vector is {1,2,3}, back() is 3

	vect.insert(vect.begin(),50); // insert 50, vector is {50, 1,2,3}
	vect.erase(vect.end()-1); // earse last, vector is {50, 1,2}
	printVect(vect);
	

	vector<int> vect2 = {11,12,13}; // vect is {50,1,2}, vect2 is {11,12,13}
	vect.swap(vect2); // vect is {11,12,13}, vect2 is {50,1,2}
	printVect(vect);
	printVect(vect2);

	return 0;
}
