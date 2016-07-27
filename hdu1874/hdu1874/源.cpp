#include<queue>
#include<functional>
#include<iostream>
#include<cstring>
#include<vector>
#include<utility>
using namespace std;
const int maxn = 200;
const int maxm = 1000;
int d[maxn];
vector<vector<pair<int,int>>> G(maxn, vector<pair<int,int>>());
int s, t;
struct path_cmp
{
	bool operator()(pair<int, int> & a, pair<int, int> &b)
	{
		return a.second > b.second;
	}
};
int dijkstra()
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, path_cmp > q;
	q.push({ s,0 });
	memset(d, 0x3f, sizeof(d));
	while (!q.empty())
	{
		pair<int, int> cur = q.top();
		q.pop();
		int here = cur.first, t_c = cur.second;
		if (here == t)
		{
			return t_c;
		}
		if (d[here] > t_c)
		{
			d[here] = t_c;
			for (pair<int, int> f : G[here])
			{
				q.push({ f.first,f.second + t_c });
			}
		}
	}
	return -1;
}

int main()
{
	int	n, m, a, b, x;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			G[i].clear();
		}
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> x;
			G[a].push_back({ b,x });
			G[b].push_back({ a,x });
		}
		cin >> s >> t;
		cout << dijkstra() << endl;
	}
}
