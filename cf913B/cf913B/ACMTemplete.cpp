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
const int maxn = 1000 + 100;
typedef long long ll;
typedef long double ld;
int n, L;
int p[maxn];
vector<int> G[maxn];
bool dfs(int cur = 0)
{
	if (G[cur].empty()) return true;
	int cnt = 0;
	for (int ch : G[cur])
	{
		if (G[ch].empty())
		{
			cnt++;
		}
		if (!dfs(ch))
		{
			return false;
		}
	}
	if (cnt < 3)
	{
		return
			false;
	}
	return true;
}
int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			G[i].clear();
		}
		int par;
		for (int i= 1; i < n; i++)
		{
			cin >> par;
			G[par - 1].push_back(i);
		}
		if (dfs())
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}
}