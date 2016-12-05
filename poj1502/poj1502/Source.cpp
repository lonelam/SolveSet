#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

const int maxn = 10005;
bool inq[maxn];
int dis[maxn];
vector<int> G[maxn];
const int inf = 0x3f3f3f3f;
struct edge
{
	int from, to, cost;
};
edge es[maxn * maxn];
void spfa(int s)
{
	queue<int> q;
	memset(inq, 0, sizeof(inq));
	q.push(s);
	dis[s] = 0;
	inq[s] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		inq[cur] = false;
		for (int i = 0; i < G[cur].size(); i++)
		{
			edge & e = es[G[cur][i]];
			if (dis[e.to] > dis[e.from] + e.cost)
			{
				dis[e.to] = dis[e.from] + e.cost;
				if (!inq[e.to])
				{
					q.push(e.to);
				}
			}
		}
		
	}
}
void init()
{

}
int main()
{
	string entry;
	int n;
	int ecnt;
	while (cin >> n)
	{
		ecnt = 0;
		memset(G, 0, sizeof(G));
		memset(dis, inf, sizeof(dis));
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				cin >> entry;
				if (entry[0] != 'x')
				{
					int cost = stoi(entry);
					es[ecnt] = { i, j, cost };
					G[i].push_back(ecnt++);

					es[ecnt] = { j, i, cost };
					G[j].push_back(ecnt++);
				}
			}
		}
		spfa(0);
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans = max(ans, dis[i]);
		}
		cout << ans << endl;
	}
}