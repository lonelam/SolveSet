#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long ll;
const int maxn = 200005;
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
		    s.push({ u, v });//undir graph no need
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

int main()
{
	int from, to;
int n;
int m;
	int kase = 1;
	while (cin >> n && n)
	{
		m = 0;
		int maxm = 2 * n;
		for (int i = 0; i < maxm; i++)
		{
			G[i].clear();
		}
		for (int i = 0; i < n; i++)
		{
			cin >> from >> to;
			m = max(max(to, from), m);
			from--;
			to--;
			G[from].push_back(to);
			G[to].push_back(from);
		}
		find_bcc(m);

		ll ans = 1;
		int esnum = 0;
		if (bcc_cnt == 1)
		{
			esnum = 2;
			ans = bcc[1].size() * (bcc[1].size() - 1) / 2;
		}
		else
		{
			for (int i = 1; i <= bcc_cnt; i++)
			{
				int cut_cnt = 0;
				for (int j = 0; j < bcc[i].size(); j++)
				{
					if (iscut[bcc[i][j]])
					{
						cut_cnt++;
					}
				}
				if (cut_cnt == 1)
				{
					ans *= (ll)bcc[i].size() - cut_cnt;
					esnum++;
				}
				
			}
			
		}
		cout <<"Case "<<kase++<<": "<<esnum<<" "<< ans << endl;
	}
}