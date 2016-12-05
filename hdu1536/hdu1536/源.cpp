#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<set>
#include<cstdio>
#include<unordered_set>
using namespace std;
const int maxh = 10001;
const int maxsi = 10001;
const int maxl = 101;
int mem[maxh];
set<int> s;
int grundy(int n)
{
	if (mem[n] != -1)
	{
		return mem[n];
	}
	bool aped[maxl];
	memset(aped, 0, sizeof(aped));
	for (int fac : s)
	{
		if(n>=fac)
		    aped[grundy( n - fac )] = true;
		else
		{
			break;
		}
	}
	int g = 0;
	while (aped[g])
	{
		g++;
	}
	return (mem[n] = g);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int k, si, m, l, hi;
	while (scanf("%d",&k)!=EOF && k)
	{

		memset(mem, -1, sizeof(mem));
		mem[0] = 0;
		s.clear();
		for (int i = 0; i < k; i++)
		{
			scanf("%d", &si);
			s.insert(si);
		}
		scanf("%d", &m);
		while (m--)
		{
			scanf("%d", &l);
			int nim = 0;
			for (int i = 0; i < l; i++)
			{
				scanf("%d", &hi);
				nim ^= grundy(hi);
			}
			if (nim == 0)
			{
				putchar('L');
			}
			else
			{
				putchar('W');
			}
		}
		putchar('\n');
	}
}