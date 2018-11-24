#include "pch.h"
#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
class Element
{
public:
	Element* next;
	T data;

	Element(Element* next, T data) : next(next), data(data) {}
};

template <typename T>
class Stack
{
private:
	Element<T>* begin;
public:
	Stack() : begin(nullptr) {}

	T Push(T data)
	{
		Element<T>* newBegin = new Element<T>(this->begin, data);
		this->begin = newBegin;

		return data;
	}

	T Pop()
	{
		T oldData = this->begin->data;

		Element<T>* next = this->begin->next;
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