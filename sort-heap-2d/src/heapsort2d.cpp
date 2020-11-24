#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class MaxHeap
{
	vector<pair<int, T>> array;

public:
	MaxHeap() {}
	void insert(int x, T item)
	{
		array.push_back(pair<int, T>(x, item));
		int target = array.size();
		while( target > 1 && x > array[(target/2)-1].first) {
			array[target-1].first = array[(target/2)-1].first;
			array[target-1].second = array[(target/2)-1].second;
			//cout << "target = " << target << ", target/2 = " << target/2 << endl;
			target /= 2;
			//cout << "target:" << target << endl;
		}
		//cout << "======end target========target:" << target << endl;
		array[target-1].first = x;
		array[target-1].second = item;
	}

	pair<int, T> popMax()
	{
		//max is always first factor by heapify(insert)
		pair<int, T> maxpair(array.front().first,array.front().second);

		//end factor moves to first factor
		array.front().first = array.back().first;
		array.front().second = array.back().second;
		array.pop_back();

		//heapify
		int x = array.front().first;
		T xitem = array.front().second;
		int parent=1, child=2;
		int arrSize = array.size();
		while(child <= arrSize) {
			if(array[child-1].first < array[child].first) {
				child++;
			}
			if(x >= array[child-1].first) {
				break;
			}
			array[parent-1].first = array[child-1].first;
			array[parent-1].second = array[child-1].second;
			parent=child;
			child *= 2;
		}
		array[parent-1].first = x;
		array[parent-1].second = xitem;

		return maxpair;
	}

	pair<int, T> getMax()
	{
		//max is always first factor by heapify(insert)
		return array.front();
	}


	bool isEmpty()
	{
		if(array.empty())
			return true;
		return false;
	}

	int factorSize()
	{
		return array.size();
	}

	void print()
	{
		cout << endl << "=============print=============" << endl;
		typename vector<pair<int, T> >::iterator iter;
		for(iter = array.begin(); iter != array.end(); iter++){
			cout<<iter->first << "(" << iter->second << ")" << " ";
		}
		cout << endl << "===============================" << endl;
	}

	void printtree(int index, int space)
	{
		if(array.size() < index) {
			return;
		}

		space += 4;
		printtree((index*2)+1, space); //right
		for(int i=4;i<space;i++) {
			cout << " ";
		}

		cout << array[index-1].first << endl;
		printtree((index*2), space); //left
	}
};


template <typename T>
class MinHeap
{
	vector<pair<int, T>> array;

public:
	MinHeap() {}
	void insert(int x, T item)
	{
		array.push_back(pair<int, T>(x, item));
		int target = array.size();
		while( target > 1 && x < array[(target/2)-1].first) {
			array[target-1].first = array[(target/2)-1].first;
			array[target-1].second = array[(target/2)-1].second;
			//cout << "target = " << target << ", target/2 = " << target/2 << endl;
			target /= 2;
			//cout << "target:" << target << endl;
		}
		//cout << "======end target========target:" << target << endl;
		array[target-1].first = x;
		array[target-1].second = item;
	}

	pair<int, T> popMin()
	{
		//min is always first factor by heapify(insert)
		pair<int, T> minpair(array.front().first,array.front().second);

		//end factor moves to first factor
		array.front().first = array.back().first;
		array.front().second = array.back().second;
		array.pop_back();

		//heapify
		int x = array.front().first;
		T xitem = array.front().second;
		int parent=1, child=2;
		int arrSize = array.size();
		while(child <= arrSize) {
			if(array[child-1].first > array[child].first) {
				child++;
			}
			if(x <= array[child-1].first) {
				break;
			}
			array[parent-1].first = array[child-1].first;
			array[parent-1].second = array[child-1].second;
			parent=child;
			child *= 2;
		}
		array[parent-1].first = x;
		array[parent-1].second = xitem;

		return minpair;
	}

	pair<int, T> getMin()
	{
		//min is always first factor by heapify(insert)
		return array.front();
	}


	bool isEmpty()
	{
		if(array.empty())
			return true;
		return false;
	}

	int factorSize()
	{
		return array.size();
	}

	void print()
	{
		cout << endl << "=============print=============" << endl;
		typename vector<pair<int, T> >::iterator iter;
		for(iter = array.begin(); iter != array.end(); iter++){
			cout<<iter->first << "(" << iter->second << ")" << " ";
		}
		cout << endl << "===============================" << endl;
	}

	void printtree(int index, int space)
	{
		if(array.size() < index) {
			return;
		}

		space += 4;
		printtree((index*2)+1, space); //right
		for(int i=4;i<space;i++) {
			cout << " ";
		}

		cout << array[index-1].first << endl;
		printtree((index*2), space); //left
	}
};


int main()
{
///////max sort
	MaxHeap<string> myheap;
	myheap.insert(60,"red");
	myheap.insert(18,"blue");
	myheap.insert(100,"yello");
	myheap.insert(7,"white");
	myheap.insert(1,"black");
	myheap.insert(280,"pink");
	myheap.insert(32,"green");
	myheap.insert(24,"violet");
	myheap.insert(66,"purple");
	myheap.insert(10,"gold");
	cout << "--------------tree-------------" << endl;
	myheap.printtree(1,0);
	cout << "-------------------------------" << endl;
	myheap.print();

	vector<pair<int,string>> sortmax;
	while(!myheap.isEmpty()) {
		pair<int, string> max = myheap.popMax();
		sortmax.push_back(max);
		/*
		cout << endl <<"pop max : " << max.first << endl;
		cout << "--------------tree-------------" << endl;
		myheap.printtree(1,0);
		cout << endl << "-------------------------------" << endl;
		*/		
	}

	cout << "max sort : ";
	vector<pair<int, string> >::iterator iter;
	for(iter = sortmax.begin(); iter != sortmax.end(); iter++) {
		cout<<iter->first << " ";
	}
	cout << endl;


///////////////min sort

	int a[] = {10,5,20,3,4,100,120,130};
	pair<int, string> mypair[] = {
		make_pair(10,"red"),
		make_pair(5,"blue"),
		make_pair(20,"yello"),
		make_pair(3,"white"),
		make_pair(4,"black"),
		make_pair(100,"pink"),
		make_pair(120,"green"),
		make_pair(130,"violet"),
	};
	MinHeap<string> minheap;
	for(int i=0; i<sizeof(a)/sizeof(int);i++) {
		minheap.insert(mypair[i].first,mypair[i].second);
	}
	cout << "--------------tree-------------" << endl;
	minheap.printtree(1,0);
	cout << "-------------------------------" << endl;
	
	minheap.print();

	vector<pair<int,string>> sortmin;
	while(!minheap.isEmpty()) {
		pair<int,string> min = minheap.popMin();
		sortmin.push_back(min);
		/*
		cout << endl <<"pop min : " << min.first << endl;
		cout << "--------------tree-------------" << endl;
		minheap.printtree(1,0);
		cout << endl << "-------------------------------" << endl;
		*/
	}

	cout << "min sort : ";
	for(iter = sortmin.begin(); iter != sortmin.end(); iter++) {
		cout<<iter->first << " ";
	}
	cout << endl;

	return 0;
}
