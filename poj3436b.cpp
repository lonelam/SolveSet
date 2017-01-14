#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 105
#define maxm 5500
#define maxnum 2600
#define maxp 15
const int inf = ~0u >> 1;
struct edge
{
    int p,next,val,anti;
    edge(){}
    edge(int _p,int _n,int _v,int _a):p(_p),next(_n),val(_v),anti(_a){}
}e[maxm];
int flow[maxn],pre[maxn],cnt[maxn],d[maxn],v[maxn],path[maxn],arc[maxn];
int tot,P,n,N,Count;
void init()
{
    tot = 0;
    Count = 0;
    fill(v,v + n + 1,-1);
    memset(cnt,0,sizeof(cnt));
    memset(d,0,sizeof(d));
    cnt[0] = n + 1;
}
void add(int p,int q,int val)
{
    e[tot] = edge(q,v[p],val,tot + 1);
    v[p] = tot++;
    e[tot] = edge(p,v[q],0,tot - 1);
    v[q] = tot++;
}
int mflow()
{
    int s = 0,t = n;
    int i,k,loc,least,sum,now;
    bool flag;
    for(int i = 0;i <= n;i++)arc[i] = v[i];
    for(sum = 0,i = s,now = inf;d[s] < n + 1;)
    {
        flow[i] = now;
        for(flag = false,k = arc[i];~k;k = e[k].next)
        {
            if(e[k].val && d[i] == d[e[k].p] + 1)
            {
                now = min(e[k].val,now);
                pre[e[k].p] = i;
                path[e[k].p] = k;
                arc[i] = k;
                i = e[k].p;
                if(i == t)
                {
                    for(sum += now;i != s;i = pre[i])
                    {
                        e[path[i]].val -= now;
                        e[path[i] ^ 1].val += now;
                    }
                    now = inf;
                }
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            for(least = n + 1,k = v[i];~k;k = e[k].next)
            {
                if(e[k].val && d[e[k].p] < least)
                {
                    least = d[e[k].p];
                    loc = k;
                }
            }
            cnt[d[i]]--;
            if(cnt[d[i]] == 0)
                break;
            arc[i] = loc;
            d[i] = least + 1;
            cnt[d[i]]++;
            if(i != s)
            {
                i = pre[i];
                now = flow[i];
            }
        }
    }
    return sum;
}
int line[maxnum],from[maxnum],to[maxnum],cost[maxnum];
int in[maxn][maxp],out[maxn][maxp];
int main()
{
    scanf("%d %d",&P,&N);
    n = 2 * N + 1;
    init();
    for(int i = 1;i <= N;i++)
    {
        int val;
        scanf("%d",&val);
        add(i,i + N,val);
        for(int j = 0;j < P;j++)
            scanf("%d",&in[i][j]);
        for(int j = 0;j < P;j++)
            scanf("%d",&out[i][j]);
    }
    for(int i = 1;i <= N;i++)
    {
        bool flag = true;
        for(int j = 0;j < P;j++)
        {
            if(in[i][j] == 1)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            add(0,i,inf);
        flag = true;
        for(int j = 0;j < P;j++)
        {
            if(out[i][j] == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            add(i + N,n,inf);
    }
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= N;j++)
        {
            bool flag = true;
            for(int k = 0;k < P;k++)
            {
                if(out[i][k] == in[j][k] || in[j][k] == 2)
                    continue;
                flag = false;
                break;
            }
            if(flag)
            {
                line[Count] = tot;
                cost[Count] = inf;
                add(i + N,j,inf);
                from[Count] = i;
                to[Count++] = j;
            }
        }
    }
    int ans = mflow();
    int md = 0;
    if(ans)
    {
        for(int i = 0;i < Count;i++)
        {
            if(cost[i] - e[line[i]].val)
                md++;
        }
    }
    printf("%d %d\n",ans,md);
    if(!md)
        return 0;
    for(int i = 0;i < Count;i++)
        if(cost[i] - e[line[i]].val)
            printf("%d %d %d\n",from[i],to[i],cost[i] - e[line[i]].val);
}
