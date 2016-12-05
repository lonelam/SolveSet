#include<bits/stdc++.h>

using namespace std;

const int maxn = 15;
const int maxh = 1 << maxn; //h represent the state

int dp[maxh];//initially inf;
int cost[maxn];
int ddl[maxn];
int pre[maxh];
bool in[maxh];
char name[maxn][105];
int N;
const int inf = 0x3f3f3f3f;

int lsb_p(int h1, int h2)
{
    int ans = h1 ^ h2;
    int i = 0;
    while(ans)
    {
        if(ans & 1 )
        {
            return i;
        }
        ans >>= 1;
        i++;
    }
    return -1;
}
void spfa()
{
    queue<int> q;
    q.push(0);
    memset(dp, inf, sizeof(dp));
    dp[0] = 0;
    memset(in,0, sizeof(in));
    in[0] = true;
    while(!q.empty())
    {
        int pre_h = q.front();
        q.pop();
        in[pre_h] = false;
        int t = 0;
        for(int i = 0; i < N; i++)
        {
            if(pre_h & (1 << i))
            {
                t += cost[i];
            }
        }
        for(int i = 0; i < N; i++)
        {
            const int nex_h = pre_h | (1 << i);

            if(!(pre_h & (1 << i)))//pre没有做i
            {

                int tt = t + cost[i];
                int tdp = dp[pre_h];
                for(int j = 0; j < N; j++)
                {
                    //pre没做j
                    if(!(pre_h & (1 << j)) && ddl[j] < tt)
                    {
                        if(ddl[j] < t)
                            tdp += cost[i];
                        else
                            tdp += tt - ddl[j];
                    }
                }
                if(tdp > dp[nex_h])
                    continue;
                if(tdp == dp[nex_h] &&(lsb_p(pre_h, nex_h) <= lsb_p(pre[nex_h],nex_h)))
                    continue;
                dp[nex_h] = tdp;
                pre[nex_h] = pre_h;
                if(!in[nex_h])
                {
                    q.push(nex_h);
                 //   printf("debug%d  %d\n",nex_h, i);
                    in[nex_h] = true;
                }
            }
        }
    }

}
void iter()
{
    queue<int> q[2];
    int flip = 0;
    q[flip].push(0);
    memset(dp, inf, sizeof(dp));
    memset(in, 0, sizeof(in));
    dp[0] = 0;
    int lay = 0;
    in[0] = true;
    while(!q[flip].empty())
    {
        while(!q[flip].empty())
        {
            int ch = q[flip].front();
            in[ch] = false;
            q[flip].pop();
            int t = 0;
            for(int i = 0; i < N; i++)
            {
                if(ch & (1 << i))
                {
                    t += cost[i];
                }
            }
            for(int i = 0; i < N; i++)
            {
                const int nh = ch | (1 << i);
                if(!(ch & (1 << i)))
                {
                    int tt = t + cost[i];
                    int tdp = dp[ch];
                    for(int j = 0; j < N; j++)
                    {
                        if(!(ch & (1 << j)) && ddl[j] < tt)
                        {
                            if(ddl[j] < t)
                            {
                                tdp += cost[i];
                            }
                            else
                            {
                                tdp += tt - ddl[j];
                            }
                        }
                    }
                    if(!in[nh])
                    {
                        q[flip ^ 1].push(nh);
                        in[nh] = true;
                    }
                    if(tdp < dp[nh]);
                    {
                        dp[nh] = tdp;
                        pre[nh] = ch;

                    }

                }
            }
        }
        lay++;
        flip ^= 1;
    }
}

int main()
{
    int t, d, c;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", & N);
       // memset(dp, inf, sizeof(dp));
        for(int i = 0; i < N; i++)
        {
            scanf("%s%d%d", name[i], ddl + i, cost + i);
        }
        spfa();
        //iter();
        int last = (1 << (N)) - 1;
        if(dp[last] != inf)
        {
            printf("%d\n", dp[last]);
            stack<char *> out;
            while(last)
            {

                out.push(name[lsb_p(last, pre[last])]);
                last = pre[last];
            }
            while(!out.empty())
            {
                printf("%s\n",out.top());
                out.pop();
            }
        }
        else
        {
            char *  erro = new char[10000000];
        }
    }
}
