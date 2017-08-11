
//#include<CSpreadSheet.h>

#include<iostream>
#include<cmath>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<string>
#include<string.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<ctime>
#include<bitset>
#include<cmath>
#define eps 1e-6
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define ll __int64
#define LL long long
#define lson l,m,(rt<<1)
#define rson m+1,r,(rt<<1)|1
#define M 1000000007
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

#define Maxn 410000

bool isp[Maxn];
ll pri[Maxn],pp[Maxn],cnt0,cnt;
ll x,y;
ll ans1,ans2;
map<int,int>myp;
int cc,n,m,p;
struct Cha
{
    int old,ne;
}cha[1100];

void init()  //打质数表
{
    cnt=0;
    int N=400000;

    for(int i=1;i<=N;i++)
        isp[i]=true;
    for(int i=2;i<=N;i++)
    {
        if(isp[i])
        {
            pri[++cnt]=i;
            for(int j=i*2;j<=N;j+=i)
                isp[j]=false;
        }
    }
}
void cal(ll cur) //分解质因数
{
    cnt0=0;

    for(int i=1;pri[i]*pri[i]<=cur;i++)
    {
        if(!(cur%pri[i]))
        {
            pp[++cnt0]=pri[i];
            while(!(cur%pri[i]))
                cur/=pri[i];
        }
    }
    if(cur!=1)
        pp[++cnt0]=cur;

}
void dfs(ll hav,int cur,int num) //容斥原理求出不互质的
{
    if((hav>x&&hav>y)||cur>cnt0)
        return ;
    for(int i=cur;i<=cnt0;i++)
    {
        ll next=hav*pp[i];

        ll tt1=y/next,tt2=x/next;

        if(num&1)
        {
            ans1-=(1+tt1)*tt1/2*next;
            ans2-=(1+tt2)*tt2/2*next;
        }
        else
        {
            ans1+=(1+tt1)*tt1/2*next;
            ans2+=(1+tt2)*tt2/2*next;
        }
        dfs(next,i+1,num^1);

    }
}
ll gcd(ll a,ll b)
{
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
int main()
{

    //printf("%I64d\n",gcd(12,18));
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   init();

   int t;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d%d",&n,&m);
       myp.clear();
       cc=0;

       while(m--)
       {
           int a;

           scanf("%d",&a);
           if(a==1)
           {
               scanf("%I64d%I64d%I64d",&x,&y,&p);
               if(x>y)
                    swap(x,y);
               x--;   //注意x要减一
               cal(p);
               ll ans;
               ans1=(1+y)*y/2,ans2=(1+x)*x/2;

               for(int i=1;i<=cnt0;i++)
               {
                   ll tt1=y/pp[i],tt2=x/pp[i];

                   ans1-=(1+tt1)*tt1/2*pp[i];
                   ans2-=(1+tt2)*tt2/2*pp[i];

                   dfs(pp[i],i+1,0);
               }
               ans=ans1-ans2;
               for(int i=1;i<=cc;i++)
               {
                   if(cha[i].ne!=cha[i].old&&cha[i].old<=y&&cha[i].old>x) //要在[x,y]范围内找，x已经减了1
                   {
                       if(gcd(cha[i].old,p)==1) //之前已经加了
                            ans-=cha[i].old;
                       if(gcd(cha[i].ne,p)==1) //改了过后是否要加上
                            ans+=cha[i].ne;
                   }
               }
               printf("%I64d\n",ans);
           }
           else
           {
               scanf("%d%d",&x,&y);
               if(myp.find(x)==myp.end())
               {
                    ++cc;
                   myp[x]=cc;
                   cha[cc].ne=y,cha[cc].old=x;
               }
               else
                   cha[myp[x]].ne=y;

           }
       }

   }

   return 0;
}
