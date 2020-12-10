#include <functional>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MaxHeap
{
private :
	vector<T> array;

	// c style
	//bool (*compare)(...);
	function<bool(T first, T second)> compare;

	static bool dcompare(T first, T second)
	{
		return first > second;
	}

public:
	MaxHeap()
	{
		compare = this->dcompare;
	}
	MaxHeap(function<bool(T first, T second)> usercompare)
	{
		compare = usercompare;
	}
	void insert(T x)
	{		
		array.push_back(x);
		int target = array.size();
		while( target > 1 && compare(x,array[(target/2)-1]) ) {
			array[target-1] = array[(target/2)-1];
			//cout << "target = " << target << ", target/2 = " << target/2 << endl;
			target /= 2;
			//cout << "target:" << target << endl;
		}
		//cout << "======end target========target:" << target << endl;
		array[target-1] = x;
	}

	T popMax()
	{
		//max is always first factor by heapify(insert)
		T max = array.front();

		//end factor moves to first factor
		array.front() = array.back();
		array.pop_back();

		//heapify
		T x = array.front();
		int parent=1, child=2;
		int arrSize = array.size();
		while(child <= arrSize) {
			if( !compare(array[child-1], array[child]) ) {
				child++;
			}
			if( compare(x,array[child-1]) || (x == array[child-1]) ) {
				break;
			}
			array[parent-1] = array[child-1];
			parent=child;
			child *= 2;
		}
		array[parent-1] = x;

		return max;
	}

	T getMax()
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
		for (vector<int>::const_iterator item=array.begin(); item != array.end();++item) {
			cout<<*item << " ";
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

		cout << array[index-1] << endl;
		printtree((index*2), space); //left
	}

	void printtree()
	{
		printtree(1, 0);
	}
};

template <typename T>
class MinHeap
{
private :
	vector<T> array;

	// c style
	//bool (*compare)(...);
	function<bool(T first, T second)> compare;

	static bool dcompare(T first, T second)
	{
		return first > second;
	}


public:
	MinHeap()
	{
		compare = this->dcompare;
	}
	MinHeap(function<bool(T first, T second)> usercompare)
	{
		compare = usercompare;
	}

	void insert(T x)
	{
		array.push_back(x);
		int target = array.size();
		while( target > 1 && !compare(x,array[(target/2)-1]) ) {
			array[target-1] = array[(target/2)-1];
			//cout << "target = " << target << ", target/2 = " << target/2 << endl;
			target /= 2;
			//cout << "target:" << target << endl;
		}
		//cout << "======end target========target:" << target << endl;
		array[target-1] = x;
	}

	T popMin()
	{
		//min is always first factor by heapify(insert)
		T min = array.front();

		//end factor moves to first factor
		array.front() = array.back();
		array.pop_back();

		//heapify
		T x = array.front();
		int parent=1, child=2;
		int arrSize = array.size();
		while(child <= arrSize) {
			if( compare(array[child-1], array[child]) ) {
				child++;
			}
			if( !compare(x,array[child-1]) || (x == array[child-1]) ) {
				break;
			}
			array[parent-1] = array[child-1];
			parent=child;
			child *= 2;
		}
		array[parent-1] = x;

		return min;
	}

	T getMin()
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
		for (vector<int>::const_iterator item=array.begin(); item != array.end();++item) {
			cout<<*item << " ";
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

		cout << array[index-1] << endl;
		printtree((index*2), space); //left
	}

	void printtree()
	{
		printtree(1, 0);
	}
};


int main()
{
///////max sort
	MaxHeap<int> myheap;
	myheap.insert(60);
	myheap.insert(18);
	myheap.insert(100);
	myheap.insert(7);
	myheap.insert(1);
	myheap.insert(280);
	myheap.insert(32);
	myheap.insert(24);
	myheap.insert(66);
	myheap.insert(10);
	cout << "--------------tree-------------" << endl;
	myheap.printtree(1,0);
	cout << "-------------------------------" << endl;

	vector<int> sortmax;
	while(!myheap.isEmpty()) {
		int max = myheap.popMax();
		sortmax.push_back(max);
		/*
		cout << endl <<"pop max : " << max << endl;
		cout << "--------------tree-------------" << endl;
		myheap.printtree(1,0);
		cout << endl << "-------------------------------" << endl;
		*/		
	}

	cout << "max sort : ";
	for (vector<int>::const_iterator i=sortmax.begin(); i != sortmax.end();++i) {
		cout<<*i << " ";
	}
	cout << endl;


///////////////min sort

	int a[] = {10,5,20,3,4,100,120,130};
	MinHeap<int> minheap;
	for(int i=0; i<sizeof(a)/sizeof(int);i++) {
		minheap.insert(a[i]);
	}
	cout << "--------------tree-------------" << endl;
	minheap.printtree(1,0);
	cout << "-------------------------------" << endl;

	vector<int> sortmin;
	while(!minheap.isEmpty()) {
		int min = minheap.popMin();
		sortmin.push_back(min);
		/*
		cout << endl <<"pop min : " << min << endl;
		cout << "--------------tree-------------" << endl;
		minheap.printtree(1,0);
		cout << endl << "-------------------------------" << endl;
		*/
		
	}

	cout << "min sort : ";
	for (vector<int>::const_iterator i=sortmin.begin(); i != sortmin.end();++i) {
		cout<<*i << " ";
	}
	cout << endl;

	return 0;
}
