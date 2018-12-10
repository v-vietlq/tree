#pragma once
#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* left;
	Node* right;
	int height;
	Node();
	~Node();

};
class AVL
{
private:
	Node* Root;
	Node* Insert(Node*& Root, int x);
	Node* Remove(Node*& Root, int x);
	Node* MinValueNode(Node* &Root);
	int Height(Node*& Root);
	int getBalanced(Node*& Root);
	Node* LeftRotate(Node* &Root);
	Node* RightRotate(Node* &Root);
	void LNR(Node* &Root);
	void LRN(Node* &Root);
public:
	Node* CreateNode(int data);
	int max(int a, int b);
	Node* Insert(int data);
	Node* Remove(int data);
	int Height();
	void LNR();
	void LRN();
	AVL();
	~AVL();
};

