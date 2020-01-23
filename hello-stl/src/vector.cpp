#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
	vector<int> vect;
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);
	vect.push_back(4);


	printVect(vect);
	vect.pop_back();

	printVect(vect);

	cout << "vect.at(1) : " << vect.at(1) << endl;
	cout << "vect front : " << vect.front() << endl;
	cout << "vect back : " << vect.back() << endl;

	vect.insert(vect.begin(),50);
	vect.erase(vect.end()-1);
	printVect(vect);
	

	vector<int> vect2 = {11,12,13};
	vect.swap(vect2);
	printVect(vect);

	return 0;
}
