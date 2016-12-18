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
const int maxn = 200000 + 200;
int a[maxn];
int s0[maxn];
int fa[maxn];
int main()
{
	int n, t, k;
	while (cin >> n >> t >> k)
	{
		int diff = 0;
		s0[1] = 2;
		s0[0] = 1;
		a[0] = 1;
		for (int i = 1; i <= t; i++)
		{
			cin >> a[i];
			diff += max(0, a[i - 1] - a[i]);
			s0[i + 1] = s0[i] + a[i];
		}
		if (k < a[t] + diff)
		{
			cout << -1 << endl;
			return 0;
		}
		int mus = k - diff - a[t];
		for (int i = t; i >= 1; i--)
		{
			for (int j = 0; j < a[i]; j++)
			{
				if (j < a[i - 1] && mus == 0)
				{
					fa[s0[i] + j] = s0[i - 1] + j;
				}
				else
				{
					if (j < a[i - 1] && j != 0)
					{
						mus--;
					}
					fa[s0[i] + j] = s0[i - 1];
				}
			}
		}
		if (mus > 0)
		{
			cout << -1 << endl;
			return 0;
		}
		cout << n << endl;
		for (int i = n; i >= 2; i--)
		{
			cout << fa[i] << " " << i << endl;
		}
	}
	return 0;
}