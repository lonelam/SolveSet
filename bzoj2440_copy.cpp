#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 55555
#define INF 2222222222
typedef long long ll;
bool check[maxn];
int prime[maxn],mu[maxn];
void Moblus(int n)
{
    memset(check,0,sizeof(check));
    mu[1]=1;
    int tot=0;
    for(int i=2;i<=n;i++)
    {
        if(!check[i])
        {
            prime[tot++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<tot;j++)
        {
            if(i*prime[j]>n)break;
            check[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                mu[i*prime[j]]=0;
                break;
            }
            else mu[i*prime[j]]=-mu[i];
        }
    }
}
ll count(ll x)
{
    ll ans=0;
    for(ll i=1;i*i<=x;i++)
        ans+=x/(i*i)*mu[i];
    return ans;
}
int main()
{
    Moblus(maxn-10);
    // printf("%lld\n",count(100000000));
    int T,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&k);
        ll l=k,r=INF,ans;
        while(l<=r)
        {
            ll mid=(l+r)>>1;
            if(count(mid)>=k)ans=mid,r=mid-1;
            else l=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
