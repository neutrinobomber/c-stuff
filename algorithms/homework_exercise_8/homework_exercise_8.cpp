#include "pch.h"
#include <iostream>
#include <cstring>

using namespace std;

class Node
{
public:
	char data;
	Node* left;
	Node* right;

	Node() {}
	Node(char data) : data(data), left(nullptr), right(nullptr) {}
};

Node* ibd(int n)
{
	Node* newNode;

	if (n > 0)
	{
		int nl = n / 2;
		int nd = n - nl - 1;

		char x = 0;
		cout << "x: ";
		cin >> x;

		newNode = new Node(x);
		newNode->left = ibd(nl);
		newNode->right = ibd(nd);

		return newNode;
	}
	else
	{
		return nullptr;
	}
}

void PrintInfix(Node* root)
{
	if (root == nullptr)
	{
		return;
	}

	PrintInfix(root->left);
	cout << root->data << " ";
	PrintInfix(root->right);
}

void PrintPrefix(Node* root)
{
	if (root == nullptr)
	{
		return;
	}

	cout << root->data << " ";
	PrintPrefix(root->left);
	PrintPrefix(root->right);
}

void PrintPostfix(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	
	PrintPostfix(root->left);
	PrintPostfix(root->right);
	cout << root->data << " ";
}

int main()
{
	Node* root;

	cout << "n: ";
	int n = 0;
	cin >> n;

	root = ibd(n);

	cout << "infix: ";
	PrintInfix(root);
	cout << endl;

	cout << "prefix: ";
	PrintPrefix(root);
	cout << endl;

	cout << "postfix: ";
	PrintPostfix(root);
	cout << endl;

	return 0;
}