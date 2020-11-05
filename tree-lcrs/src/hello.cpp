#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

typedef struct lcrs {
	lcrs* leftchild;
	lcrs* rightsibling;
	int item;
} lcrs;


class LCRS_tree
{
private:
	lcrs* mlcrs;
public:
	lcrs* createNode(int item);
	void addNode(lcrs* parent, lcrs* child);
	void printinfo(lcrs* node);
	lcrs* getroot();
	void removeTree(lcrs* node);
	LCRS_tree();
	~LCRS_tree();
};

lcrs* LCRS_tree::createNode(int item)
{
	lcrs* newnode;

	newnode = new lcrs;
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

lcrs* LCRS_tree::getroot()
{
	return mlcrs;
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

void LCRS_tree::printinfo(lcrs* node)
{
	if(node->leftchild) {
		printinfo(node->leftchild);
		cout << endl;
	}

	if(node->rightsibling) {
		printinfo(node->rightsibling);
	}

	cout << node->item << ", ";
}


int main()
{
	LCRS_tree tree;
	lcrs* root = tree.createNode(0);
	tree.addNode(NULL,root);
	cout << "====tree=====" << endl;
	tree.printinfo(root);
	cout << endl << "====eof=====" << endl;

	lcrs* child = tree.createNode(1);
	tree.addNode(root,child);
	lcrs* child2 = tree.createNode(2);
	tree.addNode(root,child2);
	lcrs* child3 = tree.createNode(3);
	tree.addNode(root,child3);
	lcrs* child4 = tree.createNode(4);
	tree.addNode(root,child4);

	lcrs* child5 = tree.createNode(5);
	tree.addNode(child2,child5);
	lcrs* child6 = tree.createNode(6);
	tree.addNode(child2,child6);

	lcrs* child7 = tree.createNode(7);
	tree.addNode(child3,child7);


	cout << "====tree=====" << endl;
	tree.printinfo(root);
	cout << endl << "====eof=====" << endl;
	
	return 0;
}
