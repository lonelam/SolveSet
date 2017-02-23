//二分匹配
#include<iostream>
#include<cstdio>
#include <set>
#include <vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn=205;
int u,v;
int g[maxn][maxn];
int x[maxn],y[maxn],arr[maxn][maxn];
int chk[maxn];
//map<int,int> h[maxn];

int dfs(int k)
{
    for(int i=0;i<v;i++)
    {
        if(g[k][i]&&!chk[i])
        {
            chk[i]=1;
            if(y[i]==-1||dfs(y[i]))
            {
                y[i]=k;
                x[k]=i;
                return 1;
            }
        }
    }
    return 0;
}

int hungary()
{
    int ans=0;
    memset(x,-1,sizeof(x));
    memset(y,-1,sizeof(y));
    for(int i=0;i<u;i++)
    {
        if(x[i]==-1)
        {
            memset(chk,0,sizeof(chk));
            ans+=dfs(i);
        }
    }
    return ans;
}

int main()
{
    int a,b;
    int k;
    while(scanf("%d %d",&u,&k)==2)
    {
    //    memset(h,0,sizeof(h));

        if(u==0&&k==0)
            break;
        v=u;
        set<int> cls;
        for(int i=0;i<u;i++)
        {
            for(int j=0;j<u;j++)
            {
                scanf("%d",&arr[i][j]);
                cls.insert(arr[i][j]);
            }
        }
        vector<int> ans;
        for(int i:cls)
        {
            memset(g,0,sizeof(g));
            for(int j=0;j<u;j++)
            {
                for(int x=0;x<u;x++)
                {
                    if(arr[j][x]==i)
                    {
                        g[j][x]=1;
                    }
                }
            }
            if (hungary()> k) ans.push_back(i);
        }
//        set<int> ans;
        int i=0;

    //    if(i==50||i==u)
        if (ans.empty())
            printf("-1");
        else
        {
            printf("%d",ans[i++]);
            for(;i<ans.size();i++)
            {

                    printf(" %d",ans[i]);
            }
        }
        cout<<endl;
    }
    return 0;
}
