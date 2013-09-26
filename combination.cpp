/*
 * =====================================================================================
 *
 *       Filename:  combination.cpp
 *
 *    Description:  implementat combination without recursion
 *
 *        Version:  1.0
 *        Created:  2013/09/26 15时44分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Shuting (cst), cicy0125@gmail.com
 *        Company:  gucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

void print_result(string& str, int *loc)
{
	int length = str.size();
	for (int i = 0; i < length; i++) {
		if (loc[i])
			cout << str[i];
	}
	cout << endl;
}

int first_1_pos(int *loc, int length)
{
	for (int i = 0; i < length; i++) {
		if(loc[i]) {
			return i;
		}
	}
	return -1;
}

int first_10_pos(int *loc, int length)
{
	for (int i = 0; i < length - 1; i++) {
		if(loc[i] && loc[i+1] == 0) {
			return i;
		}
	}
	return -1;
}

void swap(int &a, int &b)
{
	a = b + a;
	b = a - b;
	a = a - b;
}

void move_1_to_left(int *loc, int end)
{
	for (int old = 0, pos = 0; old < end; old++) {
		if (loc[old] && pos != old) {
			loc[pos++] = 1;
			loc[old] = 0;
		}
	}
}

void _combination(string& str, int *loc, int m)
{
	//initialize loc array
	int length = str.size();
	for (int i = 0; i < length; i++) {
		if (i < m)
			loc[i] = 1;
		else 
			loc[i] = 0;
	}
	print_result(str, loc);

	int first_1 = first_1_pos(loc, length); 
	int end_condition = length - m;

	//loop to search all m combinations
	while (first_1 != end_condition) {
		int first_10 = first_10_pos(loc, length);

		swap(loc[first_10], loc[first_10+1]);
		move_1_to_left(loc, first_10);

		print_result(str, loc);
		
		first_1 = first_1_pos(loc, length);
	}
}

void combination(string& str)
{
	int length = str.size();
	int loc[length];
	for (int i = 1; i < length; i++) {
		_combination(str, loc, i);
	}
}

int main(int argc, char *argv[])
{
	if (argc == 2) {
		string str(argv[1]);
		combination(str);
	} else {
		string str = "abc";
		combination(str);
	}
	return 0;
}
