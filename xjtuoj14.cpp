#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 20000 + 100;
const ll moder = 1e9 + 7;
int a[maxn];
inline int lsb(int x)
{
    return x & (-x);
}
ll tot[maxn], ans1[maxn], ans2[maxn];
int n, m;
void add(int pos, ll num)
{
    while(pos <= n)
    {
        tot[pos] += num;
        tot[pos] %= moder;
        pos += lsb(pos);
    }
}
ll cal(int pos)
{
    ll ret = 0;
    while(pos > 0)
    {
        ret += tot[pos];
        ret %= moder;
        pos -= lsb(pos);
    }
    return ret;
}int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        if(m==1){printf("%d\n",n);continue;}
        for(int i=0;i<=n;i++)ans2[i]=1;
        for(int e=2;e<=m;e++)
        {
            for(int i=0;i<=n;i++)tot[i]=0,ans1[i]=ans2[i],ans2[i]=0;
            for(int i=n;i>=1;i--)
            {
                ans2[a[i]]=cal(a[i]);
                add(a[i],ans1[a[i]]);
            }
        }
        ll sum=0;
        for(int i=1;i<=n;i++)sum=(sum+ans2[i])%moder;
        printf("%lld\n",sum);
    }
    return 0;
}
