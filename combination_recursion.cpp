/*
 * =====================================================================================
 *
 *       Filename:  combination_recursion.cpp
 *
 *    Description:  implementat combination in recursion method
 *
 *        Version:  1.0
 *        Created:  2013/09/26 14时48分49秒
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
typedef string::iterator StringItr;

void _combination(string& str, StringItr current, int m, char *b, int index)
{
	if (current == str.end())
		return;
	
	//don't choose current pos
	_combination(str, current+1, m, b, index);

	//choose current pos
	b[++index] = *current;
	_combination(str, current+1, m, b, index);

	if (index == (m-1)) {
		b[m] = '\0';
		cout << b << endl;
	}
}

void combination(string& str) 
{
	char b[str.size() + 1];
	for (int i = 1; i < str.size(); i++ ) {
		_combination(str, str.begin(), i, b, -1);
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
