#include<bits/stdc++.h>

using namespace std;

int G[600][600];

int Prev[600];

bool Vis[600];

int Layer[600];

const int inf = 0x3f3f3f3f;

int n, m;//n edges and m vertecis

bool CountLayer()
{
    int layer = 0;
    deque<int> q;
    memset(Layer, 0xff, sizeof(Layer));
    Layer[1] = 0;
    q.push_back(1);
    while(!q.empty())
    {
        int v = q.front();
        q.pop_front();
    //    q.pop_front();
       // printf("debug:%d     ",q.front());
       // q.pop_front();
        for(int j = 1; j <= m; j++)
        {
           // printf("debug:%d\n",j);
            if( (G[v][j] > 0) && (Layer[j] == -1))
            {
                Layer[j] = Layer[v] + 1;
                if(j == m)
                {
                    return true;
                }
                else
                {
                    q.push_back(j);
                  printf("debug:%d %d  %d\n", v, j, G[v][j]);
                }
            }

        }
    }
 //   printf("debug\n");
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
        memset(Vis, 0, sizeof(Vis));
        Vis[1] = true;
        while(!q.empty())
        {
            int nd = q.back();
            if(nd == m)
            {
                int nMinC = inf;
                int nMinC_vs;
                for(int i = 1; i < q.size(); i++)
                {
                    int vs = q[i - 1];
                    int ve = q[i];
                    if(G[vs][ve] > 0)
                    {
                        if(nMinC > G[vs][ve])
                        {
                            nMinC = G[vs][ve];
                            nMinC_vs = vs;
                        }
                    }
                }
                nmaxflow += nMinC;
                for(int i = 1; i < q.size(); i++)
                {
                    int vs = q[i - 1];
                    int ve = q[i];
                    G[vs][ve] -= nMinC;
                    G[ve][vs] += nMinC;
                }
                //ÍËÕ»µ½nMinC_vs
                while(!q.empty() && q.back()!= nMinC_vs)
                {
                    Vis[q.back()] = 0;
                    q.pop_back();
                }
            }
            else
            {
                for(int i = 1; i <= m; i++)
                {
                    if(G[nd][i] > 0 && Layer[i] == Layer[nd] + 1 && !Vis[i])
                    {
                        Vis[i] = true;
                        q.push_back(i);
                        break;
                    }
                }
                if(i > m)
                {
                    q.pop_back();
                }
            }
        }
    }
  //  printf("debug\n");
    return nmaxflow;
}

int main()
{
    while(cin >> n >> m)
    {

        int i, j, k;
        int s, e, c;
        memset(G, 0, sizeof(G));
        for(i = 0; i < n; i++)
        {
            cin >> s>> e>>c;
            G[s][e] += c;
        }
        cout<<Dinic() << endl;
    }
    return 0;
}

