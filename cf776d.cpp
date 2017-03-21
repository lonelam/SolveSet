#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;

int r[maxn];
int n,m;
int vis[maxn];
vector<int> sw[maxn];

struct edge
{
    int to, nex;
} es[maxn];

int head[maxn], tot;
void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}

void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].nex = head[u];
    head[u] = tot++;
}
bool vis[maxn];

int S[maxn], top;
bool dfs(int u)
{
    if (vis[u ^ 1]) return false;
    if (vis[u]) return true;
    vis[u] = true;
    S[top++] = u;
    for (int i = head[u]; i!= -1; i = edge[i].nex)
        if ()
}
