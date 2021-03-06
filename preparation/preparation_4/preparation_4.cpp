// preparation_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

void print_array(int * arr, unsigned sz);

unsigned set_power(char *, unsigned);
unsigned set_difference_power(int *, unsigned, int *, unsigned, unsigned &);
void set_difference(int *, unsigned, int *, unsigned, int *, unsigned &);
bool sub_set(int *, unsigned, int *, unsigned);
bool is_equal_ver1(int *, unsigned, int *, unsigned);
bool is_equal_ver2(char *, char *);
void gen_kset(int * set, unsigned sz, unsigned k, unsigned curr, unsigned cnt1, unsigned cnt0);
void gen_elem_kset(int * uset, int * set, unsigned sz, int elem, unsigned curr);
void gen_not_elem_kset(int * uset, int * set, unsigned sz, int elem, unsigned curr);
bool in_array(unsigned * arr, unsigned sz, unsigned val);
void gen_with_elems_from_set(int * uset, unsigned sz, int * elems, unsigned szE, int * set, unsigned curr);

void swap(int *, int *);
void permute(int *, int, int);
void combination(int *, unsigned, unsigned, unsigned, unsigned);

int main()
{
	const unsigned sz = 5;
	int uarr[sz] = { 1, 2, 3, 4, 5 };
	char bitmask_a[] = "10110";

	/*Задача 1.*/
	cout << "Set power: " << set_power(bitmask_a, sz) << endl;

	/*Задача 2.*/
	int arr_b[3] = { 3, 4, 5 };
	unsigned sz_r;

	set_difference_power(uarr, sz, arr_b, 3, sz_r);
	int * res = new int[sz_r];
	cout << "Set A: ";
	print_array(uarr, sz);
	cout << "Set B: ";
	print_array(arr_b, 3);
	cout << "Difference between A and B: ";
	set_difference(uarr, sz, arr_b, 3, res, sz_r);
	print_array(res, sz_r);

	delete[] res;
	res = NULL;

	/*Задача 3.*/
	int arr_a[4] = { 1, 3, 4, 6 };
	cout << "Universal set: ";
	print_array(uarr, sz);
	cout << "Set A: ";
	print_array(arr_a, 4);
	cout << "Is set A subset to the unversal set? " << (sub_set(uarr, sz, arr_a, 4) ? "Yes" : "No") << endl;

	/*Задача 4.*/
	int arr_c[5] = { 1, 2, 3, 4, 5 };
	cout << "Universal set: ";
	char bset_u[] = "11111";
	char bset_a[] = "11111";
	print_array(uarr, sz);
	cout << "Set C: ";
	
	print_array(arr_c, 5);
	cout << "Is equal set C to the universal: " << (is_equal_ver1(uarr, sz, arr_c, 5) ? "Yes" : "No") << endl;
	cout << "Is equal set C to the universal: " << (is_equal_ver2(bset_u, bset_a) ? "Yes" : "No") << endl;

	/*Задача 5.*/
	int * set = new int[3];
	cout << "Genetate all subset bitmasks with exactly 2 elements: " << endl;
	gen_kset(set, 3, 2, 0, 0, 0);
	cout << endl;
	delete[] set;
	set = NULL;

	/*Задача 7.*/
	int subset[sz];
	cout << "Genetate all subsets of the universal set, that have element with value 4: " << endl;
	gen_elem_kset(uarr, subset, sz, 4, 0);

	/*Задача 8.*/
	cout << "Genetate all subsets of the universal set, that does not have element with value 4: " << endl;
	gen_not_elem_kset(uarr, subset, sz, 4, 0);

	/*Задача 9.*/
	int elems[3] = { 1, 3, 5 };
	cout << "Genetate all subsets of the universal set, that have all elements from sub set B: " << endl << "Subset B: ";
	print_array(elems, 3);
	cout << "Subsets: " << endl;
	gen_with_elems_from_set(uarr, sz, elems, 3, subset, 0);

	cout << endl << endl;
	const int n = 3;
	int arr[n] = { 1, 2, 3 };
	permute(arr, 0, n - 1);

	cout << endl << endl;
	int * arr_comb = NULL;
	unsigned n_comb, k;
	do 
	{
		cout << "Please enter n: ";
		cin >> n_comb;
		cout << "Please enter k: ";
		cin >> k;
	} while (n_comb < k);
	arr_comb = new int[k];
	combination(arr_comb, 1, n_comb, 0, k);
	delete[] arr_comb;

	return 0;
}

void combination(int * a, unsigned start, unsigned n, unsigned k, unsigned maxk) 
{
	if (k >= maxk) 
	{
		for (unsigned i = 0; i < maxk; i++)
			cout << a[i] << "\t";
		cout << endl;
	}
	else 
	{
		for (unsigned i = start; i <= n; i++) 
		{
			a[k] = i;
			combination(a, i + 1, n, k + 1, maxk);
		}
	}
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permute(int *a, int l, int r)
{
	int i;
	if (l == r) 
	{
		for (int j = 0; j <= r; j++)
			cout << a[j] << "\t";
		cout << endl;
	}

	else
	{
		for (i = l; i <= r; i++)
		{
			swap(a[l], a[i]);
			permute(a, l + 1, r);
			swap(a[l], a[i]); //backtrack
		}
	}
}

void print_array(int * arr, unsigned sz)
{
	for (unsigned i = 0; i < sz; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

unsigned set_power(char * bm, unsigned sz) 
{
	unsigned cnt = 0;
	for (unsigned i = 0; i < sz; i++)
		if (bm[i] == '1') cnt++;
	return cnt;
}

unsigned set_difference_power(int * set_a, unsigned sz_a, int * set_b, unsigned sz_b, unsigned & sz_r)
{
	sz_r = 0;
	unsigned i, j, k = 0;
	for (i = 0; i < sz_a; i++) 
	{
		for (j = 0; j < sz_b; j++) 
			if (set_a[i] == set_b[j]) 
				break;
		if (j == sz_b)
			sz_r++;
	}
	return sz_r;
}

void set_difference(int * set_a, unsigned sz_a, int * set_b, unsigned sz_b, int * set_r, unsigned & sz_r) 
{
	unsigned i, j, k = 0;
	for (i = 0; i < sz_a; i++) 
	{
		for (j = 0; j < sz_b; j++)
			if (set_a[i] == set_b[j]) 
				break;
		if (j == sz_b)
			set_r[k++] = set_a[i];
	}
}

bool sub_set(int * set_a, unsigned sz_a, int * set_b, unsigned sz_b) 
{
	unsigned cnt = 0, i, j;
	for (i = 0; i < sz_b; i++)
		for (j = 0; j < sz_a; j++)
			if (set_b[i] == set_a[j]) 
				cnt++;
	return (cnt == sz_b);
}

bool is_equal_ver1(int * set_a, unsigned sz_a, int * set_b, unsigned sz_b) 
{
	unsigned szR;
	set_difference_power(set_a, sz_a, set_b, sz_b, szR);
	return (szR == 0);
}

bool is_equal_ver2(char * bset_a, char * bset_b) 
{
	unsigned bsetR = strlen(bset_a), cnt = 0;
	for (unsigned i = 0; i < bsetR; i++) 
		if ((bset_a[i] ^ bset_b[i]) == 0) 
			cnt++;
	return (cnt == bsetR);
}

void gen_kset(int * set, unsigned sz, unsigned k, unsigned curr, unsigned cnt1, unsigned cnt0) 
{
	if (curr == sz) 
		print_array(set, sz);
	else 
	{
		if (cnt1 < k) 
		{
			set[curr] = 1;
			gen_kset(set, sz, k, curr + 1, cnt1 + 1, cnt0);
		}
		if (cnt0 < sz - k) 
		{
			set[curr] = 0;
			gen_kset(set, sz, k, curr + 1, cnt1, cnt0 + 1);
		}
	}
}

void gen_elem_kset(int * uset, int * set, unsigned sz, int elem, unsigned curr)
{
	if (curr == sz) 
		print_array(set, sz);
	else 
	{
		unsigned ind = 0;
		for (unsigned i = 0; i < sz; i++) 
		{
			if (uset[i] == elem) 
			{
				ind = i;
				break;
			}
		}
		if (curr != ind) 
		{
			set[curr] = 0;
			gen_elem_kset(uset, set, sz, elem, curr + 1);
			set[curr] = 1;
			gen_elem_kset(uset, set, sz, elem, curr + 1);
		}
		else 
		{
			set[ind] = 1;
			gen_elem_kset(uset, set, sz, elem, curr + 1);
		}
	}
}

void gen_not_elem_kset(int * uset, int * set, unsigned sz, int elem, unsigned curr) 
{
	if (curr == sz) 
		print_array(set, sz);
	else 
	{
		unsigned ind = 0;
		for (unsigned i = 0; i < sz; i++) 
		{
			if (uset[i] == elem) 
			{
				ind = i;
				break;
			}
		}
		if (curr != ind) 
		{
			set[curr] = 0;
			gen_not_elem_kset(uset, set, sz, elem, curr + 1);
			set[curr] = 1;
			gen_not_elem_kset(uset, set, sz, elem, curr + 1);
		}
		else 
		{
			set[ind] = 0;
			gen_not_elem_kset(uset, set, sz, elem, curr + 1);
		}
	}
}
bool in_array(unsigned * arr, unsigned sz, unsigned val) 
{
	for (unsigned i = 0; i < sz; i++) 
		if (arr[i] == val) 
			return true;
	return false;
}

void gen_with_elems_from_set(int * uset, unsigned sz, int * elems, unsigned sz_e, int * set, unsigned curr) 
{
	if (curr == sz)
		print_array(set, sz);
	else 
	{
		unsigned * ind = new unsigned[sz_e];
		for (unsigned j = 0; j < sz_e; j++)
		{
			for (unsigned i = 0; i < sz; i++) 
			{
				if (uset[i] == elems[j]) 
				{
					ind[j] = i;
					break;
				}
			}
		}
		if (!in_array(ind, sz_e, curr))
		{
			set[curr] = 0;
			gen_with_elems_from_set(uset, sz, elems, sz_e, set, curr + 1);
			set[curr] = 1;
			gen_with_elems_from_set(uset, sz, elems, sz_e, set, curr + 1);
		}
		else 
		{
			set[curr] = 1;
			gen_with_elems_from_set(uset, sz, elems, sz_e, set, curr + 1);
		}
	}
}