#pragma once
#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node();
	~Node();

};
class BST
{
private:
	Node* Root;
	void NLR(Node* &Root);
	void LNR(Node* &Root);
	void LRN(Node* &Root);
	void Insert(Node* &Root, int x);
	void Remove(Node* &Root, int x);
	Node* Search(Node* &Root, int x);
	Node* MinvalueNode(Node* &Root);
	int Height(Node* &Root);
	int CountNode(Node* &Root);
	bool isBST(Node* &Root,Node* left,Node* right);
public:
	Node* CreateNode(int data);
	Node* Search(int x);
	void Insert(int x);
	void NLR();
	void LNR();
	void LRN();
	void Remove(int x);
	int Height();
	int CountNode();
	int Max(int &a, int &b);
	bool isBST();
	BST();
	~BST();
};

