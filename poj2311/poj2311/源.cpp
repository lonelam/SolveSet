#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<set>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX_WH = 200;
int mem[MAX_WH + 1][MAX_WH + 1];
int grundy(int w, int h)
{
	if (mem[w][h] != -1)
	{
		return mem[w][h];
	}
	set<int> s;
	for (int i = 2; w - i >= 2; i++)
	{
		s.insert(grundy(i, h) ^ grundy(w - i, h));
	}
	for (int i = 2; h - i >= 2; i++)
	{
		s.insert(grundy(w, i) ^ grundy(w, h - i));
	}
	int res = 0;
	while (s.count(res) != 0)
	{
		res++;
	}
	return mem[w][h] = res;
}
void solve(int w,int h)
{

	if (grundy(w, h) != 0)
	{
		puts("WIN");
	}
	else
	{
		puts("LOSE");
	}
}
int main()
{
	memset(mem, -1, sizeof(mem));
	int a, b;
	while (scanf("%d%d",&a,&b) != EOF)
	{
		solve(a, b);
	}
}