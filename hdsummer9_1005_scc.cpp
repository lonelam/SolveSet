#include <bits/stdc++.h>
using namespace std;
#define MEM(a) memset(a, 0, sizeof(a))

const int maxn = 1000 + 5;
vector<int> G[maxn];
int pre[maxn], lowlink[maxn], dfs_clock;
stack<int> S;
int sccno[maxn], scc_cnt;
int ind[maxn];
int topo[maxn];
int n;
set<int> sG[maxn];
set<int> rsG[maxn];

bool toposort()
{
    for (int i = 1; i <= scc_cnt; i++)
    {
        sG[i].clear();
        rsG[i].clear();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int v: G[i])
        {
            if (sccno[i] == sccno[v]) continue;
            sG[sccno[i]].insert(sccno[v]);
            rsG[sccno[v]].insert(sccno[i]);
        }
    }
    queue<int> Q;
    for (int i = 1; i <= scc_cnt; i++)
    {
       // ind[i] = rsG[i].size();
        if (rsG[i].size() == 0)
        {
            Q.push(i);
        }
    }
    int p = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        topo[p++] = u;
        for (int v: sG[u])
        {
            rsG[v].erase(u);
            if (rsG[v].empty()) Q.push(v);
        }
    }
    //cout << p << endl;
    if (p < scc_cnt) return false;
    for (int i =  1; i < p; i++)
    {
        if (sG[topo[i-1]].find(topo[i]) == sG[topo[i-1]].end())
        {
            return false;
        }
    }
    return true;
}
int ans[maxn];
void dfs(int u) { //从u点开始找一个强连通分量
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (!pre[v]) {
            dfs(v);
            if (lowlink[u] > lowlink[v]) lowlink[u] = lowlink[v];
        } else if (!sccno[v]) {
            if (lowlink[u] > pre[v]) lowlink[u] = pre[v];
        }
    }
    if (lowlink[u] == pre[u]) {
        scc_cnt++;
        for(;;) {
            int x = S.top(); S.pop();
            sccno[x] = scc_cnt;
            if (x == u) break;
        }
    }
}

void find_scc(int n) { //n是点的总数，点的范围1-n
    dfs_clock = scc_cnt = 0;
    MEM(sccno); MEM(pre); MEM(ans);
    for (int i = 1; i <= n; i++) {
        if (!pre[i]) dfs(i);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    int m;
    while(T--)
    {
        scanf("%d%d", &n, &m);
        int u, v;
        for (int i = 1; i <= n; i++)
        {
            G[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        find_scc(n);
        if (toposort())
        {
            printf("I love you my love and our love save us!\n");
        }
        else
        {
            printf("Light my fire!\n");
        }
    }
}
