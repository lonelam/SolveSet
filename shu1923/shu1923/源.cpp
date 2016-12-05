#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf = 0x3f3f3f3f;
int least_t;
const int maxn = 21;
const int maxk = 10;
char mp[maxn][maxn];//地图
bool used[maxn][maxn];
int m, n;
int tx, ty;
int opti[maxn][maxn][maxk];//存储当前最优解
void dfs(int curx, int cury, int magic,bool wall, int t)
{
	if (used[curx][cury] || (t+abs(tx - curx)+abs(cury - ty)) > least_t)//剪枝
	{
		return;
	}
	if (opti[curx][cury][magic] <= t)//剪枝
	{
		return;
	}
	opti[curx][cury][magic] = t;
	if (mp[curx][cury] == 'T')//到达终点
	{
		least_t = min(least_t, t);
	}
	if (mp[curx][cury] == 'x')//碰到墙
	{
		if (magic == 0||wall)//用完了魔法，或者不能二次穿墙
		{
			return;
		}
		magic--;
		wall = true;
	}
	else
	{
		wall = false;
	}
	used[curx][cury] = true;
	//扩展状态
	if (curx > 0)
	{
		dfs(curx - 1, cury, magic,wall, t + 1);
	}
	if (curx < m - 1)
	{
		dfs(curx + 1, cury, magic,wall, t + 1);
	}
	if (cury > 0)
	{
		dfs(curx, cury - 1, magic,wall, t + 1);
	}
	if (cury < n - 1)
	{
		dfs(curx, cury + 1, magic,wall, t + 1);
	}
	used[curx][cury] = false;
}

int main()
{
	int tt;
	memset(used, 0, sizeof(used));
	while (cin >> tt)
	{
		while (tt--)
		{
			int mgc;
			memset(opti, inf, sizeof(opti));
			least_t = inf;
			cin >> m >> n >> mgc;
			int sx, sy;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cin >> mp[i][j];
					if (mp[i][j] == 'S')
					{
						sx = i;
						sy = j;
					}
					if (mp[i][j] == 'T')
					{
						tx = i;
						ty = j;
					}
				}
			}

			dfs(sx, sy, mgc,false, 0);

			if (least_t == inf)//到不了的情况
			{
				cout << -1 << endl;
			}
			else
			cout << least_t << endl;
		}
	}
}