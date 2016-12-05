#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct edge
{
    int u, v, w;
};
typedef pair<int, int> pii;
edge es[maxn];
vector<int> G[maxn];
bool attacked[maxn];
bool vis[maxn];
deque<int> dij(int from,int &res)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
  //  printf("debug");
    memset(vis,0, sizeof(vis));
    int dist = 0;
    deque<int> ans;
    q.push({0, from});
    vis[from] = true;
    while(!q.empty())
    {
      //  printf("debug");
        pii cur = q.top();
        q.pop();
        int dis = cur.first;

        int pos = cur.second;
        if(dis > dist && !attacked[pos])
        {
            ans.clear();
            ans.push_back(pos);
            dist = dis;
        }
        else if( dis == dist && !attacked[pos])
        {
            ans.push_back(pos);
           // dist = dis;
        }
        for(int path : G[pos])
        {
            if(!vis[es[path].v])
            {
                q.push({dis + es[path].w, es[path].v});
                vis[es[path].v] = true;
            }
        }
    }
    res = dist;
    printf("debug:%d\n",dist);
    return ans;
}


int main()
{
    int t, n, u, v, w;

    scanf("%d",&t);
    memset(attacked,0, sizeof(attacked));
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            G[i].clear();
        }
        int tn = n - 1;
        for(int i = 0; i < tn; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            es[i << 1] = {u,v,w};
            es[(i << 1) + 1] = {v, u, w};
            G[u].push_back(i << 1);
            G[v].push_back((i << 1) + 1);
        }
        int di;
        deque<int> from = dij(1, di);
        deque<int> to = dij(from.front(), di);

        set<int> sig;
        while(!from.empty())
        {
            printf("from : %d\n", from.back());
            sig.insert(from.back());
            from.pop_back();
        }
        while(!to.empty())
        {
            printf("to: %d\n", to.back());
            sig.insert(to.back());
            to.pop_back();
        }
        int sum = (n - 1 - sig.size()) * di;
        for(int at : sig)
        {
            attacked[at] = true;
            deque<int> tmp = dij(1,di);
            tmp = dij(tmp.back(), di);
            sum += di;
        }

        printf("%d\n",sum);
    }
}
