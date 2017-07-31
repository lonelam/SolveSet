#include<iostream>
#include<cmath>
using namespace std;
const int MOD=1e4+7;
typedef long long ll;
ll f[MOD+5];
ll inv[MOD+5];
ll quick_multi(ll x,ll y)
{
	ll ans=1;
	while(y!=0)
	{
		if(y&1) ans=(ans*x)%MOD;
		x=(x*x)%MOD;
		y>>=1;
	}
	return ans;
}
void init()
{
	f[1]=1;
	for(int i=2;i<MOD;i++)
	{
		f[i]=f[i-1]*i%MOD;
	}
	inv[MOD-1]=quick_multi(f[MOD-1],MOD-2);
	for(int i=MOD-2;i>=1;i--)
	{
		inv[i]=inv[i+1]*(i+1)%MOD;
	}
}
ll c(ll m,ll n)
{
	if(n<m) return 0;
	return f[n]*inv[m]%MOD*inv[n-m]%MOD;
}
ll lucas(ll m,ll n)
{
	if(m!=0) return c(m%MOD,n%MOD)*lucas(m/MOD,n/MOD)%MOD;
	else return 1;
}
int main()
{
	ll n;
	init();
	while(cin >> n)
	{
		n--;
		cout << (lucas(n,n*2)+MOD-lucas(n-1,n*2))%MOD*2%MOD<<endl;
	}
}
