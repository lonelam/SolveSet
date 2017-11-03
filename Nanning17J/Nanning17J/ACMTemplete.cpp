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
const int maxn = 370000 + 100;
typedef long long ll;
typedef long double ld;
//map<string, bool> vis;
bool vis[maxn];
//map<int, bool> vis;
int power10[11];
int n;
int inline stat(int x)
{
	int ret = 0;
	static int f[10];
	for (int i = 1; i <= n; i++)
	{
		f[i] = i - 1;
	}
	for (int i = 0; i < n; i++)
	{
		int c = x % 10;
		x /= 10;
		ret *= (n - i);
		ret += f[c];
		for (int j = c; j <= n; j++)
		{
			f[j]--;
		}
	}
	return ret;
}
int bfs(int from, int to)
{
	memset(vis, 0, sizeof(vis));
	//vis.clear();
	queue<int> *cur = new queue<int>, *nex = new queue<int>;
	cur->push(from);
	int d = 0;
	vis[stat(from)] = true;
	while (!cur->empty())
	{
		while (!cur->empty())
		{
			int cc = cur->front(); cur->pop();
			if (cc == to) return d;
			//vis[c] = true;
			int yy = cc / power10[n - 1];
			for (int i = 0; i < n - 1; i++)
			{
				int xx = cc / power10[i] % 10;
				//int y = c / power10[1]
				int t = cc - power10[n - 1] * yy + power10[n - 1] * xx - power10[i] * xx + power10[i] * yy;
				int s = stat(t);
				if (!vis[s])
				{
					vis[s] = true;
					nex->push(t);
				}
			}
		}
		swap(cur, nex);
		d++;
	}
	return -1;
}
int main()
{
	power10[0] = 1;
	for (int i = 1; i < 11; i++)
	{
		power10[i] = power10[i - 1] * 10;
	}
	int from, to;
	scanf("%d", &n);
	//cin >> n;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d%d", &from, &to);
		//cin >> from >> to;
		printf("%d\n", bfs(from, to));
		//cout << bfs(from, to) << endl;
	}
	return 0;
}