#include "stdafx.h"

#include <iostream>
#include <sstream>

using namespace std;

char lower(char input)
{
	if ((input >= 65) && (input <= 90))
		input = input + 32;
	return input;
}

bool char_is_in_array(char * arr, const unsigned len, char search)
{
	for (unsigned i = 0; i < len; ++i)
		if (arr[i] == search)
			return true;
	return false;
}

bool is_number(char * str)
{
	int i = strtol(str, NULL, 10);
	if (i == 0L)
		return false;
	else
		return true;
}

void first_task()
{
	const unsigned vowels_count = 10;
	char vowels[vowels_count] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

	const unsigned max_chars = 8000;
	char input[max_chars];
	char letter = ' ';
	unsigned idx = 0;
	cout << "input: ";
	do
	{
		cin.get(letter);
		if (letter != '!') {
			input[idx++] = letter;
		}
	} while (letter != '!' && idx < max_chars);

	unsigned count = 0;
	for (int i = 0; i < max_chars; ++i)
	{
		if (char_is_in_array(vowels, vowels_count, input[i]))
			count++;
	}

	cout << "vowels count: " << count << endl << endl;
}

void second_task()
{
	const unsigned max_chars = 8000;
	char input[max_chars];
	cout << "input: ";
	cin.getline(input, max_chars);

	unsigned word_count = 0;
	for (int i = 0; i < max_chars; ++i)
	{
		if (input[i] == ' ')
			word_count += 1;
	}
	word_count++;
	cout << "word count: " << word_count << endl << endl;
}

void third_task()
{
	const unsigned max_chars = 8000;
	char input[max_chars];
	cout << "input: ";
	cin.getline(input, max_chars);

	char * token, *next_token;
	char input_copy[max_chars];
	strcpy_s(input_copy, input);
	token = strtok_s(input_copy, " ", &next_token);
	unsigned numbers_count = 0;
	while (token != NULL)
	{
		if (is_number(token))
			numbers_count++;

		token = strtok_s(NULL, " ", &next_token);
	}

	unsigned * numbers = new unsigned[numbers_count];
	token = strtok_s(input, " ", &next_token);
	unsigned idx = 0;
	while (token != NULL)
	{
		if (is_number(token))
		{
			numbers[idx] = strtol(token, NULL, 10);
			idx++;
		}

		token = strtok_s(NULL, " ", &next_token);
	}

	cout << "numbers in text: " << endl;
	for (int i = 0; i < numbers_count; ++i)
	{
		cout << numbers[i] << " ";
	}
	cout << endl << endl;
}

void fifth_task()
{
	const unsigned max_chars = 8000;
	char input[max_chars];
	cout << "input: ";
	cin.getline(input, max_chars);

	char * token, *next_token;
	char input_copy[max_chars];
	strcpy_s(input_copy, input);
	token = strtok_s(input_copy, " ", &next_token);
	unsigned words_count = 0;
	while (token != NULL)
	{
		words_count++;
		token = strtok_s(NULL, " ", &next_token);
	}

	unsigned * word_lengths = new unsigned[words_count];
	token = strtok_s(input, " ", &next_token);
	unsigned idx = 0;
	while (token != NULL)
	{
		word_lengths[idx] = (unsigned)strlen(token);
		idx++;

		token = strtok_s(NULL, " ", &next_token);
	}

	for (int i = 0; i < words_count; ++i)
		cout << word_lengths[i] << " ";
	cout << endl << endl;
}

void sixth_task()
{
	const unsigned letters_count = 53;
	char letters[letters_count] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const unsigned max_chars = 8000;
	char input[max_chars];
	cout << "input: ";
	cin.getline(input, max_chars);

	for (int i = 0; i < letters_count - 1; ++i)
	{
		char current_letter = letters[i];
		cout << current_letter << ": ";

		unsigned occurences = 0;
		unsigned idx = 0;
		char current_char = input[0];
		while (current_char != '\0')
		{
			current_char = input[idx++];
			if (current_char == current_letter)
				occurences++;
		}
		cout << occurences << endl;
	}
	cout << endl;
}

void seventh_task()
{
	const unsigned vowels_count = 10;
	char vowels[vowels_count] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

	const unsigned max_chars = 8000;
	char input[max_chars];
	cout << "input: ";
	cin.getline(input, max_chars);

	unsigned max = 0;
	char most_occured_vowel = vowels[0];
	for (int i = 0; i < vowels_count; ++i)
	{
		char current_vowel = vowels[i];
		char current_char = input[0];
		unsigned occurences = 0;
		unsigned idx = 0;
		while (current_char != '\0')
		{
			current_char = input[idx++];
			if (current_char == current_vowel)
				occurences++;
		}

		if (occurences > max)
		{
			max = occurences;
			most_occured_vowel = current_vowel;
		}
	}

	cout << most_occured_vowel << " has appeared most frequently: " << max << endl << endl;
}

int main()
{
	first_task();
	second_task();
	third_task();
	fifth_task();
	sixth_task();
	seventh_task();

	return 0;
}