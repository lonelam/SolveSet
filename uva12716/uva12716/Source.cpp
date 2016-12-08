#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn = 30000005;
int gcd_m(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd_m(b, a % b);
}
int gcd(int a, int b)
{
	if (a < b)
	{
		return gcd_m(b, a);
	}
	return gcd_m(a, b);
}
vector<int> primes;

void p_init()
{
	bool nprime[maxn] = { 1, 1 };
	for (int i = 2; i < maxn; i++)
	{
		if (!nprime[i])
		{
			primes.push_back(i);
			for (int j = i + i; j < maxn; j += i)
			{
				nprime[j] = true;
			}
		}
	}
}
int ans[maxn];

void init() {
	for (int c = 1; c <= 30000000; c++) {
		for (int a = c << 1; a <= 30000000; a += c) {
			int b = a - c;
			if ((a^b) == a - b) ans[a]++;
		}
	}
	for (int i = 1; i <= 30000000; i++) ans[i] += ans[i - 1];
}

int main()
{
	int t, n, kase = 1;
	init();
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d", &n);
			printf("Case %d: %d\n", kase++, ans[n]);
		}
	}
}