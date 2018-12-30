#include "pch.h"
#include <iostream>

using namespace std;

template <typename T>
struct Element
{
private:
	shared_ptr<Element> next;
	T data;
public:
	Element(shared_ptr<Element> next, T data) : next(next), data(data) {}

	T GetData() const
	{
		return this->data;
	}

	shared_ptr<Element> GetNext() const
	{
		return this->next;
	}
};

template <typename T>
class Stack
{
private:
	shared_ptr<Element<T>> begin;
public:
	Stack() : begin(nullptr) {}

	T Push(T data)
	{
		this->begin = make_shared<Element<T>>(this->begin, data);
		return data;
	}

	T Pop()
	{
		T oldData = this->begin->GetData();
		this->begin = this->begin->GetNext();

		return oldData;
	}

	bool IsEmpty()
	{
		return this->begin == nullptr;
	}
};

template <typename T>
ostream& operator<<(ostream& stream, Stack<T>& data)
{
	while (!data.IsEmpty())
	{
		stream << data.Pop() << " ";
	}

	return stream;
}

template <typename T>
class Node
{
private:
	T data;
	shared_ptr<Node> left;
	shared_ptr<Node> right;

public:
	Node() {}
	Node(T data) : data(data), left(nullptr), right(nullptr) {}

	T GetData() const
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

template <typename T>
class Tree
{
private:
	shared_ptr<Node<T>> root;
	Stack<T> printContainer;

	void Infix(shared_ptr<Node<T>> node)
	{
		if (node == nullptr)
		{
			return;
		}

		Infix(node->GetLeft());
		cout << node->GetData() << " ";
		printContainer.Push(node->GetData());
		Infix(node->GetRight());
	}
public:
	Tree() : root(nullptr) {}

	void Insert(T data)
	{
		if (this->root == nullptr)
		{
			this->root = make_shared<Node<T>>(data);
			return;
		}

		shared_ptr<Node<T>> location = this->root;
		shared_ptr<Node<T>> previousLocation = location;
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
			location = make_shared<Node<T>>(data);

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

	void PrintInfix()
	{
		this->Infix(root);
	}

	void PrintStack()
	{
		cout << this->printContainer;
	}
};

int main()
{
	Tree<int> bst;
	bst.Insert(1);
	bst.Insert(2);
	bst.Insert(3);

	cout << "tree: ";
	bst.PrintInfix();
	cout << endl;

	cout << "stack: ";
	bst.PrintStack();
	cout << endl;

	return 0;
}