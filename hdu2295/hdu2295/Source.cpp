/* ***********************************************
Author        :kuangbin
横纵坐标都从1开始
外部调用dance(0)
ansd为ans数组的size
ans数组存了答案
************************************************ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<functional>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxnode = 100010;
const int maxn = 1010;
const int MaxN = 1010;

struct DLX
{
	int n, m, size;
	int U[maxnode], D[maxnode], R[maxnode], L[maxnode];
	int Row[maxnode], Col[maxnode];
	int H[MaxN], S[MaxN];
	int ansd, ans[MaxN];
	int K;
	void init(int _n, int _m)
	{
		n = _n;
		m = _m;
		for (int i = 0; i <= m; i++)
		{
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
			S[i] = 0;
		}
		R[m] = 0;
		L[0] = m;
		size = m;
		for (int i = 1; i <= n; i++)
		{
			H[i] = -1;
		}

	}
	void Link(int r, int c)
	{
		S[Col[++size] = c]++;
		Row[size] = r;
		U[size] = U[c];
		D[size] = c;
		D[U[c]] = size;
		U[c] = size;
		if (H[r] == -1)
		{
			H[r] = R[size] = L[size] = size;
		}
		else
		{
			R[size] = H[r];
			L[size] = L[H[r]];
			R[L[size]] = size;
			L[H[r]] = size;
		}
	}
	void remove(int c)
	{
		for (int i = D[c]; i != c; i = D[i])
		{
			L[R[i]] = L[i];
			R[L[i]] = R[i];
		}
	}
	void resume(int c)
	{
		for (int i = U[c]; i != c; i = U[i])
		{
			R[L[i]] = L[R[i]] = i;
		}
	}
	bool v[maxnode];
	int h()
	{
		int ret = 0;
		for (int c = R[0]; c != 0; c = R[c]) v[c] = true;
		for (int c = R[0]; c != 0; c = R[c])
		{
			if (v[c])
			{
				ret++;
				for (int i = D[c]; i != c; i = D[i])
				{
					for (int j = R[i]; j != i; j = R[j])
					{
						v[Col[j]] = false;
					}
				}
			}
		}
		return ret;
	}
	bool dance(int d)
	{
		if (d + h() > K)
		{
			return false;
		}
		if (R[0] == 0)
		{
			return d <= K;
		}
		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])
		{
			if (S[i] < S[c])
			{
				c = i;
			}
		}
		for (int i = D[c]; i != c; i = D[i])
		{
			for (int j = R[i]; j != i; j = R[j])
			{
				remove(j);
			}
			remove(i);
			if (dance(d + 1)) return true;
			resume(i);
			for (int j = L[i]; j != i; j = L[j])
			{
				resume(j);
			}
		}
		return false;
	}
};

DLX gg;
double dis[55][55];
int d_n;
double d_table[2505];
int m;
double rada_x[55];
double rada_y[55];
int n;
double citi_x[55];
double citi_y[55];
int k;
inline double dist(double x1, double y1, double x2, double y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

const double eps = 1e-8;
//returns the minimum of radar distance
double bs()
{
	int l = 0;
	int r = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d_table[r++] = dis[i][j] = dist(rada_x[i], rada_y[i], citi_x[j], citi_y[j]);
		}
	}
	gg.K = k;
	sort(d_table, d_table + r);
	
	//r = distance(d_table, unique(d_table, d_table + r));
	int low = 0, high = r;
	while (low < high)
	{
		int mid = (low + high) >> 1;
		double cur_d = d_table[mid];
		gg.init(m, n);
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dis[i][j] <= cur_d + eps)
				{
					gg.Link(i, j);
				}
			}
		}

		if (gg.dance(0))
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	return d_table[high];
}
int main()
{
	int t;
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d%d%d", &n, &m, &k);
			for (int i = 1; i <= n; i++)
			{
				scanf("%lf%lf", citi_x + i,citi_y + i);
			}
			for (int i = 1; i <= m; i++)
			{
				scanf("%lf%lf", rada_x + i, rada_y + i);
			}
			printf("%.6lf\n", sqrt(bs()));
		}
	}
}