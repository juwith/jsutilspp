#include <iostream>

#include "hclass.h"

using namespace std;

void Hello::printinfo()
{
	cout << "print info val : " << this->val << ", str : " <<this->str << endl;
}


Hello::Hello(int val,const char* str)
{
	cout << "constructor" << endl;
	this->val = val;
	this->str = new char[strlen(str) + 1];
	strcpy(this->str,str);
};

Hello::~Hello()
{
	cout << "destructor" << endl;
	delete str;
};


