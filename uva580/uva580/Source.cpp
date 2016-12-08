#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
const int maxn = 30000;
int f[maxn] = {};

int main()
{
	for (int k = 3; k < maxn; k++)
	{
		f[k] = 1 << (k - 3);
		for (int i = 2; i < k - 1; i++)
		{
			f[k] += ((1 << (i - 2)) - f[i - 2]) << (k - i - 2);
		}
	}
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		printf("%d\n", f[n]);
	}
}
