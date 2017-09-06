#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 100;
typedef long long ll;
typedef long double ld;
int grid[maxn][maxn];
int n, m;

int main()
{
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> grid[i][j];
			}
		}
		ll cnt = n * m;
		for (int i = 0; i < n; i++)
		{
			ll cl[2] = { 0,0 };
			for (int j = 0; j < m; j++)
			{
				cl[grid[i][j]]++;
			}
			cnt -= m + 2;
			cnt += (1LL << cl[0]);
			cnt += (1LL << cl[1]);
		}
		for (int j = 0; j < m; j++)
		{
			ll cl[2] = { 0,0 };
			for (int i = 0; i < n; i++)
			{
				cl[grid[i][j]]++;
			}
			cnt -= n + 2;
			cnt += (1LL << cl[0]);
			cnt += (1LL << cl[1]);
		}
		cout << cnt << endl;
	}
}