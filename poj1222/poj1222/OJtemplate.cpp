#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn = 100;
int equ, var;
int a[maxn][maxn];
int x[maxn];
int free_x[maxn];
int free_num;

int Gauss()
{
	int max_r, col, k;
	free_num = 0;
	for (k = 0, col = 0; k < equ && col < var; k++, col++)
	{
		//get the maximal pivot
		max_r = k;
		for (int i = k + 1; i < equ; i++)
		{
			if (abs(a[i][col]) > abs(a[max_r][col]))
			{
				max_r = i;
			}
		}
		if (a[max_r][col] == 0)
		{
			k--;
			free_x[free_num++] = col;
			continue;
		}
		if (max_r != k)
		{
			for (int j = col; j < var + 1; j++)
			{
				swap(a[k][j], a[max_r][j]);
			}
		}

		for (int i = k + 1; i < equ; i++)
		{
			if (a[i][col] != 0)
			{
				for (int j = col; j < var + 1; j++)
				{
					a[i][j] ^= a[k][j];
				}
			}
		}
	}
	for (int i = k; i < equ; i++)
	{
		if (a[i][col] != 0)
		{
			return -1;
		}
	}
	for (int i = var - 1; i >= 0; i--)
	{
		x[i] = a[i][var];
		for (int j = i + 1; j < var; j++)
		{
			x[i] ^= (a[i][j] && x[j]);
		}
	}
	return 0;
}
int n, m;
void init()
{
	memset(a, 0, sizeof(a));
	memset(x, 0, sizeof(x));
	equ = n * m;
	var = n * m;
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int t = i * n + j;
			a[t][t] = 1;
			if (i > 0) a[(i - 1) *n + j][t] = 1;
			if (i < n - 1) a[(i + 1) * n + j][t] = 1;
			if (j > 0) a[i * n + j - 1][t] = 1;
			if (j < m - 1) a[i * n + j + 1][t] = 1;
		}
	}*/
	for (int i = 0; i<var; i++)
	{
		int ta = i % 6, tb = i / 6;
		a[i][i] = 1;
		if (ta > 0)
			a[i][i - 1] = 1;
		if (ta < 5)
			a[i][i + 1] = 1;
		if (tb > 0)
			a[i][i - 6] = 1;
		if (tb < 4)
			a[i][i + 6] = 1;
	}


}
int kase;
void solve()
{
	init();
	for (int i = 0; i < equ; i++)
	{
		cin >> a[i][var];
	}
	int t = Gauss();

		cout << "PUZZLE #" << kase++ << endl;
		for (int i = 0; i < n; i++)
		{
			cout << x[i * m];
			for (int j = 1; j < m; j++)
			{
				cout << " " << x[i * m + j];
			}
			cout << endl;
		}
}
int main()
{
	n = 5;
	m = 6;
	kase = 1;
	int T;
	while (cin >> T)
	{
		while (T--)
		{
			solve();
		}
	}
	return 0;
}