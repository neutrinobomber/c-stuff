#include "stdafx.h"

#include <iostream>

using namespace std;

void first_task()
{
	cout << "Alexander Anastasov Yankov" << endl;
}

void second_task() 
{
	cout << "university: New Bulgarian University" << endl;
	cout << "specialty: Informatics" << endl << endl;
}

void third_task()
{
	cout << "auto" << endl
		<< "double" << endl
		<< "break" << endl
		<< "else" << endl
		<< "case" << endl
		<< "enum" << endl
		<< "char" << endl
		<< "extern" << endl
		<< "const" << endl
		<< "float" << endl
		<< "continue" << endl
		<< "for" << endl
		<< "default" << endl
		<< "goto" << endl
		<< "do" << endl
		<< "if" << endl
		<< "int" << endl
		<< "long" << endl
		<< "register" << endl
		<< "return" << endl
		<< "short" << endl
		<< "signed" << endl
		<< "sizeof" << endl
		<< "static" << endl
		<< "struct" << endl
		<< "switch" << endl
		<< "typedef" << endl
		<< "union" << endl
		<< "unsigned" << endl
		<< "void" << endl
		<< "volatile" << endl
		<< "while" << endl
		<< "asm" << endl
		<< "bool" << endl
		<< "catch" << endl
		<< "class" << endl
		<< "const_cast" << endl
		<< "delete" << endl
		<< "dynamic_cast" << endl
		<< "explicit" << endl
		<< "false" << endl
		<< "friend" << endl
		<< "inline" << endl
		<< "mutable" << endl
		<< "namespace" << endl
		<< "new" << endl
		<< "operator" << endl
		<< "private" << endl
		<< "protected" << endl
		<< "public" << endl
		<< "reinterpret_" << endl
		<< "cast" << endl
		<< "static_cast" << endl
		<< "template" << endl
		<< "this" << endl
		<< "throw" << endl
		<< "true" << endl
		<< "try" << endl
		<< "typeid" << endl
		<< "typename" << endl
		<< "using" << endl
		<< "virtual" << endl
		<< "wchar_t" << endl << endl;
}

void fourth_task()
{
	cout << "Tokens are characters that are logically connected and together can create meaningful statements for the programming language." << endl;
	cout << "Types of tokens in c++: Keywords, Identifiers, Literals, Punctuators, Operators" << endl << endl;
	cout << "Literals are the values of the variables, specified by the programmer." << endl << endl;
	cout << "Commands are statements made by the programmer, which then get executed one after another." << endl << endl;
}

void fifth_task()
{
	cout << "\"#define\" is used for creation of constant values that can be used in the program" << endl;
	cout << "\"#undef\" is used to remove something created with \"#define\"" << endl;
	cout << "\"#include\" is used to include some library or header file in out code" << endl;
	cout << "the \"#if\" directive behaves the same way as the normal \"if\" statement, but gets evaluated compile-time" << endl;
	cout << "\"#ifdef\" checks if a value is defined compile-time" << endl;
	cout << "\"#ifndef\" checks if a value is not defined compile-time" << endl;
	cout << "\"#else\" can be placed after \"#if\". The code after \"#else\" gets compiled when the evaluation of \"#if\" is a negative(false or false-like) value" << endl;
	cout << "\"#elif\" can be placed after \"#if\" to perform another check in case \"#if\" has a false evaluation" << endl;
	cout << "\"#endif\" closes conditional directives like \"#if\" and \"#else\"" << endl;
	cout << "\"#line\" is used by the compiler to outline compile-time errors" << endl;
	cout << "\"#error\" causes a compilation to fail. Useful when we want to stop compilation when certain conditions are met" << endl;
	cout << endl;
}

void first_book_task()
{
	cout << "Not outputting task result because it includes non-ascii characters." << endl;
	cout << "Check the comment at the bottom of the file!" << endl << endl;
}

void second_book_task()
{
	cout << "Incorrect usage of directive on the first line." << endl << endl;
}

void third_book_task()
{
	cout << "short message :D" << endl;
	cout << endl;
}

void fourth_book_task()
{
	cout << "o   o\no   o\no   o\nooooo\no   o\no   o\no   o\n\n"
		<< "o o o\no\no\no o o\no\no\no o o\n\n"
		<< "o\no\no\no\no\no\nooooo\n\n"
		<< "o\no\no\no\no\no\nooooo\n\n"
		<< " ooo\no   o\no   o\no   o\no   o\no   o\n ooo \n\n\n"
		<< " ooo \no \no \no \no \no \n ooo \n\n"
		<< "\n  o\n  o\nooooo\n  o\n  o\n\n"
		<< "\n  o\n  o\nooooo\n  o\n  o\n\n";
}

void fifth_book_task()
{
	cout << "think of an integer number" << endl;
	cout << "multiply that number by 5" << endl;
	cout << "add 45 to the result" << endl;
	cout << "divide the result by 5" << endl;
	cout << "now subtract your number from the result" << endl;
	cout << "the result is 9" << endl << endl;
}

int main()
{
	first_task();
	second_task();
	third_task();
	fourth_task();
	fifth_task();

	first_book_task();
	second_book_task();
	third_book_task();
	fourth_book_task();
	fifth_book_task();

    return 0;
}

/*
задачи от сборник:
1. идентификатори -  а), б), д), е), л), м) 
   не-идентификатори - в), г), ж), з), и), к), н), о), п)
*/