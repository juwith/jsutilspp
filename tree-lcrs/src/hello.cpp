#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

typedef struct lcrs {
	lcrs* leftchild;
	lcrs* rightsibling;
	int index;
	void* item;
} lcrs;


class LCRS_tree
{
private:
	lcrs* mlcrs;
public:
	lcrs* createNode(int index, void* item);
	void addNode(lcrs* parent, lcrs* child);
	void printinfo(lcrs* node);
	lcrs* getroot();
	lcrs* findNode(lcrs* node, int index);
	void removeTree(lcrs* node);
	LCRS_tree();
	~LCRS_tree();
};

lcrs* LCRS_tree::createNode(int index, void* item)
{
	lcrs* newnode;

	newnode = new lcrs;
	newnode->index = index;
	newnode->item = item;
	newnode->leftchild = NULL;
	newnode->rightsibling = NULL;
	return newnode;
}


void LCRS_tree::addNode(lcrs* parent, lcrs* child)
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
		lcrs* mchild = parent->leftchild;
		while(mchild->rightsibling != NULL) {
			mchild = mchild->rightsibling;
		}
		mchild->rightsibling = child;
		//cout << "add right" << endl;
	}
}

void LCRS_tree::printinfo(lcrs* node)
{
	if(node->leftchild) {
		printinfo(node->leftchild);
		cout << endl;
	}

	if(node->rightsibling) {
		printinfo(node->rightsibling);
	}

	cout << node->index << ", ";
}


lcrs* LCRS_tree::getroot()
{
	return mlcrs;
}

lcrs* LCRS_tree::findNode(lcrs* node, int index)
{
	if(node == NULL) return NULL;

	if(node->index == index) {
		//break;
		return node;
	}

	if(node->leftchild) {
		lcrs* mynode = findNode(node->leftchild,index);
		if(mynode) return mynode;
	}

	if(node->rightsibling) {
		lcrs* mynode = findNode(node->rightsibling,index);
		if(mynode) return mynode;
	}
}


void LCRS_tree::removeTree(lcrs* node)
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


LCRS_tree::LCRS_tree()
{
	mlcrs = NULL;
}


LCRS_tree::~LCRS_tree()
{
	removeTree(mlcrs);
}


int main()
{
	LCRS_tree tree;
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

	lcrs* root = NULL;
	for(int i=0;i<sizeof(myarr)/sizeof(myarr[0]);i++) {
		//myarr[i][0] <= parent
		//myarr[i][1] <= child
		lcrs* parent = tree.findNode(root, myarr[i][0]);
		if(parent == NULL) {
			parent = tree.createNode(myarr[i][0],NULL);
			tree.addNode(root,parent);
			root = parent;
		}

		lcrs* child = tree.createNode(myarr[i][1],NULL);

		tree.addNode(parent,child);
	}
	// result :
	// 1
	// |
	// 2 - 3 - 4
	// |
	// 5 - 6 - 7
	//     |   |
	//    11   8 - 9 - 10


	cout << "====tree=====" << endl;
	tree.printinfo(root);
	cout << endl << "====eof=====" << endl;
	
	return 0;
}
