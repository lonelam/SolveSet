#include<bits/stdc++.h>
using namespace std;
//#define LOCAL
#define ll long long
ll Pow(ll a,ll n,ll mod) 
{
	ll ans=1;
	while(n)
	{
		if(n&1)
		{
			ans=ans*a;
			ans%=mod;
		}
		a*=a;
		a%=mod;
		n>>=1;
	}
	ans%=mod;
	return ans;
}

int main()
{
#ifdef LOCAL
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	ll n,k;
	while(cin>>n>>k){
		n = n%10;
		ll ans = Pow(n,k,10);
		cout<<ans<<endl;
	}
	return 0;
}
