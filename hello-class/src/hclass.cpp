#include <iostream>

#include "hclass.h"

using namespace std;

void Hello::printinfo()
{
	cout << this->val << endl;
}

int main()
{
	Hello h(5);
	h.printinfo();

	return 0;
}
