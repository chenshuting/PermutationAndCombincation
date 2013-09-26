/*
 * =====================================================================================
 *
 *       Filename:  permutation.cpp
 *
 *    Description:  implementat permutation without recursion
 *
 *        Version:  1.0
 *        Created:  2013/09/26 11时34分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Shuting (cst), cicy0125@gmail.com
 *        Company:  gucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>
using namespace std;

typedef string::iterator StringItr;


void itr_swap(StringItr i, StringItr j)
{
	char tmp = *i;
	*i = *j;
	*j = tmp;
}

void reverse(StringItr i, StringItr j) {
	while (i < j) {
		itr_swap(i, j);
		++i, --j;
	}
}

bool next(string& str) 
{

	StringItr start = str.begin();
	StringItr end = str.end() - 1;
	if(start == end) {
		return false;
	}
	StringItr i = start; 
	++i;
	if (i == end)
		return false;
	i = end;

	while(true) {
		StringItr t = i;
		--i;
		if (*i < *t) {
			StringItr j = end;

			while(!(*i < *j))
				j--;
			
			itr_swap(i, j);
			reverse(t, end);
			return true;
		}

		if (i == start) {
			//all reverse, generate min dictionary
			reverse(start, end);
			return false;
		}
	}
}

void permutation(string& str)
{
	if (str.empty())
		return;
	
	StringItr start = str.begin();
	StringItr end = str.end();

	sort(start, end);
	do{
		cout << ">>" << str << endl;
	}while(next(str));
}

int main(int argc, char *argv[])
{
	if (argc == 2) {
		string str(argv[1]);
		permutation(str);
	} else {
		string str = "bac";
		permutation(str);
	}
}
