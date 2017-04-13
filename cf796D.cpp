#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 100;
vector<pii> G[maxn];
int vis[maxn];
int euse[maxn];
int n, k, d;
queue<int> Q;
int u,v;
int main()
{

    scanf("%d%d%d", &n, &k, &d);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &u);
        Q.push(u);
        vis[u] = true;
    }
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    vector<int> ans;
    while(!Q.empty())
    {
        int c = Q.front();
        Q.pop();
            for (int i = 0; i < G[c].size(); i++)
            {
                if (!euse[G[c][i].second])
                {
                    if (!vis[G[c][i].first])
                    {
                        vis[G[c][i].first] = true;
                        Q.push(G[c][i].first);
                    }
                    else
                    {
                        ans.push_back(G[c][i].second);
                    }
                    euse[G[c][i].second] = true;
                }
            }
    }
    printf("%d\n", ans.size());
    if (ans.size()) printf("%d", ans[0]);
    for (int i = 1; i < ans.size(); i++)
    {
        printf(" %d", ans[i]);
    }
    printf("\n");

}
