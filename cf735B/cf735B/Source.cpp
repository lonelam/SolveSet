#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 100000 + 20;
int a[maxn];
int main()
{
	int n1, n2, n;
	while (scanf("%d%d%d", &n, &n1, &n2) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
		}
		sort(a, a + n);
		if (n1 > n2) swap(n1, n2);//n1 < n2;
		double sum1 = 0, sum2 = 0;
		for (int i = n - 1; i > n - 1 - n1; i--)
		{
			sum1 += a[i];
		}
		for (int i = n - 1 - n1; i > n - 1 - n1 - n2; i--)
		{
			sum2 += a[i];
		}
		printf("%lf\n", sum1 / n1 + sum2 / n2);
	}
}