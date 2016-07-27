#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 6;
bool cooked[maxn][maxn];
int bar[maxn][maxn];
const int inf = 0x3f3f3f3f;
int n, min_t;
//DFS， 按已经开炮的次数扩展
void dfs(int t)
{
	if (t >= min_t)
	{
		return;
	}
	bool done = true;
	vector<bool> cooked_row(n, false);//如果那一排或者那一列
	vector<bool> cooked_col(n, false);
	//遍历所有点
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//每一个没熟的点都看看它所在的列和排可不可以烧
			if (bar[i][j] && !cooked[i][j])
			{
				done = false;
				bool row = true, col = true;
				for (int k = 0; k < n; k++)
				{
					if (cooked[i][k])
					{
						row = false;
						break;
					}
					if (cooked[k][j])
					{
						col = false;
						break;
					}
				}
				//如果那一排可以烧，那就烧熟并扩展状态
				if (row&&!cooked_row[i])
				{
					cooked_row[i] = true;
					for (int k = 0; k < n; k++)
					{
						if (bar[i][k])
						{
							cooked[i][k] = true;
						}
					}
					dfs(t + 1);
					for (int k = 0; k < n; k++)
					{
						cooked[i][k] = false;
					}
				}
				//如果那一列可以烧，那就烧熟然后扩展状态
				if (col && !cooked_col[j])
				{
					cooked_col[j] = true;
					for (int k = 0; k < n; k++)
					{
						if (bar[k][j])
						{
							cooked[k][j] = true;
						}
					}
					dfs(t + 1);
					for (int k = 0; k < n; k++)
					{
						cooked[k][j] = false;
					}
				}
			}
		}
	}
	if (done)
	{
		min_t = min(min_t, t);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int tt;
	memset(cooked, 0, sizeof(cooked));
	while (cin >> tt)
	{
		while (tt--)
		{
			min_t = inf;
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cin >> bar[i][j];
				}
			}
			dfs(0);//从0次开始
			cout << min_t << endl;
		}
	}
}