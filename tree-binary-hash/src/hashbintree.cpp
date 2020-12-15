#include <iostream>
#include <string>
using namespace std;

template <typename Key, typename T>
struct Node {
	struct Node<Key, T> *left;
	struct Node<Key, T> *right;
	Key key;
	T item;
};

template <typename Key, typename T>
class Bin_tree
{
private:
	Node<Key, T> *mNode;
public:
	Node<Key, T>* createNode(Key key, T item)
	{
		Node<Key, T> *newnode;
	
		newnode = new Node<Key, T>;
		newnode->key = key;
		newnode->item = item;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}

	void insertNode(Key key, T item)
	{
		Node<Key, T> *newnode = insertNode(mNode,key, item);
		if(mNode == NULL) {
			mNode = newnode;
			cout << "create root node" << endl;
		}
	}

	Node<Key, T>* insertNode(Node<Key, T>* node, Key key, T item)
	{
		if(node == NULL) {
			Node<Key, T> *newnode = createNode(key, item);
			return newnode;
		}

		if(node->key < key) {
			node->right = insertNode(node->right,key,item);
		} else {
			node->left = insertNode(node->left,key,item);
		}

		return node;
	}

	Node<Key, T>* findNode(Key key)
	{
		return findNode(mNode,key);
	}

	Node<Key, T>* findNode(Node<Key, T>* node, Key key)
	{
		if(node == NULL) return NULL;

		if(node->key == key) {
			//break;
			return node;
		}

		if(node->left) {
			Node<Key, T>* mynode = findNode(node->left,key);
			if(mynode) return mynode;
		}

		if(node->right) {
			Node<Key, T>* mynode = findNode(node->right,key);
			if(mynode) return mynode;
		}

		return NULL;
	}

	Node<Key, T>* getroot()
	{
		return mNode;
	}

	Node<Key, T>* findMinNode(Node<Key, T>* node)
	{
		if(node == NULL)
			return NULL;

		if(node->left == NULL) {
			return node;
		}

		cout << "min is " << node->key <<endl;
		return findMinNode(node->left);
	}

	Node<Key, T>* removeNode(Key key)
	{
		removeNode(mNode,key);
	}

	Node<Key, T>* removeNode(Node<Key, T>* node, Key key)
	{
		Node<Key, T>* temp;
		if(node == NULL) {
			return NULL;
		}

		if(node->key > key) {
			node->left = removeNode(node->left,key);
			return node;
		} else if(node->key < key) {
			node->right = removeNode(node->right,key);
			return node;
		}

		if(node->left && node->right) {
			temp = findMinNode(node->right);
			node->key = temp->key;
			node->right = removeNode(node->right,node->key);
		} else {
			temp = node;
			if(node->left == NULL) {
				node = node->right;
			} else if(node->right == NULL) {
				node = node->left;
			}
			delete temp;
			temp = NULL;
		}

		return node;
	}

	void removeTree(Node<Key, T>* node)
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

	void preOrder(Node<Key, T>* node)
	{
		cout << ":item(" << node->key << ")	 ,";
		if(node->left) {
			preOrder(node->left);
		}
	
		if(node->right) {
			preOrder(node->right);
		}
	}

	void inOrder(Node<Key, T>* node)
	{
		if(node->left) {
			inOrder(node->left);
		}

		cout << ":item(" << node->key << ")	 ,";

		if(node->right) {
			inOrder(node->right);
		}
	}

	void postOrder(Node<Key, T>* node)
	{
		if(node->left) {
			postOrder(node->left);
		}
	
		if(node->right) {
			postOrder(node->right);
		}
		cout << ":item(" << node->key << ")	 ,";
	}

	enum TREE_PRINT_MODE{PRINT_ONLY_KEY, PRINT_ONLY_ITEM, PRINT_ALL};

	void printKeyTree()
	{
		printTree(mNode, 0, PRINT_ONLY_KEY);
	}

	void printItemTree()
	{
		printTree(mNode, 0, PRINT_ONLY_ITEM);
	}

	void printTree()
	{
		printTree(mNode, 0, PRINT_ALL);
	}

	void printTree(Node<Key, T> *node, int space, TREE_PRINT_MODE mode){
		if (node == NULL)
			return;

		space += 4; //number of spaces
		printTree(node->right, space, mode);
		for (int i = 4; i < space; i++) //number of spaces
			cout << " ";
		switch(mode) {
			case PRINT_ONLY_KEY:
				cout << node->key << endl;
			break;
			case PRINT_ONLY_ITEM:
				cout << node->item << endl;
			break;
			case PRINT_ALL:
				cout << node->key << "(" << node->item << ")" << endl;
			break;
		}
		
		printTree(node->left, space, mode);
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
	Bin_tree<int, string> mytree;

	/*              24
	*             /   \
	*          16       35
	*         /  \
	*       14    20
	*       / \
	*     5   15
	*/

	mytree.insertNode(24,"yello");
	mytree.insertNode(16,"red");
	mytree.insertNode(35,"blue");
	mytree.insertNode(14,"green");
	mytree.insertNode(20,"white");
	mytree.insertNode(5,"black");
	mytree.insertNode(15,"gray");

	cout << "pre order  : {";
	mytree.preOrder();
	cout << "}" << endl;

	cout << "in order   : {";
	mytree.inOrder();
	cout << "}" << endl;

	cout << "post order : {";
	mytree.postOrder();
	cout << "}" << endl;

	Node<int,string>* mynode = mytree.findNode(5);
	if(mynode) {
		cout << "found my node key : " << mynode->key << ", item : " << mynode->item << endl;
	}

	cout << "==========print Tree(horizontally)===========" << endl;
	mytree.printTree();
	cout << "=============================================" << endl;

	cout << "===remove \"5 \" print Tree(horizontally)====" << endl;
	mytree.removeNode(5);
	mytree.printTree();
	cout << "=============================================" << endl;

	cout << "===remove \"14 \" print Tree(horizontally)====" << endl;
	mytree.removeNode(14);
	mytree.printTree();
	cout << "=============================================" << endl;

	cout << "===remove \"24 \" print Tree(horizontally)====" << endl;
	mytree.removeNode(24);
	mytree.printTree();
	cout << "=============================================" << endl;




//////////////////

	Bin_tree<string, string> hashmap;
	hashmap.insertNode("water mellon","green");
	hashmap.insertNode("blueberry","blue");
	hashmap.insertNode("apple","red");
	hashmap.insertNode("lemon","yello");
	hashmap.insertNode("banana","yello");

	hashmap.printTree();

	Node<string,string>* mynode2 = hashmap.findNode("banana");
	if(mynode2) {
		cout << "found my node key : " << mynode2->key << ", item : " << mynode2->item << endl;
	}


	return 0;
}
