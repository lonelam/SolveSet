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
int q, x, y;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const int maxm = 40 + 5;
typedef long long ll;
typedef long double ld;
ll d[maxn];
ll presum[maxn];
int u[maxn], v[maxn];
ll w[maxn];
ll G[maxm][maxm];
int n, m;
ll dis[maxm][maxm];
int id[maxn];
vector<int> disc;
ll rdis(int x, int y)
{
	if (x < y) swap(x, y);
	return min(presum[x - 1] - presum[y - 1], presum[n] - presum[x - 1] + presum[y - 1]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> n >> m)
	{
		memset(id, -1, sizeof(id));
		for (int i = 1; i <= n; i++)
		{
			cin >> d[i];
			presum[i] = presum[i - 1] + d[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> u[i] >> v[i] >> w[i];
			disc.push_back(u[i]);
			disc.push_back(v[i]);
		}
		sort(disc.begin(), disc.end());
		disc.erase(unique(disc.begin(), disc.end()), disc.end());
		for (int i = 0; i < disc.size(); i++)
		{
			G[i][i] = 0;
			id[disc[i]] = i;
			for (int j = i+1; j < disc.size(); j++)
			{
				G[i][j] = G[j][i] = min(presum[disc[j] - 1] - presum[disc[i] - 1], presum[n] - presum[disc[j] - 1] + presum[disc[i] - 1]);
			}
		}
		for (int i = 0; i < m; i++)
		{
			int uid = lower_bound(disc.begin(), disc.end(), u[i]) - disc.begin();
			int vid = lower_bound(disc.begin(), disc.end(), v[i]) - disc.begin();
			G[uid][vid] = G[vid][uid] = min(G[uid][vid], w[i]);
		}
		for (int k = 0; k < disc.size(); k++)
		{
			for (int i = 0; i < disc.size(); i++)
			{
				for (int j = 0; j < disc.size(); j++)
				{
					G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
				}
			}
		}
		cin >> q;
		while (q--)
		{
			cin >> x >> y;
			ll ans = rdis(x, y);
			/*int closex = lower_bound(disc.begin(), disc.end(), x) - disc.begin();
			if (closex == disc.size()) closex--;

			int closey = lower_bound(disc.begin(), disc.end(), y) - disc.begin();
			if (closey == disc.size()) closey--;*/

			for (int i = 0; i < disc.size(); i++)
			{
				for (int j = 0; j < disc.size(); j++)
				{
					ans = min(ans, rdis(x, disc[i]) + rdis(y, disc[j]) + G[i][j]);
				}
			}
			cout << ans << endl;
		}
	}
}