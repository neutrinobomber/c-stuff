#include <iostream>
#include <cassert>

#include "TraceFun.h"
#include "CountVar.h"
#include "CSchool.h"

using namespace std;

double fun(int a, int b) 
{
	TraceFun t("fun", cout);
	a *= a;
	cout << "a = " << a << endl;
	b *= b;
	cout << "b = " << b << endl;
	a += b;
	cout << "a = " << a << endl;

	return (double)a / b;
}

int sum(int a, int b) 
{
	TraceFun t("sum", cout);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	CountVar var(5., "var", cout);
	for (int i = 0; i < 20; i++) 
	{
		var + 4. / i;
		var = 6. / i;
		CountVar tmp(15.2, "tmp", cout);
		var = tmp;
		var*tmp;
	}

	return a + b;
}

int main()
{
	//fun(4, 5);
	//sum(3, 4);
	CStudent s1("Ivan", 2);
	s1.change_grade(4, 1);
	s1[0] = 6;
	cout << s1() << endl;
	CStudent s2("Mariq", 3);
	//!!!!!!!!!!!
	CStudent arrStud[2] = { s1, s2 };
	CSchool s("School1", 2, arrStud);
	cout << s << endl;

	return 0;
}