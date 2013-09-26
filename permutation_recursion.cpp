/*
 * =====================================================================================
 *
 *       Filename:  permutation_recursion.cpp
 *
 *    Description:  implementat permutation with recursion methods
 *
 *        Version:  1.0
 *        Created:  2013/09/26 11时25分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Shuting (cst), cicy0125@gmail.com
 *        Company:  gucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
#include <string.h>
using namespace std;

void permutation(char *str, char *begin)
{
	if (*begin == '\0') {
		cout << ">>" << str << endl;
	}

	for (char *pos = begin; *pos != '\0'; pos++) {
		char tmp = *pos;
		*pos = *begin;
		*begin = tmp;

		permutation(str, begin+1);

		tmp = *pos;
		*pos = *begin;
		*begin = tmp;
	}
}

int main(int argc, char *argv[]) {

	if (argc == 2) {
		char *str = argv[1];
		permutation(str, str);
	} else {
		char str[] = "abc";
		permutation(str, str);
	}
	
}
