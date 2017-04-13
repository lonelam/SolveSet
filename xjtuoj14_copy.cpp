/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/

#include<bits/stdc++.h>

using namespace std;

const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;

#define LL long long
#define IN freopen("test.in", "r", stdin)
#define OUT freopen("test.out", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

const LL mod=1e9+7;
const int maxn=20005;
int a[maxn];
LL tot[maxn],ans1[maxn],ans2[maxn];
int n,m;

void add(int pos,LL num)
{
    while(pos<=n)
    {
        tot[pos]+=num;
        tot[pos]%=mod;
        pos+=lowbit(pos);
    }
}

LL cal(int pos)
{
    LL ret=0;
    while(pos>0)
    {
        ret+=tot[pos];
        ret%=mod;
        pos-=lowbit(pos);
    }
    return ret;
}

int main()
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
        LL sum=0;
        for(int i=1;i<=n;i++)sum=(sum+ans2[i])%mod;
        printf("%lld\n",sum);
    }
    return 0;
}
