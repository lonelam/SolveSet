#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 205;
char grid[maxn][maxn];
bool vis[maxn];
vector<pii> vuls;
int ans;
bool specialized;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };
int m, n;
int light;
void dfs(int cur)
{
	if (cur == vuls.size())
	{
		for (int i = 0; i < vuls.size(); i++)
		{
			if (!vis[i])
			{
				return;
			}
		}
		ans = min(ans, light);
		return;
	}
	int cx = vuls[cur].first;
	int cy = vuls[cur].second;
	bool ok = true;
	for (int dir = 0; dir < 2; dir++)
	{
		int tx = cx + dx[dir];
		int ty = cy + dy[dir];
		if (tx >= 0 && ty < m && grid[tx][ty] == '#')
		{
			ok = false;
		}
	}
	bool f1 = true, f[2] = { true, true };
	if (ok)
	{
		if (vis[cur])
		{
			f1 = false;
		}
		else
		{
			vis[cur] = true;
		}
		for (int dir = 0; dir < 2; dir++)
		{
			int tx = cx + dx[dir];
			int ty = cy + dy[dir];
			if (tx < 0 || ty >= m || vis[grid[tx][ty]])
			{
				f[dir] = false;
			}
			else
			{
				vis[grid[tx][ty]] = true;
			}
		}
		light++;
		dfs(cur + 1);
		if (f1)
		{
			vis[cur] = false;
		}
		else
		{
			f1 = true;
		}
		for (int dir = 0; dir < 2; dir++)
		{
			if (f[dir])
			{
				vis[grid[cx + dx[dir]][cy + dy[dir]]] = false;
			}
			else
			{
				f[dir] = true;
			}
		}
		light--;
	}
	dfs(cur + 1);
		if (!specialized)
		{
			for (int d = 1; d < 4; d++)
			{
				ok = true;
				for (int dd = 0; dd < 2; dd++)
				{
					int dir = (d + dd) % 4;
					int tx = cx + dx[dir];
					int ty = cy + dy[dir];
					if (tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] == '#' )
					{
						ok = false;
					}
					
				}
				if (ok)
				{
					specialized = true;
					light++;
					if (vis[cur])
					{
						f1 = false;
					}
					else
					{
						vis[cur] = true;
					}
					for (int dd = 0; dd < 2; dd++)
					{
						int dir = (d + dd) % 4;
						int tx = cx + dx[dir];
						int ty = cy + dy[dir];
						if (tx < 0 || tx >= n || ty < 0 || ty >= m || vis[grid[tx][ty]])
						{
							f[dd] = false;
						}
						else
						{
							vis[grid[tx][ty]] = true;
						}
					}
					dfs(cur + 1);
					light--;
					specialized = false;
					if (f1)
					{
						vis[cur] = false;
					}
					else
					{
						f1 = true;
					}
					for (int dd = 0; dd < 2; dd++)
					{
						if (f[dd])
						{
							int dir = (d + dd) % 4;
							int tx = cx + dx[dir];
							int ty = cy + dy[dir];
							vis[grid[tx][ty]] = false;
						}
						else
						{
							f[dd] = true;
						}
					}
				}
			}
		}
}
int main()
{
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
		{
			return 0;
		}
		vuls.clear();
		specialized = false;
		ans = inf;
		light = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> grid[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == '.')
				{
					grid[i][j] = vuls.size();
					vuls.emplace_back(make_pair(i, j));
				}
			}
		}
		dfs(0);
		cout << (ans == inf ? -1 : ans) << endl;
	}
}