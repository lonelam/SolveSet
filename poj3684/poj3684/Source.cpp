#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10005;
double hs[maxn];
int main()
{
	int c, n, h, t, k;
	double r;
	scanf("%d", &c);
	for (int kase = 1; kase <= c; kase++)
	{
		scanf("%d%d%lf%d", &n, &h, &r, &t);
		const double T = sqrt( h / 5.0);
		r = r / 100;
	//	k = floor(t / T);
		for (int i = 0; i < n; i++)
		{
			//const double T = sqrt(h / 5.0);
			k = int((t - i) / T);
			if (t < i)
			{
				hs[i] = h;
			}
			else
			{
				if (k & 1)
				{
					hs[i] = h - 5.0 * (k * T + T - t + i) * (k * T + T - t + i);
				}
				else
				{
					hs[i] =h- 5.0 * (t - k * T - i) * (t - k * T - i);
				}
			}
		}
		sort(hs, hs + n);
		printf("%.2f", hs[0]);
		for (int i = 1; i < n; i++)
		{
			printf(" %.2f", hs[i] + r * i * 2);
		}
		printf("\n");
	}
	return 0;
}