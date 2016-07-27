const int MAX_N = 1000;
const int MAX_E = 1000;
const int INF = 0x3f3f3f3f;
int from[MAX_E];
int to[MAX_E];
int w[MAX_E];
int dis[MAX_N];
int tot;
bool exist;
void init()
{
	tot = 0;
}
void add_edge(int u, int v, int d)
{
	from[tot] = u;
	to[tot] = v;
	w[tot++] = d;
}

void bellman_ford(int s, int n)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	bool relaxed = false;
	for (int k = 0; k < n - 1; k++)
	{
		for (int i = 0; i < tot; i++)
		{
			int x = from[i];
			int y = to[i];
			if (dis[y] > dis[x] + w[i])
			{
				dis[y] = dis[x] + w[i];
				relaxed = true;
			}
		}
		if (!relaxed)
		{
			break;
		}
	}
	exist = 0;
	for (int i = 0; i < tot && !exist; i++)
	{
		if (dis[to[i]] > dis[from[i]] + w[i])
		{
			exist = 1;
		}
	}
}

vector<pair<int, int>> G[MAX_N];
bool vis[MAX_N];
int dis[MAX_N];
int inqueue[MAX_N];
void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		G[i].clear();
	}
	exist = 0;
}
void add_edge(int u, int v, int w)
{

	G[u].push_back(make_pair(v, w));
}

void SPFA(int s, int n)
{
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		vis[x] = false;
		for (int i = 0; i < G[x].size(); i++)
		{
			int y = G[x][i].first;
			int w = G[x][i].second;
			if (dis[y] > dis[x] + w)
			{
				dis[y] = dis[x] + w;
				if (!vis[y])
				{
					q.push(y);
					vis[y] = true;
					if (++inqueue[y] >= n)
					{
						exist = 1;
					}
				}
			}
		}
		if (exist)
		{
			break;
		}
	}
}