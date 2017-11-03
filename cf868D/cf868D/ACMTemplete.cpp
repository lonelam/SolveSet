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
int n, m;
string ss[maxn * 2];
int mk[maxn * 2];
bool vis[10000000];
bool check(string & s, int k)
{
	memset(vis, 0, sizeof(bool) * (1 << k));
	int cur = 0;
	for (int i = 0; i < k; i++)
	{
		cur <<= 1;
		cur |= (s[i] - '0');
	}
	vis[cur] = 1;
	for (int i = k; i < s.size(); i++)
	{
		cur -= (int)(s[i - k] - '0') << (k-1);
		cur <<= 1;
		cur |= (s[i] - '0');
		vis[cur] = 1;
	}
	for (int i = 0; i < (1 << k); i++)
	{
		if (!vis[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> ss[i];
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			static int u, v;
			cin >> u >> v;
			u--; v--;
			ss[n] = ss[u] + ss[v];
			mk[n] = max(mk[u], mk[v]);
			while (check(ss[n], mk[n] + 1)) mk[n]++;
			cout << mk[n] << endl;
			n++;

		}
	}
}