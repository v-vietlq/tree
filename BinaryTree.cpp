#include "BinaryTree.h"


Node::Node()
{
	data = 0;
	left = right = NULL;
}
Node::~Node()
{
}
BST::BST()
{
	Root = NULL;
}
BST::~BST()
{
}
Node* BST::CreateNode(int data)
{
	Node* newNode = new Node;
	if (newNode == NULL) return NULL;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void BST::Insert(int x)
{
	Insert(Root, x);
}
void BST::Insert(Node* &Root, int x)
{
	if (Root == NULL)
	{
		Root = CreateNode(x);
	}
	else
	{
		if (Root->data < x) Insert(Root->right, x);
		else if (Root->data > x) Insert(Root->left, x);
		else return;
	}
}
void BST::NLR()
{
	NLR(Root);
}
void BST::NLR(Node* &Root)
{
	if (Root == NULL) return;
	else
	{
		cout << Root->data << " ";
		NLR(Root->left);
		NLR(Root->right);
	}
}
void BST::LNR()
{
	LNR(Root);
}
void BST::LNR(Node* &Root)
{
	if (Root == NULL) return;
	else
	{
		LNR(Root->left);
		cout << Root->data << " ";
		LNR(Root->right);
	}
}
void BST::LRN()
{
	LRN(Root);
}
void BST::LRN(Node* &Root)
{
	if (Root == NULL) return;
	else
	{
		LRN(Root->left);
		LRN(Root->right);
		cout << Root->data << " ";
	}
}
Node* BST::Search(Node* &Root, int x)
{
	if (Root == NULL) return NULL;
	if (Root->data == x) return Root;
	else if (Root->data > x) return Search(Root->left, x);
	else return Search(Root->right, x);
}
Node* BST::Search(int x)
{
	return Search(Root, x);
}
int BST::Max(int &a, int &b)
{
	if (a >= b)return a;
	else return b;
}
int BST::Height()
{
	return Height(Root);
}
int BST::Height(Node* &Root)
{
	int LeftHeight, RightHeight;
	if (Root == NULL) return 0;
	LeftHeight = Height(Root->left);
	RightHeight = Height(Root->right);
	return Max(LeftHeight, RightHeight) + 1;
}
int BST::CountNode(Node* &Root)
{
	if (Root == NULL) return 0;
	else
		return CountNode(Root->left) + CountNode(Root->right) + 1;
}
int BST::CountNode()
{
	return CountNode(Root);
}
Node* BST::MinvalueNode(Node* &Root)
{
	Node* Cur = Root;
	while (Cur->left != NULL)
		Cur = Cur->left;
	return Cur;
}
void BST::Remove(Node* &Root, int x)
{
	if (Root == NULL) return;
	else
	{
		if (Root->data > x) Remove(Root->left, x);
		else if (Root->data < x) Remove(Root->right, x);
		else
		{
			if (Root->left == NULL)
			{
				Node* temp = Root->right;
				delete Root;
				Root = temp;
			}
			else if (Root->right == NULL)
			{
				Node*temp = Root->left;
				delete Root;
				Root = temp;
			}
			else
			{
				Node* MinNode = MinvalueNode(Root->right);
				Root->data = MinNode->data;
				Remove(Root->right, MinNode->data);
			}
		}
	}
}
void BST::Remove(int x)
{
	Remove(Root, x);
}
bool BST::isBST(Node* &Root,Node* left,Node* right)
{
	if (Root == NULL) return true;
	if (left != NULL && Root->data < left->data) return false;
	if (right != NULL && Root->data > right->data) return false;
	return isBST(Root->left, left, Root) && isBST(Root->right, Root, right);
}
bool BST::isBST()
{
	return isBST(Root, NULL, NULL);
}