#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
const int maxn = 1005;
vector<int> G[maxn], bcc[maxn];
int odd[maxn], color[maxn];
int bccno[maxn];
int dfs_clock, bcc_cnt;
int pre[maxn], iscut[maxn];
struct edge
{
	int u, v;
};
stack<edge> s;
int dfs(int u, int fa)
{
	int lowu = pre[u] = ++dfs_clock;
	int child = 0;
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (!pre[v])
		{
			s.push({ u, v });
			child++;
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			//because the low_reach of v is larger which represent (u,v) is a bridge,
			//u is a cut and we need to construct a new bcc which contains the nodes
			//under u(including u)!
			if (lowv >= pre[u])
			{
				iscut[u] = true;
				bcc_cnt++;
				bcc[bcc_cnt].clear();
				for (;;)
				{
					edge x = s.top(); s.pop();
					if (bccno[x.u] != bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x.u);
						bccno[x.u] = bcc_cnt;
					}
					if (bccno[x.v] != bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x.v);
						bccno[x.v] = bcc_cnt;
					}
					if (x.u == u && x.v == v)
					{
						break;
					}
				}
			}
		}
		//v is visited before u and v is not u's father
		//this turns out that through u you can visit its ancester 
		// and u is not a cut
		else if (pre[v] < pre[u] && v != fa)
		{
			//s.push({ u, v });undir graph no need
			lowu = min(lowu, pre[v]);
			//father of v might be the cut if no decendences going to ancester of v!
		}

	}
	if (fa < 0 && child == 1)
	{
		iscut[u] = false;
	}
	return lowu;

}



void find_bcc(int n)
{
	memset(pre, 0, sizeof(pre));
	memset(iscut, 0, sizeof(iscut));
	memset(bccno, 0, sizeof(bccno));
	dfs_clock = 0;
	bcc_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (!pre[i])
		{
			dfs(i, -1);
		}
	}
}


bool bipartite(int u, int b)
{
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (bccno[v] != b)
		{
			continue;
		}
		if (color[v] == color[u])
		{
			return false;
		}
		if (!color[v])
		{
			color[v] = 3 - color[u];
			if (!bipartite(v, b))
			{
				return false;
			}
		}
	}
	return true;
}

int A[maxn][maxn];

int main()
{
	int kase = 0, n, m;
	while (cin >> n >> m && n)
	{
		for (int i = 0; i < n; i++)
		{
			G[i].clear();
		}
		memset(A, 0, sizeof(A));
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			A[u][v] = A[v][u] = 1;
		}
		for (int u = 0; u < n; u++)
		{
			for (int v = u + 1; v < n; v++)
			{
				if (!A[u][v])
				{
					G[u].push_back(v);
					G[v].push_back(u);
				}
			}
		}
		find_bcc(n);
		memset(odd, 0, sizeof(odd));
		for (int i = 1; i <= bcc_cnt; i++)
		{
			memset(color, 0, sizeof(color));
			for (int j = 0; j < bcc[i].size(); j++)
			{
				bccno[bcc[i][j]] = i;//might be unnecessary
			}
			int u = bcc[i][0];
			color[u] = 1;
			if (!bipartite(u, i))
			{
				for (int j = 0; j < bcc[i].size(); j++)
				{
					odd[bcc[i][j]] = 1;
				}
			}
		}
		int ans = n;
		for (int i = 0; i < n; i++)
		{
			if (odd[i]) ans--;
		}
		cout << ans << endl;
	}
}