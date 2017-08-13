#include<stdio.h>        //������ô��ͷ�ļ���
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxm=10000+100;    //��������
const int INF=0x3f3f3f3f;

struct edge{        //�ߣ����㡢�յ㡢��������������λ����
    int from,to,c,f,cost;
    edge(int a,int b,int m,int n,int p):from(a),to(b),c(m),f(n),cost(p){}
};

int aabs(int a){
    return a>=0?a:-a;
}
bool flg;
struct MCMF{
    int m,s,t;
    vector<edge>e;
    vector<int>g[maxm];
    int dis[maxm],a[maxm],p[maxm];
    bool vis[maxm];
    void init(int n){        //��ʼ������
        for(int i=0;i<=n;i++)g[i].clear();
        e.clear();
    }
    void clr()
    {
      for (int i = 0; i < m; i++)
      {
        e[i].f = 0;
      }
    }
    void add(int a,int b,int c,int v){    //�ӱߺ���
        e.push_back(edge(a,b,c,0,v));
        e.push_back(edge(b,a,0,0,-v));
        m=e.size();
        g[a].push_back(m-2);
        g[b].push_back(m-1);
    }
    bool spfa(int& flow,int& cost){
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        queue<int>q;
        q.push(s);
        vis[s]=1;
        dis[s]=0;
        p[s]=0;
        a[s]=INF;
        while(!q.empty()){
            int u=q.front();q.pop();
            vis[u]=0;
            for(int i=0;i<g[u].size();i++){
                edge tmp=e[g[u][i]];
                if(dis[tmp.to]>dis[u]+tmp.cost&&tmp.c>tmp.f){
                    dis[tmp.to]=dis[u]+tmp.cost;
                    p[tmp.to]=g[u][i];
                    a[tmp.to]=min(a[u],tmp.c-tmp.f);
                    if(!vis[tmp.to]){
                        q.push(tmp.to);
                        vis[tmp.to]=1;
                    }
                }
            }
        }
        //�����������������������¿���Ҫ�޸ģ�
        if(dis[t]==INF || dis[t] > 0)return 0;
        flow+=a[t];
        if (dis[t] < 0) flg = 0;
        cost+=dis[t]*a[t];
        int u=t;
        while(u!=s){
            e[p[u]].f+=a[t];
            e[p[u]^1].f-=a[t];
            u=e[p[u]].from;
        }
        return 1;
    }
    int MF(int s,int t, int & flow){
        this->s=s;this->t=t;
        flow=0;
        int cost=0;
        while(spfa(flow,cost));
        return cost;
    }
}G;
int main()
{
  int n, m;
  while(scanf("%d%d", &n, &m) != EOF)
  {
    int S = n + 1;
    int T = n + 2;
    int SS = n + 3;
    //edge 0 is SS->S
    G.init(n + 3);
    int ans = 0;
    G.add(SS, S, 0, 0);
    for (int i = 1; i <= n; i++)
    {
      static int a, b, c, d;
      scanf("%d%d%d%d", &a, &b, &c, &d);
      // G.add(S, i, b, 1000 - a);
      G.add(S, i, b, a);
      G.add(i, T, d, -c);
    }
    for (int i = 0; i < m; i++)
    {
      int u, v, k;
      scanf("%d%d%d", &u, &v, &k);
      G.add(u, v, INF, k);
      G.add(v, u, INF, k);
    }
    // int L = 0, R = 500000 + 1;
    // while(L + 1 < R)
    // {
      // const int mid = (L + R) / 2;
      // cout << mid << endl;
      // printf("%d\n", mid);
      G.e[0].c = INF;
      // G.clr();
      flg = true;
      int flow;
      int tmp = G.MF(SS, T, flow);
      tmp = -tmp;
      // if (flow == mid && flg)
      // {
        // L = mid;
      ans = max(ans, tmp);
    //   }
    //   else
    //   {
    //     R = mid;
    //   }
    // }
    printf("%d\n", ans);
  }
}
