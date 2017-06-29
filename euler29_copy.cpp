#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
#define N 1000001
#define M 21

ll cnt[N];
bool flag[N];
bool vis[M][N];

int gcd(int x,int y)
{
    int tmp;
    while (y)
    {
        tmp=x%y;
        x=y; y=tmp;
    }
    return x;
}

int lcm(int x,int y){return 1ll*x*y/gcd(x,y);}

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);

    int n,m=1; scanf("%d",&n);
    for (int i=2;i<=n;i<<=1,m++); m--;

    for (int i=2;i<=m;i++)
    {
        for (int j=1;j<i;j++)
        {
            int l=lcm(i,j),len1=l/j,len2=l/i;
            for (int k=1;k*len1<=n;k++) vis[i][k*len2]=true;
        }
    }
    cnt[1]=n-1;
    for (int i=2;i<=m;i++)
    {
        cnt[i]=cnt[i-1];
        for (int j=2;j<=n;j++) if (!vis[i][j]) cnt[i]++;
    }

    ll ans=0;
    for (int i=2;i<=n;i++)
    {
        if (flag[i]) continue;
        int p=0; ll x=i;
        do
        {
            flag[x]=true;
            p++; x*=i;
        }while (x<=n);
        ans+=cnt[p];
    }
    cout<<ans<<endl;
    return 0;
}
