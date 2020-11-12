#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node {
	struct Node<T> *left;
	struct Node<T> *right;
	T item;
};

template <typename T>
class Bin_tree
{
private:
	Node<T> *mNode;
public:
	Node<T>* createNode(T item)
	{
		Node<T> *newnode;
	
		newnode = new Node<T>;
		newnode->item = item;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}

	void insertNode(T item)
	{
		Node<T> *newnode = insertNode(mNode,item);
		if(mNode == NULL) {
			mNode = newnode;
			cout << "create root node" << endl;
		}
	}

	Node<T>* insertNode(Node<T>* node, T item)
	{
		if(node == NULL) {
			Node<T> *newnode = createNode(item);
			return newnode;
		}

		if(node->item < item) {
			node->right = insertNode(node->right,item);
		} else {
			node->left = insertNode(node->left,item);
		}

		return node;
	}

	Node<T>* findNode(T item)
	{
		findNode(mNode,item);
	}

	Node<T>* findNode(Node<T>* node, T item)
	{
		if(node == NULL) return NULL;

		if(node->item == item) {
			//break;
			return node;
		}

		if(node->left) {
			Node<T>* mynode = findNode(node->left,item);
			if(mynode) return mynode;
		}

		if(node->right) {
			Node<T>* mynode = findNode(node->right,item);
			if(mynode) return mynode;
		}

		return NULL;
	}

	Node<T>* getroot()
	{
		return mNode;
	}

	void removeTree(Node<T>* node)
	{
		if(node->right) {
			removeTree(node->right);
			//cout << "right" << endl;
		}
	
		if(node->left) {
			removeTree(node->left);
			//cout << "left" << endl;
		}
	
		node->right = NULL;
		node->left = NULL;
		//cout << "remove" << endl;
	
		delete node;
		node = NULL;
	}

//extention
	void preOrder()
	{
		preOrder(mNode);
	}

	void inOrder()
	{
		inOrder(mNode);
	}

	void postOrder()
	{
		postOrder(mNode);
	}

	void preOrder(Node<T>* node)
	{
		cout << ":item(" << node->item << ")	 ,";
		if(node->left) {
			preOrder(node->left);
		}
	
		if(node->right) {
			preOrder(node->right);
		}
	}

	void inOrder(Node<T>* node)
	{
		if(node->left) {
			inOrder(node->left);
		}

		cout << ":item(" << node->item << ")	 ,";

		if(node->right) {
			inOrder(node->right);
		}
	}

	void postOrder(Node<T>* node)
	{
		if(node->left) {
			postOrder(node->left);
		}
	
		if(node->right) {
			postOrder(node->right);
		}
		cout << ":item(" << node->item << ")	 ,";
	}

	void printTree()
	{
		printTree(mNode, 0);
	}

	void printTree(Node<T> *node, int space){
		if (node == NULL)
			return;

		space += 4; //number of spaces
		printTree(node->right, space);
		for (int i = 4; i < space; i++) //number of spaces
			cout << " ";
		cout << node->item << endl;
		printTree(node->left, space);
	}


//creator,destructor
	Bin_tree()
	{
		mNode = NULL;
	}
	~Bin_tree()
	{
		removeTree(mNode);
	}
};

int main()
{
	Bin_tree<int> mytree;

	/*              24
	*             /   \
	*          16       35
	*         /  \
	*       14    20
	*       / \
	*     5   15
	*/

	mytree.insertNode(24);
	mytree.insertNode(16);
	mytree.insertNode(35);
	mytree.insertNode(14);
	mytree.insertNode(20);
	mytree.insertNode(5);
	mytree.insertNode(15);

	cout << "pre order  : {";
	mytree.preOrder();
	cout << "}" << endl;

	cout << "in order   : {";
	mytree.inOrder();
	cout << "}" << endl;

	cout << "post order : {";
	mytree.postOrder();
	cout << "}" << endl;

	Node<int>* mynode = mytree.findNode(5);
	if(mynode) {
		cout << "found my node:	" << mynode->item << endl;
	}

	cout << "==========print Tree(horizontally)===========" << endl;
	mytree.printTree();
	cout << "=============================================" << endl;

	return 0;
}
