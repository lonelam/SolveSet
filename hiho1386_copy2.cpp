#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#define inf 0x3f3f3f3f
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define ou(a) printf("%d\n",a)
#define pb push_back
#define mkp make_pair
template<class T>inline void rd(T &x)
{
    char c=getchar();
    x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))
    {
        x=x*10+c-'0';
        c=getchar();
    }
}
#define IN freopen("in.txt","r",stdin);
#define OUT freopen("out.txt","w",stdout);
using namespace std;
const int mod=1e9;
const int N=1e3+10;
pair<int,LL> dp[N][4][6][6][2];
struct wq
{
    char s[12];
    int val,cost;
} a[510];
bool cmp(wq a,wq b)
{
    return a.val>b.val;
}
set<int>eg[1500];
int main()
{
    int t,n,all;
    rd(t);
    while(t--)
    {
        rd(n);
        rep(i,1,n) scanf("%s",a[i].s),rd(a[i].val),rd(a[i].cost);
        rd(all);
        sort(a+1,a+n+1,cmp);
        memset(dp,0,sizeof(dp));
        int ansval=0,anscost=0;
        rep(i,0,1400) eg[i].clear();
        LL anssum=0;
        rep(i,1,n)
        {
            if(a[i].s[0]=='F')
            {
                dep(f,3,1)dep(m,5,0)dep(d,5,0)dep(g,1,0)
                {
                    int hs=(f-1)*100+m*10+d+g*1000;
                    if(f+m+d+g>11||eg[hs].size()==0) continue;
                    for(auto j:eg[hs])
                    {
                        int c=j+a[i].cost;
                        if(c>all) continue;
                        if(dp[c][f][m][d][g].first<dp[c-a[i].cost][f-1][m][d][g].first+a[i].val)
                        {
                            dp[c][f][m][d][g].first=dp[c-a[i].cost][f-1][m][d][g].first+a[i].val;
                            dp[c][f][m][d][g].second=dp[c-a[i].cost][f-1][m][d][g].second;
                            eg[hs+100].insert(c);
                        }
                        else if(dp[c][f][m][d][g].first==dp[c-a[i].cost][f-1][m][d][g].first+a[i].val)
                        {
                            dp[c][f][m][d][g].second+=dp[c-a[i].cost][f-1][m][d][g].second;
                            if(dp[c][f][m][d][g].second>mod) dp[c][f][m][d][g].second=mod;
                            eg[hs+100].insert(c);
                        }
                    }
                }
                if(a[i].val*2>dp[a[i].cost][1][0][0][0].first)
                {
                    dp[a[i].cost][1][0][0][0].first=a[i].val*2;
                    dp[a[i].cost][1][0][0][0].second=1;
                    eg[100].insert(a[i].cost);
                }
                else if(a[i].val*2==dp[a[i].cost][1][0][0][0].first)
                {
                    dp[a[i].cost][1][0][0][0].second++;
                    eg[100].insert(a[i].cost);
                }
            }
            else if(a[i].s[0]=='M')
            {
                dep(m,5,1)dep(f,3,0)dep(d,5,0)dep(g,1,0)
                {
                    int hs=f*100+(m-1)*10+d+g*1000;
                    if(f+m+d+g>11||eg[hs].size()==0) continue;
                    for(auto j:eg[hs])
                    {
                        int c=j+a[i].cost;
                        if(c>all) continue;
                        if(dp[c][f][m][d][g].first<dp[c-a[i].cost][f][m-1][d][g].first+a[i].val)
                        {
                            dp[c][f][m][d][g].first=dp[c-a[i].cost][f][m-1][d][g].first+a[i].val;
                            dp[c][f][m][d][g].second=dp[c-a[i].cost][f][m-1][d][g].second;
                            eg[hs+10].insert(c);
                        }
                        else if(dp[c][f][m][d][g].first==dp[c-a[i].cost][f][m-1][d][g].first+a[i].val)
                        {
                            dp[c][f][m][d][g].second+=dp[c-a[i].cost][f][m-1][d][g].second;
                            if(dp[c][f][m][d][g].second>mod) dp[c][f][m][d][g].second=mod;
                            eg[hs+10].insert(c);
                        }
                    }
                }
                if(a[i].val*2>dp[a[i].cost][0][1][0][0].first)
                {
                    dp[a[i].cost][0][1][0][0].first=a[i].val*2;
                    dp[a[i].cost][0][1][0][0].second=1;
                    eg[10].insert(a[i].cost);
                }
                else if(a[i].val*2==dp[a[i].cost][0][1][0][0].first)
                {
                    dp[a[i].cost][0][1][0][0].second++;
                    eg[10].insert(a[i].cost);
                }
            }
            else if(a[i].s[0]=='D')
            {
                dep(d,5,1)dep(f,3,0)dep(m,5,0)dep(g,1,0)
                {
                    int hs=f*100+m*10+d-1+g*1000;
                    if(f+m+d+g>11||eg[hs].size()==0) continue;
                    for(auto j:eg[hs])
                    {
                        int c=j+a[i].cost;
                        if(c>all) continue;
                        if(dp[c][f][m][d][g].first<dp[c-a[i].cost][f][m][d-1][g].first+a[i].val)
                        {
                            dp[c][f][m][d][g].first=dp[c-a[i].cost][f][m][d-1][g].first+a[i].val;
                            dp[c][f][m][d][g].second=dp[c-a[i].cost][f][m][d-1][g].second;
                            eg[hs+1].insert(c);
                        }
                        else if(dp[c][f][m][d][g].first==dp[c-a[i].cost][f][m][d-1][g].first+a[i].val)
                        {
                            dp[c][f][m][d][g].second+=dp[c-a[i].cost][f][m][d-1][g].second;
                            if(dp[c][f][m][d][g].second>mod) dp[c][f][m][d][g].second=mod;
                            eg[hs+1].insert(c);
                        }
                    }
                }
                if(a[i].val*2>dp[a[i].cost][0][0][1][0].first)
                {
                    dp[a[i].cost][0][0][1][0].first=a[i].val*2;
                    dp[a[i].cost][0][0][1][0].second=1;
                    eg[1].insert(a[i].cost);
                }
                else if(a[i].val*2==dp[a[i].cost][0][0][1][0].first)
                {
                    dp[a[i].cost][0][0][1][0].second++;
                    eg[1].insert(a[i].cost);
                }
            }
            else
            {
                dep(f,3,0)dep(m,5,0)dep(d,5,0)
                {
                    int hs=f*100+m*10+d;
                    if(f+m+d+1>11||eg[hs].size()==0) continue;
                    for(auto j:eg[hs])
                    {
                        int c=j+a[i].cost;
                        if(c>all) continue;
                        if(dp[c][f][m][d][1].first<dp[c-a[i].cost][f][m][d][0].first+a[i].val)
                        {
                            dp[c][f][m][d][1].first=dp[c-a[i].cost][f][m][d][0].first+a[i].val;
                            dp[c][f][m][d][1].second=dp[c-a[i].cost][f][m][d][0].second;
                            eg[hs+1000].insert(c);
                        }
                        else if(dp[c][f][m][d][1].first==dp[c-a[i].cost][f][m][d][0].first+a[i].val)
                        {
                            dp[c][f][m][d][1].second+=dp[c-a[i].cost][f][m][d][0].second;
                            if(dp[c][f][m][d][1].second>mod) dp[c][f][m][d][1].second=mod;
                            eg[hs+1000].insert(c);
                        }
                    }
                }
                if(a[i].val*2>dp[a[i].cost][0][0][0][1].first)
                {
                    dp[a[i].cost][0][0][0][1].first=a[i].val*2;
                    dp[a[i].cost][0][0][0][1].second=1;
                    eg[1000].insert(a[i].cost);
                }
                else if(a[i].val*2==dp[a[i].cost][0][0][0][1].first)
                {
                    dp[a[i].cost][0][0][0][1].second++;
                    eg[1000].insert(a[i].cost);
                }
            }
            //printf("%d\n",i);
            //rep(f,0,3)rep(m,0,5)rep(d,0,5)rep(g,0,1)rep(c,0,all) if(dp[c][f][m][d][g].second) printf("%d %c %d %d %d %d %d %d %lld\n",i,a[i].s[0],f,m,d,g,c,dp[c][f][m][d][g].first,dp[c][f][m][d][g].second);
            //system("pause");
        }
        rep(f,1,3)rep(m,2,5)rep(d,3,5)
        {
            if(f+m+d<10) continue;
            if(f+m+d>10) break;
            int hs=f*100+m*10+d+1000;
            //printf("%d %d\n",hs,eg[hs].size());
            if(!eg[hs].size()) continue;
            for(auto j:eg[hs])
            {
                int c=j;
                //printf("%d %d %lld\n",c,dp[c][f][m][d][1].first,dp[c][f][m][d][1].second);
                if(dp[c][f][m][d][1].first>ansval)
                {
                    ansval=dp[c][f][m][d][1].first;
                    anscost=c;
                    anssum=dp[c][f][m][d][1].second;
                }
                else if(dp[c][f][m][d][1].first==ansval)
                {
                    if(c<anscost)
                    {
                        anscost=c;
                        anssum=dp[c][f][m][d][1].second;
                    }
                    else if(c==anscost)
                    {
                        anssum+=dp[c][f][m][d][1].second;
                        if(anssum>mod) anssum=mod;
                    }
                }
            }
        }
        if(anssum>mod) anssum=mod;
        printf("%d %d %lld\n",ansval,anscost,anssum);
    }
    return 0;
}
