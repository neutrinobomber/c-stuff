// homework_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cmath>

using namespace std;

void first_task()
{
	bool bool_type;
	int int_type;
	char char_type;
	float float_type;
	double double_type;

	char res[6];
	cout << "give me a bool(true, false): ";
	cin >> res;
	if (strcmp(res, "true") == 0)
	{
		bool_type = true;
	}
	else if (strcmp(res, "false") == 0)
	{
		bool_type = false;
	}
	else
	{
		cout << "invalid input" << endl;
		return;
	}

	cout << "give me an integer: ";
	cin >> int_type;

	cout << "give a char: ";
	cin >> char_type;

	cout << "give me a float: ";
	cin >> float_type;

	cout << "give me a double: ";
	cin >> double_type;

	cout << "your bool: " << bool_type << endl;
	cout << "your int: " << int_type << endl;
	cout << "your char: " << char_type << endl;
	cout << "your float: " << float_type << endl;
	cout << "your double: " << double_type << endl << endl;
}

void second_task()
{
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a * b = " << a * b << endl;
	cout << "a / b = " << a / b << endl;
	cout << "a % b = " << a % b << endl << endl;
}

void third_task()
{
	double a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	a++;
	cout << "a++ : " << a << endl;
	b++;
	cout << "b++ : " << b << endl;
	a--;
	cout << "a-- : " << a << endl;
	b--;
	cout << "b-- : " << b << endl;

	cout << "++a : " << ++a << endl;
	cout << "++b : " << ++b << endl;
	cout << "--a : " << --a << endl;
	cout << "--b : " << --b << endl;

	cout << "a += b : " << (a += b) << endl;
	cout << "a -= b : " << (a -= b) << endl;
	cout << "a /= b : " << (a /= b) << endl;
	cout << "a %= b : " << ((int)a % (int)b) << endl << endl;
}

void fourth_task()
{
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl << endl;
}

void fifth_task()
{
	cout << "Bitwise operations are useful when we want to achieve maximum performance with mathematical expressions." << endl;
	cout << "A good example is a computer graphics engine. Bitwise operations are also useful for encryption and network programming when we work with sockets." << endl << endl;
}

void book_task_6()
{
	int years = 0;
	cout << "How old are you?" << endl;
	cin >> years;

	cout << "You have lived approximately " << (unsigned long long)(years * 365) << " days, "
		<< (unsigned long long)(years * 8760) << " hours and "
		<< (unsigned long long)(years * 525600) << " minutes" << endl << endl;
}

void book_task_7()
{
	double side, h;
	cout << "side = ";
	cin >> side;
	cout << "height = ";
	cin >> h;
	cout << "area = " << side * h / 2 << endl << endl;

	double a, b, c, p;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	p = (a + b + c) / 2;
	cout << "area = " << sqrt(p * (p - a) * (p - b) * (p - c)) << endl << endl;
}

void book_task_8()
{
	cout << "a / (b * c / (d * e / (f * h)));" << endl;
	cout << "(a + b) / (x - 2 * y);" << endl;
	cout << "a + b / (x - 2) * y;" << endl << endl;
}

void book_task_9()
{
	cout << "log(x * x + exp(x) + 10)" << endl;
	cout << "log(x * x * x * x + x * x + 8) / log(5)" << endl;
	cout << "pow(acos(x) - floor(y) - floor(z), 3) * exp(ceil(x) + 1.23)" << endl;
	cout << "(a - b * c) / pow(atan(a) - sinh(b) - cosh(c), 4)" << endl << endl;
}

void book_task_10()
{
	// в), г), д), е)
}

void book_task_11()
{
	// а) √(a + b) - √(a - b)
	// б) a + b : (c + d) - (a + b) : c + d
	// в) x . y : (u + v) - ((u - v) . (a + b)) : y

	//         cos(x + y) : 2
	// г) 1 + e
}

void book_task_12()
{
	/*
	а) 1 
	6) 1
	в) 0
	г) 0 
	д) 0
	е) 0
	ж) 2 
	з) 9 
	и) 3
	й) 1 
	к) 0
	*/
}

void book_task_13()
{
	double a;
	cout << "a = ";
	cin >> a;
	cout << "p = " << 4 * sqrt(a) << endl;

	double p;
	cout << "p = ";
	cin >> p;
	cout << "s = " << p * p * sqrt(3) / 36 << endl;
}

int main()
{
	first_task();
	second_task();
	third_task();
	fourth_task();
	fifth_task();

	book_task_6();
	book_task_7();
	book_task_8();
	book_task_9();
	book_task_10();
	book_task_11();
	book_task_12();
	book_task_13();

    return 0;
}