#include "pch.h"
#include <iostream>

using namespace std;

class Element
{
public:
	Element* next;
	int data;

	Element() : next(nullptr), data(0) {}
	Element(Element* next, int data) : next(next), data(data) {}
};

class Stack
{
private:
	Element* begin;
public:
	Stack() : begin(nullptr) {}

	int Push(int data)
	{
		Element* newBegin = new Element;
		newBegin->data = data;
		newBegin->next = this->begin;
		this->begin = newBegin;

		return data;
	}

	int Pop()
	{
		int oldData = this->begin->data;

		Element* next = this->begin->next;
		delete this->begin;
		this->begin = next;

		return oldData;
	}

	bool IsEmpty()
	{
		return this->begin == nullptr;
	}
};

int main()
{
	Stack test;
	test.Push(1);
	test.Push(2);
	test.Push(3);

	while (!test.IsEmpty())
	{
		cout << test.Pop() << endl;
	}

	return 0;
}