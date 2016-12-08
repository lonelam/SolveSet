#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int euler_phi(int n)
{
	int m = (int)sqrt(n + 0.5);
	int ans = n;
	for (int i = 2; i <= m; i++)
	{
		if (n % i == 0)
		{
			ans = ans / i * (i - 1);
			while (n % i == 0)
			{
				n /= i;
			}
		}
	}
	if (n > 1)
	{
		ans = ans / n * (n - 1);
	}
	return ans;
}
const int maxn = 50005;
int phi[maxn];

void phi_table()
{
	memset(phi, 0, sizeof(phi));
	phi[1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		if (!phi[i])
		{
			for (int j = i; j < maxn; j += i)
			{
				if (!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i *(i - 1);
			}
		}
	}
}
int main()
{
	int n;
	phi_table();
	while (scanf("%d", &n) != EOF && n)
	{
		int f = 0;
		for (int i = 2; i <= n; i++)
		{
			f += phi[i];
		}
		printf("%d\n", 2 * f + 1);
	}
}
