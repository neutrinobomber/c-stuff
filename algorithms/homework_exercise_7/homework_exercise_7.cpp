#include "pch.h"
#include <iostream>

using namespace std;

struct Node
{
private:
	shared_ptr<Node> next;
	int data;
public:
	Node(int data) : data(data), next(nullptr) {}

	void SetNext(shared_ptr<Node> next)
	{
		this->next = next;
	}

	shared_ptr<Node> GetNext() const
	{
		return this->next;
	}

	int GetData() const
	{
		return this->data;
	}
};

class List
{
private:
	shared_ptr<Node> begin;

public:
	List() : begin(nullptr) {}

	void Insert(int data)
	{
		auto container = make_shared<Node>(data);

		if (this->begin == nullptr)
		{
			this->begin = container;
			this->begin->SetNext(nullptr);
		}
		else if (this->begin->GetData() > container->GetData())
		{
			container->SetNext(this->begin);
			this->begin = container;
		}
		else
		{
			auto currentPtr = this->begin;
			auto previousPtr = currentPtr;

			while (currentPtr != nullptr && currentPtr->GetData() < container->GetData())
			{
				previousPtr = currentPtr;
				currentPtr = currentPtr->GetNext();
			}

			container->SetNext(currentPtr);
			previousPtr->SetNext(container);
		}
	}

	friend ostream& operator<<(ostream& stream, const List& data);
};

ostream& operator<<(ostream& stream, const List& data)
{
	auto ptr = data.begin;
	while (ptr != nullptr)
	{
		stream << ptr->GetData() << " ";
		ptr = ptr->GetNext();
	}

	return stream;
}

int main()
{
	List data;
	data.Insert(2);
	data.Insert(3);
	data.Insert(1);
	data.Insert(3);

	cout << data << endl;

	return 0;
}