#include <iostream>
#include <string.h>

#include "hoperatorarr.h"

using namespace std;

void HeyArrOper::printinfo()
{
	cout << "print info val : " << arr << endl;
}

char& HeyArrOper::operator[](int count)
{
	return this->arr[count];
}

HeyArrOper::HeyArrOper(char* arr)
{
	//cout << "constructor" << endl;
	strcpy(this->arr,arr);
};

HeyArrOper::~HeyArrOper()
{
	//cout << "destructor" << endl;
}

