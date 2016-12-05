#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1050;
const int maxm = maxn * maxn;

const double eps = 1e-4;
double len[maxn][maxn];
double da[maxn][maxn];
const double inf = 10000000;
bool vis[maxn];
double lowc[maxn];
double cost[maxn][maxn];
double prim(int n)
{
	double ans = 0;
	memset(vis, 0, sizeof(vis));
	vis[0] = true;
	for (int i = 1; i < n; i++) lowc[i] = cost[0][i];
	for (int i = 1; i < n; i++)
	{
		double minc = inf;
		int p = -1;
		for (int j = 0; j < n; j++)
		{
			if (!vis[j] && minc > lowc[j])
			{
				minc = lowc[j];
				p = j;
			}
		}
		if (minc == inf) return  - 1;
		ans += minc;
		vis[p] = true;
		for (int j = 0; j < n; j++)
		{
			if (!vis[j] && lowc[j] > cost[p][j])
			{
				lowc[j] = cost[p][j];
			}
		}
	}
	return ans;
}
double xs[maxn], ys[maxn], alti[maxn];
int main()
{
	int n;
	memset(cost, 0, sizeof(cost));
	while (scanf("%d", &n) != EOF && n)
	{
		double high = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf", xs + i, ys + i, alti + i);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				double dx = xs[i] - xs[j];
				double dy = ys[i] - ys[j];
				len[j][i] = len[i][j] = sqrt(dx * dx + dy * dy);
				
				da[j][i] = da[i][j] = abs(alti[i] - alti[j]);
				high = max(high, da[i][j]);
			}
		}
		double low = 0;
		while (high - low > eps)
		{
			const double mid = low + (high - low) / 2;
			for (int i = 0; i < n; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					cost[i][j] = cost[j][i] = da[i][j] - mid * len[i][j];
				}
			}
			
			const double g = prim(n);
			
			if (g < 0)
				high = mid;
			else low = mid;
		}
		printf("%.3f\n", low);
	}
}