#include <iostream>

#include "hoperator.h"

using namespace std;

int main()
{
	HeyOper h(1);
	HeyOper h2(2);
	HeyOper h3(3);

	cout << "h1 + h2 + h3" << endl;
	h = h.plus(h2.plus(h3));
	h.printinfo();

	cout << "h4 + h5 + h6" << endl;
	HeyOper h4(4);
	HeyOper h5(5);
	HeyOper h6(6);
	h4 = h4+h5+h6;
	h4.printinfo();
	
	return 0;
}

