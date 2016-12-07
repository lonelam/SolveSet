#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define LOCAL
bool isp(int n){
	for(int i=2;i*i<=n;++i){
		if(n%i == 0)return false;
	}
	return true;
}

int main()
{
#ifdef LOCAL
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif	
	ll n;
	while(cin>>n){
		if(isp(n))cout<<1<<endl;
		else if(n%2==0)cout<<2<<endl;
		else {
			if(isp(n-2))cout<<2<<endl;
			else cout<<3<<endl;
		}
	}
	return 0; 
} 
