#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <cassert>
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
int n;
pair<vector<int>, vector<int> > gao(pair<vector<int>, vector<int> > pre = { {1}, {} })
{
	if (pre.second.size() == n)
	{
		return pre;
	}
	vector<int> g = pre.first;
	g.insert(g.begin(), 0);
	int test = 1;
	for (int i = 0; i < pre.second.size(); i++)
	{
		if (pre.second[i] + g[i] >= 2 || pre.second[i] + g[i] <= -2)
		{
			for (int j = 0; j < g.size(); j++)
			{
				g[j] = -g[j];
			}
			test = -1;	
			break;
		}
	}
	for (int i = 0; i < pre.second.size(); i++)
	{
		g[i] += pre.second[i];
		assert(g[i] >= -1 && g[i] <= 1);
	}
	pair<vector<int>, vector<int> > ret = { g, pre.first };
	return gao(ret);
}
int main()
{
	while (~scanf("%d", &n))
	{
		pair<vector<int>, vector<int> > ans = gao();
		printf("%d\n", ans.first.size()-1);
		if (*ans.first.rbegin() == -1)
		{
			for (int i = 0; i < ans.first.size(); i++)
			{
				ans.first[i] = -ans.first[i];
			}
			
		}
		if (*ans.second.rbegin() == -1)
		{
			
			for (int i = 0; i < ans.second.size(); i++)
			{
				ans.second[i] = -ans.second[i];
			}
		}
		for (int i = 0; i < ans.first.size(); i++)
		{
			printf("%d%c", ans.first[i], i == (ans.first.size() - 1) ? '\n' : ' ');
		}
		printf("%d\n", ans.second.size()-1);
		for (int i = 0; i < ans.second.size(); i++)
		{
			printf("%d%c", ans.second[i], i == (ans.second.size() - 1) ? '\n' : ' ');
		}
	}
}