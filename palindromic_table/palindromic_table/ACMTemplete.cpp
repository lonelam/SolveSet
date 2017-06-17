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
const int maxn = 100000 + 100;
typedef long long ll;
typedef long double ld;
vector<int> grid[maxn];
vector<int> presum[maxn];
int n, m;
int a[maxn];
vector<int> presum[maxn];
int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n <= m)
		{
			for (int i = 0; i < n; i++)
			{
				grid[i].clear();
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
				    scanf("%d", a + i * n + j);
					grid[i].push_back(a[i * n + j]);
				}
			}
		}
		else
		{
			swap(n, m);
			for (int i = 0; i < n; i++)
			{
				grid[i].clear();
			}
			for (int j = 0; j < m; j++)
			{
				for (int i = 0; i < n; i++)
				{
					scanf("%d", a + i * n + j);
					grid[i].push_back(a[i * n + j]);
				}
			}
		}
		for (int j = 0; j < m; j++)
		{
			presum[j].clear();
			presum[j].push_back(0);
			for (int i = 0; i < n; i++)
			{
				presum[j].push_back(*presum[j].rbegin() + grid[i][j]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int k = i; k < n; k++)
			{
				//interval [i, k]
				
			}
		}
	}
}
