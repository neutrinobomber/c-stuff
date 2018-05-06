// start main.cpp
/*
	1. Опит за записване на данни във файл, който се използва от друга програма. Препълване на стек. Делене на нула.
	2. Да се пише код, който няма шанс да аварира.
	3. Кода на връщане не е консистентен при всички функции и можем да се объркаме за типа на грешката.
	4. Чрез запазването на код на грешка в глобална променлива, не е ясно в коя функция е възникнала грешката. Също не може да се определи причината за възникване на грешката.
	5. Програмата приключва изпълнението си при всяка възникнала грешка и така може да се изгуби потребителска информация.
	6. Assert ни казва на кой ред е възникнала грешката и при какво условие.
	7. Този механизъм е стандартизиран и много гъвкав и можем да обработваме много видове грешки без да прекратяваме програмата, чрез което имаме по-голям контрол над изпълнението.
	10. Изпълнява се кода след края на този try блок.
	11. Програмата аварира.
	12. Изключението се прихваща от най-близката catch клауза.
	13. Изключението се повдига повторно и може да се прихване от друг catch.
	15. Потребителски дефинираните exception-и ни дават възможност за по-голяма гъвкавост на error handling-а. Чрез наследяване на стандартните изключения, можем да се възползваме от полиморфизъм при прихващането на грешките.
	16. Когато искаме при възникване на грешка програмата да прекъсне изпълнението си без предупреждение.
	17. Обекта "a" се унищожава, а при обекта "b" имаме memory leak.
	18. void f() throw () указва че няма да хвърля никакви exception-и, и дори да хвърли exception, няма да може да се прихване. void f() може да хвърля всякакви exception-и.
	19. - void f() throw(bad_alloc)
		- void f() throw ()
		- void f() throw (...)
	20. - Програмата ще прекрати изпълнението си.
		- Това изключение ще трябва да се прихване чрез catch на по-базово изключение или специфичния тип изключение.
*/

#include <stdexcept>
#include <iostream>

#include "CStudent.h"

using namespace std;

void task_8()
{
	throw runtime_error("Network failure");
	throw "Network failure";
	throw 13;
}

void task_9()
{
	try
	{
		task_8();
	}
	catch (const runtime_error & err)
	{
		cout << err.what() << endl;
	}

	try
	{
		throw "Network failure";
	}
	catch (const char * err)
	{
		cout << err << endl;
	}

	try 
	{
		throw 13;
	}
	catch (const int err)
	{
		cout << err << endl;
	}
}

void task_14()
{
	try
	{
		throw logic_error("error");
	}
	catch (const logic_error & err)
	{
		cout << err.what() << endl;
	}

	try
	{
		throw runtime_error("error");
	}
	catch (const runtime_error & err)
	{
		cout << err.what() << endl;
	}

	try
	{
		throw exception("error");
	}
	catch (...)
	{
		cout << "any error" << endl;
	}
}

void task_21()
{
	const int len = 3;
	CStudent stud[len];

	for (size_t i = 0; i < len; i++)
	{
		cout << "student[" << i << "]:" << endl;
		stud[i].read();
	}

	CStudent best = stud[0];
	for (size_t i = 0; i < len; i++)
	{
		if (stud[i] > best)
		{
			best = stud[i];
		}
	}

	cout << "best student: " << endl << best << endl;
}

int main()
{
	task_21();
		
	return 0;
}
// end main.cpp