#include "pch.h"
#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
class Element
{
public:
	shared_ptr<Element> next;
	T data;

	Element(shared_ptr<Element> next, T data) : next(next), data(data) {}
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
		T oldData = this->begin->data;
		this->begin = this->begin->next;

		return oldData;
	}

	bool IsEmpty()
	{
		return this->begin == nullptr;
	}
};

int main()
{
	Stack<char> collection;
	
	char symbol = ' ';
	string line;
	getline(cin, line);
	istringstream iss(line);
	while (iss >> symbol)
	{
		collection.Push(symbol);
	}

	while (!collection.IsEmpty())
	{
		cout << collection.Pop();
	}
	cout << endl;

	return 0;
}