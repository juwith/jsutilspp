#include <iostream>
#include <string.h>

#include "hoperator.h"

using namespace std;

void HeyOper::printinfo()
{
	cout << "print info val : " << val << endl;
}

HeyOper HeyOper::plus(const HeyOper& obj)
{
	HeyOper temp(val + obj.val);
	return temp;
}

HeyOper HeyOper::operator+(const HeyOper& obj)
{
	HeyOper temp(val + obj.val);
	return temp;
}

HeyOper& HeyOper::operator+=(const HeyOper& obj)
{
	(*this) = (*this) + obj;
	return *this;
}

HeyOper::HeyOper(int val)
{
	//cout << "constructor" << endl;
	this->val = val;
};

HeyOper::~HeyOper()
{
	//cout << "destructor" << endl;
}

////////////////////

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

