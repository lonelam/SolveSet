/* ***********************************************
Author        :kuangbin
横纵坐标都从1开始
外部调用dance(0)
ansd为ans数组的size
ans数组存了答案
************************************************ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
const int MaxM = 1010;
const int MaxN = 1010;
struct DLX
{
	int n, m, size;
	int U[maxnode], D[maxnode], R[maxnode], L[maxnode], Row[maxnode], Col[maxnode];
	int H[MaxN], S[MaxM];
	int ansd, ans[MaxN];
	int ans_[MaxN];
	void init(int _n, int _m)
	{
		n = _n;
		m = _m;
		ansd = inf;
		for (int i = 0; i <= m; i++)
		{
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[m] = 0; L[0] = m;
		size = m;
		for (int i = 1; i <= n; i++)
			H[i] = -1;
	}
	void Link(int r, int c)
	{
		++S[Col[++size] = c];
		Row[size] = r;
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if (H[r] < 0)H[r] = L[size] = R[size] = size;
		else
		{
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}
	void remove(int c)
	{
		L[R[c]] = L[c]; R[L[c]] = R[c];
		for (int i = D[c]; i != c; i = D[i])
			for (int j = R[i]; j != i; j = R[j])
			{
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				--S[Col[j]];
			}
	}
	void resume(int c)
	{
		for (int i = U[c]; i != c; i = U[i])
			for (int j = L[i]; j != i; j = L[j])
				++S[Col[U[D[j]] = D[U[j]] = j]];
		L[R[c]] = R[L[c]] = c;
	}
	//d为递归深度
	bool Dance(int d)
	{
		if (R[0] == 0)
		{
			if (d < ansd)
			{
				ansd = d;
				memcpy(ans_, ans, sizeof(ans));
			}
			return true;
		}
		bool ret = false;
		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])
			if (S[i] < S[c])
				c = i;
		remove(c);
		for (int i = D[c]; i != c; i = D[i])
		{
			ans[d] = Row[i];
			for (int j = R[i]; j != i; j = R[j])remove(Col[j]);
			if (Dance(d + 1)) ret = true;
			for (int j = L[i]; j != i; j = L[j])resume(Col[j]);
		}
		resume(c);
		return ret;
	}
};

DLX g;
int main()
{
	int t;
	int n, m, p;
	int x1, y1, x2, y2;
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d%d%d", &n, &m, &p);
			g.init(p, n * m);
			for (int k = 1; k <= p; k++)
			{
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				for (int i = x1; i < x2; i++)
				{
					for (int j = y1; j < y2; j++)
					{
						g.Link(k, i * n + j + 1);
					}
				}
			}
			if (!g.Dance(0))
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", g.ansd);
			}
		}
	}
}