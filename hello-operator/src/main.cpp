#include <iostream>

#include "hoperator.h"
#include "hoperatorarr.h"


using namespace std;

int main()
{
	HeyOper h1(1);
	HeyOper h2(2);
	HeyOper h3(3);

	cout << "h1 + h2 + h3" << endl;
	h1 = h1.plus(h2.plus(h3));
	h1.printinfo();

	cout << "h4 + h5 + h6" << endl;
	HeyOper h4(4);
	HeyOper h5(5);
	HeyOper h6(6);
	h4 = h4+h5+h6;
	h4.printinfo();

	cout << "ph1 + ph2" << endl;
	HeyOper* ph1 = new HeyOper(7);
	HeyOper* ph2 = new HeyOper(8);
	*ph1 = *ph1 + *ph2;
	ph1->printinfo();
	delete ph1;
	delete ph2;

	cout << "h7 + h8" << endl;
	HeyOper h7(7);
	HeyOper h8(8);
	h7 += h8;
	h7.printinfo();

//////
	HeyArrOper ha1((char*)"aello");
	ha1.printinfo();
	cout << "operation arr[0]" << endl;
	ha1[0] = 'h';
	ha1.printinfo();

	return 0;
}

