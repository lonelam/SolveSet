#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 15;
bool G[maxn][maxn];
bool vis[maxn];
bool eq[maxn][maxn];
int topo[maxn];
int P[maxn];
int a[maxn];
int n;
int tcnt;
int pos[maxn];
void toposort(int x)
{
	if (vis[x])
	{
		return;
	}
	for (int i = 0; i <= n; i++)
	{
		if (G[x][i] && !vis[i])
		{
			toposort(i);
		}
	}
	
	topo[--tcnt] = x;
	pos[x] = tcnt;
	vis[x] = true;
}

int main()
{
	int t;
	string s;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n >> s;
			memset(G, 0, sizeof(G));
			memset(eq, 0, sizeof(eq));
			memset(vis, 0, sizeof(vis));
			memset(pos, -1, sizeof(pos));
			int cur = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = i + 1; j <= n; j++)
				{
					if (s[cur] == '0')
					{
						eq[i][j] = true;
						eq[j][i] = true;
					}
					else if (s[cur] == '+')
					{
						G[j][i] = true;
					}
					else if(s[cur] == '-')
					{
						G[i][j] = true;
					}
					else
					{
						cout << "debug_error" << endl;
					}
					cur++;
				}
			}
			tcnt = n + 1;
			//toposort(0);
			for (int i = 0; i <= n; i++)
			{
				toposort(i);
			}
			for (int i = 0; i <= n; i++)
			{
				if (pos[i] == -1)
				{
					cout << "debug_no_access" << endl;
				}
			}

			int zero_p = pos[0];
			
			P[zero_p] = 0;
			for (int i = zero_p + 1; i <= n; i++)
			{
				if (eq[topo[i]][topo[i - 1]])
				{
					P[topo[i]] = P[topo[i - 1]];
				}
				else P[topo[i]] = P[topo[i - 1]] - 1;
			}

			for (int i = zero_p - 1; i >= 0; i--)
			{
				if (eq[topo[i]][topo[i + 1]])
				{
					P[topo[i]] = P[topo[i + 1]];
				}
				else P[topo[i]] = P[topo[i + 1]] + 1;
			}
			for (int i = 1; i <= n; i++)
			{
				a[i] = P[i] - P[i - 1];
			}
			cout << a[1];
			for (int i = 2; i <= n; i++)
			{
				cout << " " << a[i];
			}
			cout << endl;
		}
	}
}

