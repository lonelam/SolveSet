#include<deque>
//#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 51;
const int maxp = 11;
const int inf = 0x3f3f3f3f;
int G[maxn * 2][maxn * 2];
int Source[maxn * 2][maxp];
int Dest[maxn * 2][maxp];
int Q[maxn * 2];
int Layer[maxn * 2];
int Flow[maxn * 2][maxn * 2];
bool vis[maxn * 2];
//int pre[maxn * 2];
bool cntLayer(int s, int t)

{
    int layer = 0;
    deque<int> q;
    memset(Layer, -1, sizeof(Layer));
    Layer[s] = 0;
    q.push_back(s);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop_front();
        for(int i = 0; i <= t; i++)
        {
            if(G[cur][i] > Flow[cur][i] && Layer[i] == -1)
            {

                Layer[i] = Layer[cur] + 1;

                q.push_back(i);
            }
        }
    }
    return Layer[t] != -1;
}
int Dinic(int s, int t)
{
    deque<int> q;
    int ans = 0;
    memset(Flow,0,sizeof(Flow));
    while(cntLayer(s, t))
    {
        memset(vis, 0, sizeof(vis));
        q.push_back(s);
       // printf("debug");
        vis[s] = true;
        while(!q.empty())
        {
            int cur = q.back();
      //      q.pop_back();
            int i;
            if(cur == t)
            {
                int Augflow = inf;
                int popto;
                int dn = t;
                for(int i = 1; i < q.size(); i++)
                {
                    int from = q[i - 1];
                    int to = q[i];
                    if(Augflow > G[from][to] - Flow[from][to])
                    {
                        popto = from;
                        Augflow = G[from][to] - Flow[from][to];
                    }
                }
                for(int i = 1; i < q.size(); i++)
                {
                    int from = q[i - 1];
                    int to = q[i];
                    Flow[from][to] += Augflow;
                    Flow[to][from] -= Augflow;
                }
                while(!q.empty() &&  q.back()!= popto)
                {
                    vis[q.back()] = false;
                    q.pop_back();
                }
                ans += Augflow;
               // printf("debug");
                continue;
            }
            for(i = 0; i <= t; i++)
            {
                if(G[cur][i] > Flow[cur][i] && !vis[i] && Layer[cur] + 1 == Layer[i])
                {
                    q.push_back(i);
                 //  printf("debug");
                    vis[i] = true;
                    break;
                }
            }
            if(i == t + 1)
            {

                //vis[cur] = false;
                q.pop_back();
            }
        }
    }
    return ans;
}
vector<deque<int> > path(int n)
{
    vector<deque<int> > ans;
    queue<deque<int> > q;
    int s = 2 * n;
    int t = 2 * n + 1;
    deque<int> tmp;
    tmp.push_back(s);
    q.push(tmp);
    while(!q.empty())
    {
        deque<int> cur = q.front();
        q.pop();
        if(cur.back() == t)
        {
            ans.push_back(cur);
        }
        else
        {
            for(int i = 0; i <= t; i++)
            {
                if(Flow[cur.back()][i] > 0)
                {
                    cur.push_back(i);
                    q.push(cur);
                    cur.pop_back();
                }
            }
        }
    }
    return ans;
}
int main()
{
    int p, n;
    while(scanf("%d%d",&p,&n)!=EOF)
    {
        int start = 2 * n;
        memset(G, 0, sizeof(G));
        int end = 2 * n + 1;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",Q + i);
            for(int j = 0; j < p; j++)
            {
                scanf("%d", Source[i] + j);

            }
            for(int j = 0; j < p; j++)
            {
                scanf("%d",Dest[i] + j);
            }
        }
        for(int i = 0; i < n; i++)
        {
            G[i][i + n] = Q[i];
         //   printf("debug: edge %d %d\n",i, i + n);
            bool from0 = true, end0 = true;
            for(int j = 0; j < p; j++)
            {
                if(Source[i][j] == 1)
                {
                    from0 = false;
                }
                if(Dest[i][j] == 0)
                {
                    end0 = false;
                }
            }
            if(from0)
            {
                G[start][i] = inf;
           //     printf("from to: %d\n",i);
            }
            if(end0)
            {
                G[i + n][end] = inf;
             //   printf("end to %d\n",i + n);
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                bool isto = true;
                for(int k = 0; k < p; k++)
                {
                    if((Dest[i][k] == 1 && Source[j][k] == 0)||(Dest[i][k] == 0 && Source[j][k] == 1))
                    {
                        isto = false;
                        break;
                    }
                }
                if(isto && i!= j)
                {
                    G[i + n][j] = inf;
                 //   printf("debug:edge %d %d\n", i, j);
                }
            }
        }
        int tot = Dinic(start, end);
        vector<deque<int> > ans = path(n);
        int ecnt = 0;
        for(int i = 0; i < ans.size(); i++)
        {

            ecnt += ans[i].size()/ 2 - 2;
        }
        printf("%d %d\n",  tot, ecnt);
        for(int i = 0; i < ans.size(); i++)
        {
            int cf = inf;
            for(int j = 1; j < ans[i].size(); j++)
            {
                int to = ans[i][j], from = ans[i][j - 1];
                cf = min(Flow[from][to], cf);
                //if(from < n)
              //  printf("%d %d %d\n", from + 1, to + 1, cf);
            }
            for(int j = 1; j < ans[i].size(); j++)
            {
                int to = ans[i][j], from = ans[i][j - 1];
                if(to < n && from != start)
                {
                    printf("%d %d %d\n", from - n + 1, to +1, cf);
                }
            }
          //  printf("%d\n", cf);

        }
    //    printf("%d ",tot);
    }
}


