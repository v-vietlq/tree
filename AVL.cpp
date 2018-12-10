#include "AVL.h"

Node::Node()
{
	data = 0;
	left = right = NULL;
	height = 1;
}
Node::~Node()
{
	delete left;
	delete right;
}
AVL::AVL()
{
	Root = NULL;
}

AVL::~AVL()
{
}
Node* AVL::CreateNode(int data)
{
	Node* newNode = new Node;
	if (newNode == NULL) return NULL;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}
int AVL::Height(Node* &Root)
{
	if (Root == NULL) return 0;
	return Root->height;
}
int AVL::Height()
{
	return Height(Root);
}
int AVL::max(int a, int b)
{
	if (a >= b) return a;
	else return b;
}
int AVL::getBalanced(Node* &Root)
{
	if (Root == NULL) return 0;
	return Height(Root->left) - Height(Root->right);
}
Node* AVL::LeftRotate(Node* &Root)
{
	Node* temp = Root->right;
	Root->right = temp->left;
	temp->left = Root;

	Root->height = max(Height(Root->left), Height(Root->right)) + 1;
	temp->height = max(Height(temp->left), Height(temp->right)) + 1;
	Root = temp;
	return Root;
}
Node* AVL::RightRotate(Node* &Root)
{
	Node* temp = Root->left;
	Root->left = temp->right;
	temp->right = Root;

	Root->height = max(Height(Root->left), Height(Root->right)) + 1;
	temp->height = max(Height(temp->left), Height(temp->right)) + 1;
	Root = temp;
	return Root;
}
Node* AVL::Insert(Node* &Root, int x)
{
	if (Root == NULL) Root = CreateNode(x);
	else
	{
		if (Root->data < x) Insert(Root->right, x);
		else if (Root->data > x) Insert(Root->left, x);
		else return Root;
	}
	Root->height = 1 + max(Height(Root->left), Height(Root->right));
	int Balance = getBalanced(Root);

	// Left Left Case
	if (Balance > 1 && x < Root->left->data)
		return RightRotate(Root);

	// Right Right Case 
	if (Balance < -1 && x > Root->right->data)
		return LeftRotate(Root);

	// Left Right Case 
	if (Balance > 1 && x > Root->left->data)
	{
		Root->left = LeftRotate(Root->left);
		return RightRotate(Root);
	}

	// Right Left Case 
	if (Balance < -1 && x < Root->right->data)
	{
		Root->right = RightRotate(Root->right);
		return LeftRotate(Root);
	}

	return Root;
}

Node* AVL::Insert(int data)
{
	return Insert(Root, data);
}
Node* AVL::MinValueNode(Node* &Root)
{
	Node *cur = Root;
	while (cur->left != NULL)
	{
		cur = cur->left;
	}
	return cur;
}
Node* AVL::Remove(Node* &Root, int x)
{
	if (Root == NULL) return Root;
	else
	{
		if (x > Root->data) Root->right = Remove(Root->right, x);
		else if (x < Root->data) Root->left = Remove(Root->left, x);
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
				Node* temp = Root->left;
				delete Root;
				Root = temp;
			}
			else
			{
				Node * minNode = MinValueNode(Root->right);
				Root->data = minNode->data;
				Root->right = Remove(Root->right, minNode->data);
			}
		}
		if (Root == NULL) return Root;
		Root->height = max(Height(Root->left), Height(Root->right)) + 1;
		int Balance = getBalanced(Root);

		// Left Left Case
		if (Balance > 1 && getBalanced(Root->left) >= 0)
			return RightRotate(Root);

		// Right Right Case 
		if (Balance < -1 && getBalanced(Root->right) <= 0)
			return LeftRotate(Root);

		// Left Right Case 
		if (Balance > 1 && getBalanced(Root->left) < 0)
		{
			Root->left = LeftRotate(Root->left);
			return RightRotate(Root);
		}

		// Right Left Case 
		if (Balance < -1 && getBalanced(Root->right) < 0)
		{
			Root->right = RightRotate(Root->right);
			return LeftRotate(Root);
		}
		return Root;
	}

}
Node* AVL::Remove(int data)
{
	return Remove(Root, data);
}

void AVL::LNR()
{
	LNR(Root);
}
void AVL::LNR(Node* &Root)
{
	if (Root == NULL) return;
	else
	{
		LNR(Root->left);
		cout << Root->data << " ";
		LNR(Root->right);
	}
}
void AVL::LRN()
{


	LRN(Root);
}
void AVL::LRN(Node* &Root)
{
	if (Root == NULL) return;
	else
	{
		LRN(Root->left);
		LRN(Root->right);
		cout << Root->data << " ";
	}
}