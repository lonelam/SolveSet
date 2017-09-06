#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
typedef long long ll;
typedef long double ld;
string grid[3];
set<string> legal;
void dfs(string & st, int flip)
{
	if (legal.find(st) != legal.end()) return;
	legal.insert(st);
	int won1 = 0, won2 = 0;
	map<char, int> diag, rdiag;
	for (int i = 0; i < 3; i++)
	{
		diag[st[i* 3 + i]]++;
		rdiag[st[i * 3 + 2 - i]]++;
		map<char, int> row;
		map<char, int> col;
		for (int j = 0; j < 3; j++)
		{
			row[st[i* 3 + j]]++;
			col[st[j* 3 +i]]++;
		}
		if (row['X'] == 3 || col['X'] == 3)
		{
			won1++;
		}
		if (row['0'] == 3 || col['0'] == 3)
		{
			won2++;
		}
	}
	if (diag['X'] == 3 || rdiag['X'] == 3)
	{
		won1++;
	}
	if (diag['0'] == 3 || rdiag['0'] == 3)
	{
		won2++;
	}
	if (won1 || won2)
	{
		return;
	}
	for (int i = 0; i < 9; i++)
	{
		if (st[i] == '.')
		{
			if (flip)
			{
				st[i] = '0';
			}
			else
			{
				st[i] = 'X';
			}
			dfs(st, flip ^ 1);
			st[i] = '.';
		}
	}
}
int main()
{
	string init = ".........";
	dfs(init, 0);
	for (int i = 0; i < 3; i++)
	{
		cin >> grid[i];
	}
	if (legal.find(grid[0] + grid[1] + grid[2]) == legal.end())
	{
		cout << "illegal\n";
		return 0;
	}
	map<char, int> cnt;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cnt[grid[i][j]]++;
		}
	}
	if (cnt['X'] < cnt['0'] || cnt['X'] > cnt['0'] + 1)
	{
		cout << "illegal\n";
	}
	else
	{
		int won1 = 0, won2 = 0;
		map<char, int> diag, rdiag;
		for (int i = 0; i < 3; i++)
		{
			diag[grid[i][i]]++;
			rdiag[grid[i][2 - i]]++;
			map<char, int> row;
			map<char, int> col;
			for (int j = 0; j < 3; j++)
			{
				row[grid[i][j]]++;
				col[grid[j][i]]++;
			}
			if (row['X'] == 3 || col['X'] == 3)
			{
				won1++;
			}
			if (row['0'] == 3 || col['0'] == 3)
			{
				won2++;
			}
		}
		if (diag['X'] == 3 || rdiag['X'] == 3)
		{
			won1++;
		}
		if (diag['0'] == 3 || rdiag['0'] == 3)
		{
			won2++;
		}
		if (won1 && won2)
		{
			cout << "illegal\n";
		}
		else if (won1)
		{
			cout << "the first player won\n";
		}
		else if (won2)
		{
			cout << "the second player won\n";
		}
		else if (cnt['.'] == 0)
		{
			cout << "draw\n";
		}
		else if (cnt['X'] == cnt['0'])
		{
			cout << "first\n";
		}
		else if (cnt['0'] < cnt['X'])
		{
			cout << "second\n";
		}
	}
	
}