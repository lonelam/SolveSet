#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
/*
-----------Answered by Lonelam---------
*
*          ┌─┐       ┌─┐
*       ┌──┘ ┴───────┘ ┴──┐
*       │                 │
*       │       ───       │
*       │  ─┬┘       └┬─  │
*       │                 │
*       │       ─┴─       │
*       │                 │
*       └───┐         ┌───┘
*           │         │
*           │         │
*           │         │
*           │         └──────────────┐
*           │                        │
*           │                        ├─┐
*           │                        ┌─┘
*           │                        │
*           └─┐  ┐  ┌───────┬──┐  ┌──┘
*             │ ─┤ ─┤       │ ─┤ ─┤
*             └──┴──┘       └──┴──┘
*                 神兽保佑
*                 代码无BUG!
*/
using namespace std;
map<char, char> mirror{ {'A','A'},{'b','d'},{'d','b'},{'H','H'},{'I','I'},{'J','L'},{'L','J'},{'M','M'},{'O','O'},{'T','T'},{'U','U'},{'V','V'},{'W','W'},{'X','X'},{'Y','Y'},{'m','m'} ,{'n','n'},{'o','o'},{'p','q'},{'q','p'},{'u','u'},{'v','v'},{'w','w'},{'x','x'},{'S','Z'},{'Z','S'},{'i','i'} };
bool is_s_string(string & s)
{
	int p = 0, q = s.size() - 1;
	while (p < q)
	{
		if (mirror[s[p]] == s[q])
		{
			p++;
			q--;
		}
		else
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string line;
	while (getline(cin, line))
	{
		if (is_s_string(line))
		{
			cout << "TAK\n";
		}
		else
		{
			cout << "NIE\n";
		}
	}
}