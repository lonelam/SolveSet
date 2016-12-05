#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef __int64 ll;
int main()
{
	ll d,k,a,b,t;
	while(scanf("%I64d%I64d%I64d%I64d%I64d",&d,&k,&a,&b,&t)!=EOF)
	{
		if(a>= b)
		{
			printf("%I64d\n",b * d);
		}
		
		{
			ll ans = min(min((d-(d%k))*b,(d/k) * (a * k + t) - t),a*k + (d-(d%k) - k)*b);
		//	printf("%I64d\n",ans);
			if((d%k)*b <= t+ (d%k)*a)
			{
				ans += (d%k)*b;
			}
			else
			{
				ans += t+ (d%k)*a;
			}
			printf("%I64d\n",ans);
		}
	}
}
