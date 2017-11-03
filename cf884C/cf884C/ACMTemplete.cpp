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
int p[maxn];
bool vis[maxn];
int n;
int main()
{
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i];
		}
		vector<int> G;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				int cnt = 0;
			    int q = i;
				while (!vis[q])
				{
					vis[q] = true;
					q = p[q];
					cnt++;
				}
				G.push_back(cnt);
			}
		}
		sort(G.begin(), G.end());
		if (G.size() > 1)
		{
			int u1 = G.back();
			G.pop_back();
			int u2 = G.back();
			G.pop_back();
			G.push_back(u1 + u2);
		}
		ll ans = 0;
		for (int x : G)
		{
			ans += x * (ll)x;
		}
		cout << ans << endl;

	}
}