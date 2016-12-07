#include<bits/stdc++.h>
using namespace std;
//#define LOCAL
#define ll long long
bool prime[100005];


int main()
{
#ifdef LOCAL
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif	
	prime[0]=1;
	prime[1]=1;
	for(int i=2;i<=100005;++i)
	{
		if(prime[i]==0)
		{			
			for(int j=i+i;j<=100005;j+=i)	
			{
				prime[j]=1;
			}
		}
	}
	ll n,k;
	while(cin>>n){
		int x,ans = 0;
		for(int i=0;i<n;++i){
			cin>>x;
			if(prime[x] == 0)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

