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
	Node* darj;

	if (n > 0)
	{
		int nl = n / 2;
		int nd = n - nl - 1;

		char x = 0;
		cout << "x: ";
		cin >> x;

		darj = new Node(x);
		darj->left = ibd(nl);
		darj->right = ibd(nd);

		return darj;
	}
	else
	{
		return nullptr;
	}
}

int count1 = 1;
void print(Node* root)
{
	if (root)
	{
		cout << "\t" << root->data;
		count1++;
		print(root->right);
		count1--;
		cout << endl;
		for (int i = 1; i <= count1; i++)
		{
			cout << "\t";
		}
		count1++;
		print(root->left);
		count1--;
	}
}

int main()
{
	Node* root;

	cout << "n: ";
	int n = 0;
	cin >> n;

	root = ibd(n);
	print(root);

	return 0;
}