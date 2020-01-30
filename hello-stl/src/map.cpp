#include <iostream>
#include <map>

/**
 * @file map.cpp
 * @author Jusang Maeng (jusang6900@gmail.com)
 * @date 2020.01.30
 * @brief map examples
 * @see http://www.cplusplus.com/reference/map/map/
 * http://www.cplusplus.com/reference/utility/pair/
 */

using namespace std;

template <typename T1, typename T2>
static void printMap_itr(map<T1,T2> &map)
{
	cout << "iterator map : {" << endl;
	for(typename map<T1,T2>::iterator itr = map.begin(); itr != map.end(); ++itr)
	{
		cout << itr->first << ", " << itr->second << endl;
	}
	cout << "}" << endl;
}


template <typename T1, typename T2>
static void printMap_range(map<T1,T2> &map)
{
	cout << "map : {" << endl;
	for(const auto& elem : map)
	{
		cout << elem.first << ", " << elem.second << endl;
	}
	cout << "}" << endl;
}


int main()
{
	map<char,int> mp;

	//these are same way.
	mp.insert(pair<char, int>('d', 4));
	mp.insert(pair<char, int>('b', 2));
	mp['c'] = 3;
	mp['a'] = 1;
	mp['e'] = 5;

	cout << "===================print test!!" << endl;
	printMap_itr(mp);
	printMap_range(mp);
	cout << "===================end of print test!!" << endl;

	cout << "what is 'a' value? " << mp['a'] << endl;

	map<string,int> mp2;
	mp2.insert(pair<string, int>("banana", 1));
	mp2.insert(pair<string, int>("apple", 2));
	mp2["melon"] = 3;
	mp2["pineapple"] = 4;

	printMap_range(mp2);

	cout << "what is 'apple' value? " << mp2["apple"] << endl;


	return 0;
}
