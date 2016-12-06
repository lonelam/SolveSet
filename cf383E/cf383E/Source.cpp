#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
const int maxn = 100000 + 50;
int color[maxn * 2];
int part[maxn * 2];
int a[maxn], b[maxn];
	int N;
	int n;
bool dfs(int to, int co)
{
	color[to] = co;
	bool ok = true;
	for (int d = -1; d <= 1; d++)
	{
		if (color[(to + d - 1) % N] == color[(to + d) % N] && color[(to + d) % N] == color[(to + d + 1) % N])
		{
			color[to] = -1;
			return false;
		}
	}
	if (color[prt[to]] == -1)
	{
		if (!dfs(part[to], co ^ 1)) ok = false;
	}
		for (int d = -1; d <= 1; d++)
		{
			if (color[(to + d) % N] == -1)
			{
				if (!dfs((to + d) % N, co ^ 1)) if(!dfs((to + d) % N, co)) ok = false;
			}
		}
		if (ok) return true;

	color[to] = -1;
	return false;
}

int main()
{
	int boy, girl;
	while (scanf("%d", &n)!= EOF)
	{
		N = 2 * n;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &boy, &girl);
			a[i] = boy - 1;
			b[i] = girl - 1;
			part[a[i]] = b[i];
			part[b[i]] = a[i];
		}
		memset(color, -1, sizeof(color));
		for (int i = 0; i < N; i++)
		{
			if (color[i] == -1)
			{
				dfs(i, 0);
			}
		}
		for (int i = 0; i < n; i++)
		{
			printf("%d %d\n", color[a[i]] + 1, color[b[i]] + 1);
		}
	}
}