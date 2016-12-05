#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 205;
struct edge
{

    int to, w;

};

const int inf = 0x3f3f3f3f;
edge es[maxn << 1];
vector<int> G[maxn];
bool vis[maxn];
int cur[maxn];
int dis[maxn];
int pre[maxn];
int n, m;
bool bfs()
{

    queue<int> q, nex;
    q.push(1);
    int d = 0;
    vis[1] = true;
    while(!q.empty())
    {
        while(!q.empty())
        {
            int c = q.front();
            q.pop();
            if(c == n)
            {
                return true;
            }
            for(int i = 0; i < G[c].size(); i++)
            {
                if(es[G[c][i]].w > 0 && !vis[es[G[c][i]].to])
                {
                    vis[es[G[c][i]].to] = true;
                    q.push(es[G[c][i]].to);
                    dis[es[G[c][i]].to] = d;
                }
            }
        }
        swap(q, nex);
        d++;
    }
    return false;
}
int Dinic()
{
    int ans = 0;
    pre[1] = 0;
    while(bfs())
    {
        memset(cur, 0, sizeof(cur));
        for(int i = 1; i <= n; i++)
        {
            for(int & j = cur[i];j < G[i].size(); j++)
            {
                int k = es[G[i][j]].to;
                int wt = es[G[i][j]].w;
                if(wt > 0&& dis[i] + 1 == dis[j])
                {
                    pre[j] = i;
                    if(k == n)
                    {
                        int p = n;
                        int mf = inf;
                        int backto = n;
                        while(pre[p])
                        {
                            p = pre[p];
                            if(mf > es[G[p][cur[p]]].w )
                            {
                                mf = es[G[p][cur[p]]].w;
                                backto = p;
                            }
                        }
                        p = n;
                        while(pre[p])
                        {
                            p = pre[p];
                            es[G[p][cur[p]]].w -= mf;
                            es[G[p][cur[p]]^ 1].w += mf;
                        }
                        i = backto;
                        j = cur[i];
                        ans += mf;

                    }
                    else
                    {
                        i = k;
                        j = cur[i];
                    }
                    continue;
                }

            }
        }
    }
    return ans;
}


int main()
{
    int u, v, w;
    while(scanf("%d%d", &m, &n)!= EOF)
    {
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            es[(i << 1)] = {v, w};
            G[u].push_back(i << 1);
            es[(i << 1) ^ 1] = {u, w};
            G[v].push_back((i << 1) ^ 1);
        }
        printf("%d\n",Dinic());
    }
}
