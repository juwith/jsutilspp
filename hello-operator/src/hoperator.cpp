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

