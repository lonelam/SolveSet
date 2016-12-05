#include<iostream>
#include<string>
#include<utility>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxk = 17;
const int maxs = 1 << maxk;
const int maxp = 16;
typedef pair<int, int> pii;

int dp[maxs][maxp][maxp];
bool grid[5][5];
const int dx[] = { 1, -1,0,0 };
const int dy[] = { 0,0,1,-1 };
bool inq[maxp][maxp];
int main()
{
	int t, n, m;
	string s;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n >> m;
			int mss = 1 <<  n * m;
			int sx, sy;
			for (int i = 0; i < n; i++)
			{
				cin >> s;
				for (int j = 0; j < m; j++)
				{
					grid[i][j] = s[j] == 'X' ? false : true;
					if (s[j] == 'S')
					{
						sx = i;
						sy = j;
					}
				}
			}
			queue<pii> cur;
			int sp = sx * m + sy;
			cur.push({ sp,sp });
			memset(dp, inf, sizeof(dp));
			
			dp[1 << (sp)][sp][sp] = 0;
			int goal = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (grid[i][j])
					{
						goal |= 1 << (i * m + j);
					}
				}
			}
			memset(inq, 0, sizeof(inq));
			int trim = inf;
			while (!cur.empty())
			{
				pii cp = cur.front();
				cur.pop();
				inq[cp.first][cp.second] = false;
				int cx1 = cp.first / m;
				int cy1 = cp.first % m;
				int cx2 = cp.second / m;
				int cy2 = cp.second % m;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						int tx1 = cx1 + dx[i];
						int ty1 = cy1 + dy[i];
						int tx2 = cx2 + dx[j];
						int ty2 = cy2 + dy[j];
						if (tx1 >= 0 && tx1 < n && ty1 >= 0 && ty1 < m && grid[tx1][ty1] && tx2 >= 0 && tx2 < n && ty2 >= 0 && ty2 < m && grid[tx2][ty2])
						{
							int tp1 = tx1 * m + ty1;
							int tp2 = tx2 * m + ty2;
							for (int stat = 0; stat < mss; stat++)
							{
								if (stat & (1 << cp.first) && (stat & ( 1 << cp.second)))
								{
									int poststat = stat | (1 << tp1) | (1 << tp2);
									if (dp[poststat][tp1][tp2] > dp[stat][cp.first][cp.second] + 1)
									{
										dp[poststat][tp1][tp2] = dp[stat][cp.first][cp.second] + 1;
										if (!inq[tp1][tp2] && dp[poststat][tp1][tp2] + 1<= trim)
										{
											inq[tp1][tp2] = true;
											cur.push({ tp1, tp2 });
										}
										if((stat | (1 << tp1) | (1 << tp2)) == goal) 
											trim = min(trim, dp[stat][cp.first][cp.second] + 1);
									}
								}
							}
						}
					}
				}
			}
			int ans = inf;
			int mmn = n * m;
			for (int i = 0; i < mmn; i++)
			{
				for (int j = 0; j < mmn; j++)
				{
					ans = min(ans, dp[goal][i][j]);
				}
			}
			cout << ans << endl;
		}
	}
}