#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

struct edge
{
	int to, id, cost;
};
const int maxn = 100000 + 20;
//RMQ interval tree

int RMQ[maxn * 6];
int RMQ_N;

void init(int n)
{
	RMQ_N = 1;
	while( n > RMQ_N)
	{
		RMQ_N <<= 1;
	}
	//RMQ_N <<= 1;
}

void RMQ_init(int n, int * tar)
{
	init(n);
	memset(RMQ, 0, sizeof(RMQ));
	for (int i = 0; i < n; i++)
	{
		RMQ[RMQ_N + i] = i;
	}
	for (int i = n; i < RMQ_N; i++)
	{
        RMQ[RMQ_N + i] == -1;
	}
	for (int i = RMQ_N - 1; i > 0; i--)
	{
		if (RMQ[i * 2 + 1] == -1 || tar[RMQ[i * 2]] < tar[RMQ[i * 2 + 1]])
		{
			RMQ[i] = RMQ[i * 2];
		}
		else
		{
			RMQ[i] = RMQ[i * 2 + 1];
		}
	}
}
int ql, qr;
int in_query(int * tar, int o, int l, int r)
{
	if (ql <= l && r <= qr)
	{
		return RMQ[o];
	}
	//printf("rmq dubug:  %d  %d   %d\n", l, r, o);
	if (qr < l ||ql >r)
	{
		return -1;
	}
	const int mid = l + (r - l) / 2;
	int dl = in_query(tar, o * 2, l, mid);
	int dr = in_query(tar, o * 2 + 1, mid + 1, r);
	if (dl == -1) return dr;
	if ( dr == -1 || tar[dl] < tar[dr])
	{
		return dl;
	}
	else
	{
		return dr;
	}
}


int RM_query(int * tar, int left, int right)
{
	ql = left;
	qr = right;
	return in_query(tar, 1, 0, RMQ_N - 1);
}


// SUM interval tree

int sum[maxn * 6];
int sum_N;
void sum_init(int n)
{
	sum_N = 1;
	while(n > sum_N)
	{
		sum_N <<= 1;
	}
	memset(sum, 0, sizeof(sum));
}

void sum_add(int pos, int adder, int o = 1, int l = 0, int r = sum_N - 1)
{
	if (l == r)
	{
		if (l == pos)
		{
			sum[o]+= adder;
		}
		return;
	}
	if (l <= pos && pos <= r)
	{
		const int mid = l + (r - l) / 2;
		sum[o] += adder;
		// printf("debugsum::%d  %d  %d:\n", o, l, r);
		sum_add(pos, adder, o * 2, l, mid);
		sum_add(pos, adder, o * 2 + 1, mid + 1, r);
	}
}

int s_in_query(int o, int l, int r)
{
	if (ql <= l && r <= qr)
	{
		return sum[o];
	}
	if (r < ql || qr < l)
	{
		return 0;
	}
	const int mid = l + (r - l) / 2;
	return s_in_query(o * 2, l, mid) + s_in_query(o * 2 + 1, mid + 1, r);
}

int sum_query(int l, int r)
{
	ql = l;
	qr = r;
	return s_in_query(1, 0, sum_N - 1);
}


int depth[maxn * 3];
int vs[maxn * 3];
int sp[maxn];
int fp[maxn];
int k;
vector<edge> es;
vector<int> G[maxn];
void addedge(int from, int to, int cost, int id)
{
	G[from].push_back(es.size());
	es.push_back({to, id, cost});
	G[to].push_back(es.size());
	es.push_back({from, id, cost});
}
int vfp[maxn];
void dfs(int u, int p, int d)
{
	//printf("debug:%d\n", k);
	vs[k] = u;
	vfp[u] = k;
	depth[k++] = d;
	for (int i = 0; i < G[u].size(); i++)
	{
		if (es[G[u][i]].to != p)
		{
			fp[es[G[u][i]].id] = k;
			sum_add(k, es[G[u][i]].cost);
			dfs(es[G[u][i]].to, u, d +1);
			sum_add(k, -es[G[u][i]].cost);
			sp[es[G[u][i]].id] = k++;
			depth[k] = d;
			vs[k++] = u;
		}
	}
	vs[k] = u;
	depth[k] = d;
}
int main()
{
	int tree_n;
	int q_n;
	while(scanf("%d", &tree_n)!=EOF)
	{
		for (int i = 0; i < tree_n; i++)
		{
			G[i].clear();
		}
		es.clear();
		int ui,vi, wi;
		for (int i = 1; i < tree_n; i++)
		{
			scanf("%d%d%d", &ui, &vi, &wi);
			addedge(ui, vi, wi, i);
		}
		k = 1;
		sum_init(tree_n * 3);
		dfs(0, -1,0);
		RMQ_init(k, depth);
		//for (int i = 0; i < k; i++) printf("%d ", sum[i + sum_N]); printf("\n");
		//for (int i = 0; i < k; i++) printf("%d ", RMQ[i + RMQ_N]); printf("\n");
		//for (int i = 0; i < k; i++) printf("%d ", vs[i]); printf("\n");
		scanf("%d", &q_n);
		for (int i = 0; i < q_n; i++)
		{
			int f, t;
			scanf("%d%d", &f, &t);
			if (vfp[f] > vfp[t]) swap(f, t);
			int lca = vs[RM_query(depth,vfp[f],vfp[t])];
			//printf("%d  %d lca: %d , query_tar: %d \n", vfp[f], vfp[t], lca, RM_query(depth,vfp[f],vfp[t]));
			printf("%d\n",sum_query(vfp[lca] + 1, vfp[t]) + sum_query(vfp[lca] + 1, vfp[f]));
		}
	}
}


/*
7
0 1 4
0 2 3
5 2 5
1 4 8
3 1 7
4 6 2

*/
