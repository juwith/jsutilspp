#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

template <typename T>
struct lcrs {
	struct lcrs<T> *leftchild;
	struct lcrs<T> *rightsibling;
	int index;
	T item;
};

template <typename T>
class LCRS_tree
{
private:
	lcrs<T> *mlcrs;
public:
	lcrs<T>* createNode(int index, T item)
	{
		lcrs<T> *newnode;
	
		newnode = new lcrs<T>;
		newnode->index = index;
		newnode->item = item;
		newnode->leftchild = NULL;
		newnode->rightsibling = NULL;
		return newnode;
	}

	void addNode(lcrs<T>* parent, lcrs<T>* child)
	{
		if(mlcrs == NULL) {
			mlcrs = child;
			cout << "create root" << endl;
			return;
		}

		if(parent->leftchild == NULL) {
			parent->leftchild = child;
			//cout << "add left" << endl;
		} else {
			lcrs<T>* mchild = parent->leftchild;
			while(mchild->rightsibling != NULL) {
				mchild = mchild->rightsibling;
			}
			mchild->rightsibling = child;
			//cout << "add right" << endl;
		}
	}

	lcrs<T>* getroot()
	{
		return mlcrs;
	}

	lcrs<T>* findNode(lcrs<T>* node, int index)
	{
		if(node == NULL) return NULL;

		if(node->index == index) {
			//break;
			return node;
		}

		if(node->leftchild) {
			lcrs<T>* mynode = findNode(node->leftchild,index);
			if(mynode) return mynode;
		}

		if(node->rightsibling) {
			lcrs<T>* mynode = findNode(node->rightsibling,index);
			if(mynode) return mynode;
		}

		return NULL;
	}

	void removeTree(lcrs<T>* node)
	{
		if(node->rightsibling) {
			removeTree(node->rightsibling);
			//cout << "right" << endl;
		}
	
		if(node->leftchild) {
			removeTree(node->leftchild);
			//cout << "left" << endl;
		}
	
		node->rightsibling = NULL;
		node->leftchild = NULL;
		//cout << "remove" << endl;
	
		delete node;
		node = NULL;
	}

//extention
	void printinfo(lcrs<T>* node)
	{
		if(node->leftchild) {
			printinfo(node->leftchild);
			cout << endl;
		}
	
		if(node->rightsibling) {
			printinfo(node->rightsibling);
		}
	
		cout << node->index << ":item(" << node->item << ")	 ,";
	}
	lcrs<T>* userSum(lcrs<T>* node, int index, int* sum)
	{
		if(node == NULL) return NULL;
	
		if(node->index == index) {
			//break;
			T item = node->item;
			*sum += item.size();
			return node;
		}
	
		if(node->leftchild) {
			lcrs<T>* mynode = userSum(node->leftchild,index,sum);
			if(mynode) {
				T item = node->item;
				*sum += item.size();
				return mynode;
			}
		}
	
		if(node->rightsibling) {
			lcrs<T>* mynode = userSum(node->rightsibling,index,sum);
			if(mynode) {
				return mynode;
			}
		}
	}

//creator,destructor
	LCRS_tree()
	{
		mlcrs = NULL;
	}
	~LCRS_tree()
	{
		removeTree(mlcrs);
	}
	
};



int main()
{
	LCRS_tree<string> tree;
/*

	lcrs* root = tree.createNode(1,NULL);
	tree.addNode(NULL,root);
	cout << "====tree=====" << endl;
	tree.printinfo(root);
	cout << endl << "====eof=====" << endl;

	lcrs* child = tree.createNode(1,NULL);
	tree.addNode(root,child);
	lcrs* child2 = tree.createNode(2,NULL);
	tree.addNode(root,child2);
	lcrs* child3 = tree.createNode(3,NULL);
	tree.addNode(root,child3);
	lcrs* child4 = tree.createNode(4,NULL);
	tree.addNode(root,child4);

	lcrs* child5 = tree.createNode(5,NULL);
	tree.addNode(child2,child5);
	lcrs* child6 = tree.createNode(6,NULL);
	tree.addNode(child2,child6);

	lcrs* child7 = tree.createNode(7,NULL);
	tree.addNode(child3,child7);

	lcrs* mynode = tree.findNode(root,1);
	if(mynode) cout << "find node index: " << mynode->index << endl;

*/

	int myarr[][2] = {
		{1,2},
		{1,3},
		{1,4},
		{2,5},
		{2,6},
		{2,7},
		{6,11},
		{7,8},
		{7,9},
		{7,10},
	};

	int itemsize = sizeof(myarr)/sizeof(myarr[0])+1;
	string myitem[itemsize] = {"root","usr","bin","lib","mydata","etc","hello","abc","ccc","dev","tmp"};

	lcrs<string> *root = NULL;
	for(int i=0;i<sizeof(myarr)/sizeof(myarr[0]);i++) {
		//myarr[i][0] <= parent
		//myarr[i][1] <= child
		lcrs<string> *parent = tree.findNode(root, myarr[i][0]);
		if(parent == NULL) {
			parent = tree.createNode(myarr[i][0],myitem[0]);
			tree.addNode(root,parent);
			root = parent;
		}
		int numofitem = myarr[i][1]-1;
		lcrs<string> *child = tree.createNode(myarr[i][1],myitem[numofitem]);

		tree.addNode(parent,child);
	}
	// result :
	// 1(root)
	// |
	// 2(usr) - 3(bin) - 4(lib)
	// |
	// 5(mydata) - 6(etc) - 7(hello)
	//     |                   |
	//    11(abc)   8(ccc) - 9(dev) - 10(tmp)

	//calculate accumluated val
	cout << "====tree=====" << endl;
	tree.printinfo(root);
	cout << endl << "====eof=====" << endl;

	int max=0;
	for(int i=1;i<itemsize+1;i++) {
		int sum = 0;
		tree.userSum(root,i,&sum);
		cout << "index " << i << " sum of string size : " << sum << endl;
		if(max < sum) max=sum;
	}

	cout << "max sum : " << max << endl;

	return 0;
}
