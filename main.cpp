#include "BinaryTree.h"
int main()
{
	BST T;
	T.Insert(3);
	T.Insert(4);
	T.Insert(1);
	T.Insert(2);
	T.Insert(5);
	T.Insert(0);
	T.Insert(6);
	T.LRN();
	cout << "\n";
	T.Remove(8);
	T.LNR();
	if (T.isBST()) cout << "\nTree is a Binary search tree\n";
	else cout << "\nTree is not a Binary search tree\n";
	system("pause");
	return 0;
}