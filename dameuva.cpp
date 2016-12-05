
#include "stdio.h"
#include "string.h"
#include "iostream"
#include "algorithm"
#include "set"
typedef long long ll;
using namespace std;
//int mark[100001];
set<ll >dict;
int maxd;
ll finalden[100100];
ll den[100100];
ll get_first(ll a,ll b)
{

	return b/a+1;
}
ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
bool judge(int d)
{
	for(int i=d;i>=0;i--)
	{

		if(den[i]!=finalden[i])
		{
			return 	finalden[i]==-1||den[i]<finalden[i];
		}
	}
	return false;
}
bool dfs(int d,ll first,ll a, ll b)
{
	if(d==maxd)
	{
		if(b%a||dict.count(b/a))
			return false;
		den[d]=b/a;
		if(judge(d))
		{
			memcpy(finalden,den,sizeof(ll)*(d+1));
		}
		return true;


	}
	first=max(first,get_first(a,b));
	bool ok=false;
	for(int i=first;;i++)
	{
			if(!dict.count(i))
			{
				if(i*a>=(maxd+1-d)*b)
				break;
				den[d]=i;
				ll b2=b*i;
				ll a2=a*i-b;
				ll g=gcd(a2,b2);
				if(dfs(d+1,i+1,a2/g,b2/g))
					ok=true;
			}


	}
	return ok;
}
int main()
{
	int kk;
	int kkk=1;
	scanf("%d",&kk);
	while (kk--)
	{

		dict.clear();
		memset(den,0,sizeof(den));
		memset(finalden,-1,sizeof(finalden));
		ll a,b,k,t;
		scanf("%I64d%I64d%I64d",&a,&b,&k);
		for(int i=0;i<k;i++)
		{

			scanf("%I64d",&t);
			dict.insert(t);
		}

		for(maxd=1;;maxd++)
		{
			if(dfs(0,get_first(a,b),a,b))
				break;
		}
 	printf("Case %d: %lld/%lld=",kkk++,a,b);
      printf("1/%lld",finalden[0]);
      for(int i=1;i<=maxd;i++) printf("+1/%lld",finalden[i]);
      puts("");
	}
}

