#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int dx[4] = { -1, 0, 0, 1 };
const int dy[4] = { 0, 1, -1, 0 };
int X, Y;
const int MAX_X = 14;
const int MAX_Y = 14;
vector<int> dX, dY, pX, pY;
int dist[MAX_X][MAX_Y][MAX_X][MAX_Y];
char field[MAX_X][MAX_Y];
const int MAX_V = MAX_X * MAX_Y * MAX_X * MAX_Y;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];
void add_edge(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		G[i].clear();
	}
}
bool dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++)
	{
		int u = G[v][i];
		int w = match[u];
		if (w < 0 || !used[w] && dfs(w))
		{
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}
void bfs(int x, int y, int d[MAX_X][MAX_Y])
{
	queue<int> qx, qy;
	d[x][y] = 0;
	qx.push(x);
	qy.push(y);
	while (!qx.empty())
	{
		x = qx.front();
		y = qy.front();
		qx.pop();
		qy.pop();
		for (int k = 0; k < 4; k++)
		{
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (tx >= 0 && tx < X && ty >= 0 && ty < Y && field[tx][ty] == '.' && d[tx][ty] < 0)
			{
				d[tx][ty] = d[x][y] + 1;
				qx.push(tx);
				qy.push(ty);
			}

		}
	}
}

void solve()
{
	int n = X * Y;
	dX.clear();
	dY.clear();
	pX.clear();
	pY.clear();
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			if (field[i][j] == 'D')
			{
				dX.push_back(i);
				dY.push_back(j);
				bfs(i, j, dist[i][j]);
			}
			else if (field[i][j] == '.')
			{
				pX.push_back(i);
				pY.push_back(j);
			}
		}
	}
	int d = dX.size();
	int p = pX.size();
	init(n * d + p);
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < p; j++)
		{
			if (dist[dX[i]][dY[i]][pX[j]][pY[j]] >= 0)
			{
				//k is cur_time
				for (int k = dist[dX[i]][dY[i]][pX[j]][pY[j]]; k <= n; k++)
				{
					add_edge((k - 1) * d + i, n * d + j);
				}
			}
		}
	}
	if (p == 0)
	{
		cout << 0 << endl;
		return;
	}
	int num = 0;
	memset(match, -1, sizeof(match));
	for (int v = 0; v < n * d; v++)
	{
		memset(used, 0, sizeof(used));
		if (dfs(v))
		{
			if (++num == p)
			{
				cout << v / d + 1 << endl;
				return;
			}
		}
	}
	cout << "impossible\n";
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> X >> Y;
		for (int i = 0; i < X; i++)
		{
			cin >> field[i];
		}
		solve();
	}
	//system("pause");
}
