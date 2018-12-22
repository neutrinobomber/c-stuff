#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	char data;
	shared_ptr<Node> left;
	shared_ptr<Node> right;

	Node() {}
	Node(char data) : data(data), left(nullptr), right(nullptr) {}
};

class Tree
{
private:
	shared_ptr<Node> root;
	unsigned currentElement;

	shared_ptr<Node> BuildTree(string data, size_t treeSize)
	{
		if (treeSize > 0)
		{
			size_t leftTreeSize = treeSize / 2;
			size_t rightTreeSize = treeSize - leftTreeSize - 1;

			char element = data[this->currentElement];
			shared_ptr<Node> newNode(new Node(element));

			this->currentElement += 1;

			newNode->left = this->BuildTree(data, leftTreeSize);
			newNode->right = this->BuildTree(data, rightTreeSize);

			return newNode;
		}
		else
		{
			return nullptr;
		}
	}

	void Infix(shared_ptr<Node> node)
	{
		if (node == nullptr)
		{
			return;
		}

		Infix(node->left);
		cout << node->data << " ";
		Infix(node->right);
	}

	void Prefix(shared_ptr<Node> node)
	{
		if (node == nullptr)
		{
			return;
		}

		cout << node->data << " ";
		Prefix(node->left);
		Prefix(node->right);
	}

	void Postfix(shared_ptr<Node> node)
	{
		if (node == nullptr)
		{
			return;
		}

		Postfix(node->left);
		Postfix(node->right);
		cout << node->data << " ";
	}

public:
	Tree() : root(nullptr) {}

	void Build(string data)
	{
		this->root = nullptr;
		this->currentElement = 0;
		this->root = this->BuildTree(data, data.size());
	}

	void PrintInfix()
	{
		Infix(this->root);
	}

	void PrintPrefix()
	{
		this->Prefix(root);
	}

	void PrintPostfix()
	{
		this->Postfix(this->root);
	}
};

int main()
{
	string data = "";
	cout << "input: ";
	cin >> data;

	Tree tree;
	tree.Build(data);

	cout << "infix: ";
	tree.PrintInfix();
	cout << endl;

	cout << "postfix: ";
	tree.PrintPostfix();
	cout << endl;

	cout << "prefix: ";
	tree.PrintPrefix();
	cout << endl;

	return 0;
}