#include "AVL.h"
int main()
{
	AVL T;
	T.Insert(2);
	T.Insert(3);
	T.Insert(4);
	T.Insert(5);
	T.Insert(23);
	T.Insert(4);
	T.Insert(24);
	T.Insert(34);
	T.Insert(12);
	T.Insert(16);
	T.Insert(22);
	T.LNR();
	cout << "\n";
	T.Remove(3);
	T.LRN();

	system("pause");

}