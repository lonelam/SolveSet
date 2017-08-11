
#include<iostream>
using namespace std;
typedef long long ll;
const int MOD=  10007;

//乘法逆元辅助函数
ll ex_gcd(ll a,ll b,ll &x,ll &y)
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
		ll tmp=x;
		x=y;
		y=tmp-a/b*y;
	}
}
//该函数返回乘法逆元
ll multi_reverse(ll b,ll p)//b是除法中的除数 相当于 a/b mod p中的b p是除法中的模数
{
	//x是乘法逆元
	ll x,y;
	ex_gcd(b,p,x,y);
	//处理得出最小正整数解
	x=(x%p+p)%p;
	return x;
}
//使用注意 a / b 先取模
ll c(ll m,ll n)
{
	if(n<m) return 0 ;
	ll ans=1;
	ll div=1;
	for(ll i=n;i>=1;i--) ans=ans*i%MOD;
	for(ll i=m;i>=1;i--) div=div*i%MOD;
	for(ll i=n-m;i>=1;i--) div=div*i%MOD;
	ll x,y;
	x=multi_reverse(div,MOD);
	return ans*x%MOD;
}

int main()
{
	ll n,m;
	while(cin >> n)
	{
		n--;
//		 printf("%d\n",(c(n,n<<1)+MOD-c(n-1,n<<1))%MOD*2%MOD);
		printf("%d\n", (c(n,2*n)*2%MOD  - c(n-1,2*n)*2%MOD+ MOD)  % MOD);
	}
}
