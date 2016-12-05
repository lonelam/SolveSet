#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<cstring>
#include <cstdio>
using namespace std;
const int maxn = 1000;
int n, W, cash;
const int maxc = 100000 + 50;
int w[maxn],  m[maxn];
bool dp[maxc];

int knapsack()
{
	///int maxn = 0;
	memset(dp, 0, sizeof(dp));
	dp[0] = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = cash; j >= w[i]; j--)
		{
			dp[j] = dp[j] || dp[j - w[i]] ;
		}
	}
	for (int j = cash; j >= 0; j--)
	{
		if (dp[j]) return j;
	}
}

void expand(int origin_n)
{
	for (int i = 0; i < origin_n; i++)
	{
		int j;
		for (j = 2; j << 1 <= m[i]; j <<= 1)
		{
			w[n++] = w[i] * j;
		}
		w[n++] = w[i] * (m[i] - j + 1);
	}
}


int main()
{
	while (scanf("%d%d", &cash, &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", m + i, w + i);
			if (m[i] == 0) w[i] = 0;
		}
		expand(n);
		printf("%d\n", knapsack());
	}
}
/*

735 3  4 125  6 5  3 350
735 3  2 125 2 5 3 100
633 4  500 30  6 100  1 5  0 1
735 0
0 3  10 100  10 50  10 10



*/