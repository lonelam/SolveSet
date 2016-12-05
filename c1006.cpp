#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int maxm = 500005;
int a[maxn];
vector<int> G[maxn];
bool vis[maxn];
bool bfs(int n)
{
    queue<int> q;
    q.push(1);
    memset(vis, 0, sizeof(vis));
    vis[1] = true;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int to : G[cur])
        {
            if(!vis[to])
            {
                q.push(to);
                vis[to] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    int m,n;
    int f, to;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
      //  memset(G,0, sizeof(G));
        for(int i = 1; i <= n; i++)
        {
            G[i].clear();
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", a +i);
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &f, &to);
            G[f].push_back(to);
            G[to].push_back(f);
        }
        int cnt = 0;
        int odds[2];
        for(int i = 1; i <= n; i++)
        {
            if(G[i].size() & 1)
            {
                cnt++;
                if(cnt < 3)
                {
                    odds[cnt - 1] = i;
                }
                else
                {
                   // cnt++;
                    break;
                }
            }
        }
        if(bfs(n))
        {
            int sum = 0;
            int ans = 0;
            if(cnt == 0)
            {
                for(int i = 1; i <= n; i++)
                {
                    int tim = G[i].size() / 2;
                    for(int k = 0; k < tim; k++)
                    {
                        sum ^= a[i];
                    }

                }

                for(int i = 1; i <= n; i++)
                {
                    ans = max(ans, sum ^ a[i]);
                }

                printf("%d\n", ans);
            }
            else if( cnt == 2)
            {
                for(int i = 1; i <= n; i++)
                {
                    int tim = G[i].size() / 2;
                    for(int k = 0; k < tim; k++)
                    {
                        sum ^= a[i];
                    }
                }
                sum ^= a[odds[0]];
                sum ^= a[odds[1]];
                printf("%d\n",sum);
            }
            else
            {
                printf("Impossible\n");
            }
        }
        else
        {
            printf("Impossible\n");
        }
    }
}
