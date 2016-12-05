#include<vector>
#include<iostream>
#include<numeric>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX_V = 10000;
const int MAX_LOG_V = logb(MAX_V);
vector<int> G[MAX_V];
int root;
int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];

void dfs(int v, int p, int d)
{
    parent[0][v] = p;
    depth[v] = d;
    for (int i = 0; i < G[v].size(); i++)
    {
        if (G[v][i] != p) dfs(G[v][i], v, d + 1);
    }
}

void init(int V)
{

    dfs(root, -1, 0);
    for (int k = 0; k + 1 < MAX_LOG_V; k++)
    {
        for (int v = 0; v < V; v++)
        {
            if (parent[k][v] < 0) parent[k + 1][v] = -1;
            else parent[k + 1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v)
{
    // walk u ans v to the same depth
    while(depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < MAX_LOG_V; k++)
    {
        if ((depth[v] - depth[u]) >> k & 1)
        {
            v = parent[k][v];
        }
    }
    if (u == v) return u;
    for (int k = MAX_LOG_V - 1; k >= 0; k--)
    {
        if (parent[k][u] != parent[k][v])
        {
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

///LCA RMQ version!!


///RMQ !

//TODO
const int inf = 0x3f3f3f3f;
int minind[MAX_V * 2 + 1];
int N;
int rmq_init(int * tar, int n)
{
    N = 1;
    while(n < N)
    {
        N <<= 1;
    }
    for (int i = 0; i < n; i++)
    {
        minind[N + i] = i;
    }
    for (int i = n; i <= N; i++)
    {
        minind[N + i] = inf;
    }
    for (int i = N - 1; i > 0; i--)
    {
        if (tar[minind[i * 2]] < tar[minind[i * 2 + 1]])
        {
            minind[i] = minind[i * 2];
        }
        else
        {
            minind[i] = minind[i * 2 + 1];
        }
    }
}

int depth[MAX_V * 2 - 1];
int inner_query(int l, int r,int o, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return minind[o];
    }
    if (r < ql || qr < l)
    {
        return N * 2;
    }
    int ans = 0;
    const int mid = l + (r - l)/ 2;
    int dl = inner_query(l, mid,o * 2, ql, qr);
    int dr = inner_query(mid, r,o * 2 + 1, ql, qr);
    if (minind[dl] < minind[dr])
    {
        return dl;
    }
    else
    {
        return dr;
    }
}
int query(int l, int r)
{
    return inner_query(0, N, 1, l, r);
}
///LCA

vector<int> G[MAX_V];
int root;
int vs[MAX_V * 2 - 1];
int id [MAX_V];
void dfs(int v, int p, int d, int & k)
{
    id[v] = k;
    vs[k] = v;
    depth[k++] = d;
    for (int i = 0; i < G[v].size(); i++)
    {
        if (G[v][i] != p)
        {
            dfs(G[v][i], v, d + 1, k);
            vs[k] = v;
            depth[k++] = d;
        }
    }
}
void init(int V)
{
    int k = 0;
    dfs(root, -1, 0, k);
    rmq_init(depth, V * 2 -1);
}

int lca(int u, int v)
{
    return vs[query(min(id[u],id[v]), max(id[u], id[v]))];
}

