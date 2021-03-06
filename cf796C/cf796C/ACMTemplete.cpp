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
typedef long long ll;
typedef long double ld;
const int maxn = 300000 + 100;
int a[maxn];
//int m[maxn];
int cnt[maxn];

vector<int> G[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> ms, m2s;
	int m = -1e9 - 1, m2 = -1e9 - 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		if (a[i] > m)
		{
			swap(ms, m2s);
			ms.clear();
			ms.push_back(i);
			m2 = m;
			m = a[i];
		}
		else if (a[i] == m)
		{
			ms.push_back(i);
		}
		else if (a[i] == m2)
		{
			m2s.push_back(i);
		}
		else if (a[i] > m2)
		{
			m2 = a[i];
			m2s.clear();
			m2s.push_back(i);
		}
	}
	int u, v;
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if (ms.size() == 1)
	{
		int head = ms[0];
		bool ok = true;
		if (m2 == m - 1)
			for (int i : m2s)
			{
				if (find(G[head].begin(), G[head].end(), i)== G[head].end())
				{
					ok = false;
				}
			}
		if (!ok) m += 1;
	}
	else
	{
		//int head = ms[0];
		bool ok = false;
		for (int i = 0; i < ms.size(); i++)
		{
			for (int j : G[ms[i]])
			{
				cnt[j]++;
			}
			cnt[ms[i]]++;
		}
		for (int i = 1; i <= n; i++)
		{
			if (cnt[i] == ms.size())
			{
				ok = true;
				break;
			}
		}
		/*
		5
		2 2 2 2 2
		2 3
		2 1
		2 4
		2 5
		*/

		if (!ok)m += 2;
		else m += 1;
	}
	printf("%d\n", m);
}