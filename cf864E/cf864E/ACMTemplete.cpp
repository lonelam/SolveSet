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
const int maxd = 2000 + 100;
typedef long long ll;
typedef long double ld;
//ll t[maxn], d[maxn], p[maxn];
struct item
{
	int t, d, p, id;
	bool operator<(const item & rhs) const
	{
		if (d != rhs.d) return d < rhs.d;
		return t < rhs.t;
	}
} is[maxn], is2[maxn];
ll dp[maxd];
vector<int> pre[maxd];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> is[i].t >> is[i].d >> is[i].p;
			is[i].id = i + 1;
			is2[i] = is[i];

		}
		sort(is, is + n);
		for (int i = 0; i < n; i++)
		{
			for (int dd = is[i].d - 1; dd >= is[i].t; dd--)
			{
				if (dp[dd - is[i].t] + is[i].p > dp[dd] )
				{
					dp[dd] = dp[dd - is[i].t] + is[i].p;
					pre[dd] = pre[dd - is[i].t];
					pre[dd].push_back(is[i].id);
				}
			}
		}
		int ans = 0;
		for (int dd = 0; dd <= 2000; dd++)
		{
			if (dp[dd] > dp[ans])
			{
				ans = dd;
			}
		}
		int p = ans;
		cout << dp[ans] << endl;
		vector<int> & g = pre[ans];
		
		cout << g.size() << endl;
		//reverse(g.begin(), g.end());
		for (int o : g)
		{
			cout << o << " ";
		}
	}
}