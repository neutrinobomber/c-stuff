#include "pch.h"
#include <iostream>

using namespace std;

class Node
{
private:
	int data;
	shared_ptr<Node> left;
	shared_ptr<Node> right;

public:
	Node() {}
	Node(int data) : data(data), left(nullptr), right(nullptr) {}

	int GetData() const
	{
		return this->data;
	}

	shared_ptr<Node> GetLeft() const
	{
		return this->left;
	}

	shared_ptr<Node> GetRight() const
	{
		return this->right;
	}

	void SetLeft(shared_ptr<Node> newLeft)
	{
		this->left = newLeft;
	}

	void SetRight(shared_ptr<Node> newRight)
	{
		this->right = newRight;
	}
};

class Tree
{
private:
	shared_ptr<Node> root;

	void Prefix(shared_ptr<Node> node)
	{
		if (node == nullptr)
		{
			return;
		}

		cout << node->GetData() << " ";
		Prefix(node->GetLeft());
		Prefix(node->GetRight());
	}
public:
	Tree() : root(nullptr) {}

	void Insert(int data)
	{
		if (this->root == nullptr)
		{
			this->root = make_shared<Node>(data);
			return;
		}

		shared_ptr<Node> location = this->root;
		shared_ptr<Node> previousLocation = location;
		bool found = false;

		while (!found && location != nullptr)
		{
			previousLocation = location;
			found = location->GetData() == data;

			if (location->GetData() > data)
			{
				location = location->GetLeft();
			}
			else
			{
				location = location->GetRight();
			}
		}

		if (!found)
		{
			location = make_shared<Node>(data);

			if (previousLocation->GetData() > data)
			{
				previousLocation->SetLeft(location);
			}
			else
			{
				previousLocation->SetRight(location);
			}
		}
	}

	void PrintPrefix()
	{
		this->Prefix(root);
	}
};

int main()
{
	Tree bst;
	bst.Insert(1);
	bst.Insert(2);
	bst.Insert(3);

	bst.PrintPrefix();

	return 0;
}