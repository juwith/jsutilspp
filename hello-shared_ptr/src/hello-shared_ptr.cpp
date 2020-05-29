#include <iostream>
#include <memory>

using namespace std;

int main()
{
	cout << "create shared_ptr p1 for value '10'" << endl << endl;
	shared_ptr<int> p1(new int(10));

	std::shared_ptr<int>::element_type val = *p1; // you can also use ' *p1.get() '
	cout << "p1 address is : " << p1.get() << ", p1 val is : " << val << endl;

	cout << "number of referring : " << p1.use_count() << endl << endl;

	cout << "create shared_ptr p2, p2 uses p1" << endl;
	shared_ptr<int> p2(p1);
	cout << "number of referring : " << p1.use_count() << endl << endl;

	cout << "reset p1 for value '20'" << endl;
	p1.reset(new int(20));
	cout << "p1 address is : " << p1.get() << ", p1 val is : " << *p1.get() << endl;

	//you don't have to free memory.
	return 0;
}
