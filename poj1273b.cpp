#include<queue>
#include<cstdio>
#include<cstring>

using namespace std;

int G[300][300];
bool vis[300];
int layer[300];
const int inf = 0x3f3f3f3f;
int n, m;
bool CountLayer()
{
  //  int layer = 0;
    deque<int> q;
    memset(layer, -1, sizeof(layer));
    layer[1] = 0;
    q.push_back(1);
    while(!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for(int j = 1; j <= m; j++)
        {
            if(G[v][j] > 0 && layer[j] == -1)
            {
                layer[j] = layer[v] + 1;
                if(j == m)
                {
                    return true;
                }
                else
                {
                    q.push_back(j);
                }
            }
        }
    }
    return false;
}
int Dinic()
{
    int i;
    int s;
    int nmaxflow = 0;
    deque<int> q;
    while(CountLayer())
    {
        q.push_back(1);
        memset(vis, 0, sizeof(vis));
        vis[1] = 1;
        while(!q.empty())
        {
            int nd = q.back();
            if(nd == m)
            {
                int mc = inf;
                int rollback;
                for(int i = 1; i < q.size();i++)
                {
                    int vs = q[i - 1];
                    int ve = q[i];
                    if(G[vs][ve] > 0)
                    {
                        if(mc > G[vs][ve])
                        {
                            mc = G[vs][ve];
                            rollback = vs;
                        }
                    }
                }
                nmaxflow += mc;
                for(i = 1; i < q.size(); i ++)
                {
                    int vs = q[i - 1];
                    int ve = q[i];
                    G[vs][ve] -= mc;
                    G[ve][vs] += mc;
                }
                while(!q.empty() && q.back() != rollback)
                {
                    vis[q.back()] = 0;
                    q.pop_back();
                }
            }
            else
            {
                for(i = 1; i <= m; i++)
                {
                    if(G[nd][i] > 0 && layer[i] == layer[nd] + 1 && !vis[i])
                    {
                        vis[i] = 1;
                        q.push_back(i);
                        break;
                    }
                }
                if(i > m)
                    q.pop_back();
            }
        }
    }
    return nmaxflow;
}


int main()
{
    int u, v, w;
    while(scanf("%d%d", &n, &m)!= EOF)
    {
        memset(G, 0 ,sizeof(G));
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            G[u][v] +=  w;

        }
        printf("%d\n",Dinic());
    }
}
