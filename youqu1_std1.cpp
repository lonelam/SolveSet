
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll ex_gcd(ll a,ll b,ll &x,ll &y)  //ÍØÕ¹Å·¼¸ÀïµÃ
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	else
	{
		ll r=ex_gcd(b,a%b,x,y);
		ll t=x;
		x=y;
		y=t-a/b*y;
		return r;
	}
}
int main()
{

	ll a,b,m,n,l;
	while(scanf("%lld %lld %lld %lld %lld",&a,&b,&m,&n,&l)==5)
	{
//		ll x,y;
//		ll d=ex_gcd(n-m,l,x,y);
//		if((a-b)%d)
//		{
//			cout <<"Impossible\n";
//			continue;
//		}
//		else
//		{
//			x=x*((a-b)/d);
//			ll r=l/d;
//			x=(x%r+r)%r;
//			printf("%lld\n",x);
//		}
		ll d,L,x,y;
		if(n-m>0)
		{
			d=ex_gcd(n-m,l,x,y);
			L=a-b;
		}
		else
		{
			d=ex_gcd(m-n,l,x,y);
			L=b-a;
		}
		if(L%d!=0)
		{
			cout <<"Impossible"<<endl;
			continue;
		 }
		 else
		 {
		   	 x=x*(L/d);
			 ll r=l/d;
			 x=(x%r+r)%r;
			 printf("%lld\n",x);
		 }
	}

}
