#include<bits/stdc++.h>
using namespace std;
//#define LOCAL
int a[100005];

int main()
{
#ifdef LOCAL
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif	
	int n,k;
	while(cin>>n>>k){
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		sort(a,a+n);
		long long ans = 0;
		for(int i=n-1-k;i<n;++i){
			ans += a[i];
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
