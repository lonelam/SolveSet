#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
/*
-----------Answered by Lonelam---------
*
*          ┌─┐       ┌─┐
*       ┌──┘ ┴───────┘ ┴──┐
*       │                 │
*       │       ───       │
*       │  ─┬┘       └┬─  │
*       │                 │
*       │       ─┴─       │
*       │                 │
*       └───┐         ┌───┘
*           │         │
*           │         │
*           │         │
*           │         └──────────────┐
*           │                        │
*           │                        ├─┐
*           │                        ┌─┘
*           │                        │
*           └─┐  ┐  ┌───────┬──┐  ┌──┘
*             │ ─┤ ─┤       │ ─┤ ─┤
*             └──┴──┘       └──┴──┘
*                 神兽保佑
*                 代码无BUG!
*/
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
struct path
{
	ll from, to, fee;
};
map<p, ll> cost;
ll get_fee(ll x, ll y)
{
	return cost[{x, y}] + cost[{y, x}];
}
void bfs1(ll from,ll to,ll fee)
{
	vector<ll> cur, nex;
	unordered_set<ll> used;
	unordered_map<ll, ll> par;
	cur.push_back(from);
	used.insert(from);
	bool nfound = true;
	while (!cur.empty()&&nfound)
	{
		for (ll x : cur)
		{
			if (x == to)
			{
				nfound = false;
				break;
			}
			for (ll y : vector<ll>{ x / 2,2 * x,2 * x + 1 })
			{
				if (used.count(y) == 0)
				{
					par[y] = x;
					used.insert(y);
					nex.push_back(y);
				}
			}
		}
		cur = nex;
		nex.clear();
	}
	ll curs = to;
	while (curs != from)
	{
		cost[{curs, par[curs]}] += fee;
		curs = par[curs];
	}
}
ll bfs2(ll from, ll to)
{
	vector<ll>cur, nex;
	unordered_set<ll> used;
	unordered_map<ll, ll> par;
	cur.push_back(from);
	used.insert(from);
	bool nfound = true;
	while (!cur.empty() && nfound)
	{
		for (ll x : cur)
		{
			if (x == to)
			{
				nfound = false;
				break;
			}
			for (ll y : vector<ll>{ x / 2,2 * x,2 * x + 1 })
			{
				if (used.count(y) == 0)
				{
					par[y] = x;
					used.insert(y);
					nex.push_back(y);
				}
			}
		}
		cur = nex;
		nex.clear();
	}
	ll curs = to,ans = 0;
	while (curs != from)
	{
		ans += get_fee(curs, par[curs]);
		curs = par[curs];
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int q;
	while (cin >> q)
	{
		int cmd;
		ll u, v, w;
		for (int i = 0; i < q; i++)
		{
			cin >> cmd;
			if (cmd == 1)
			{
				cin >> u>>v>>w;
				bfs1(u, v, w);
			}
			else if (cmd == 2)
			{
				cin >> u >> v;
				cout << bfs2(u, v) << endl;
			}
		}
	}
}