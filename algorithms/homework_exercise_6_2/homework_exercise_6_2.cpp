#include "pch.h"
#include <iostream>
#include <sstream>
#include <memory>

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

int main()
{
	Stack<char> collection;
	
	cout << "input: ";
	char symbol = ' ';
	string line;
	getline(cin, line);
	istringstream iss(line);
	while (iss >> symbol)
	{
		collection.Push(symbol);
	}

	cout << "output: ";
	while (!collection.IsEmpty())
	{
		cout << collection.Pop();
	}
	cout << endl;

	return 0;
}