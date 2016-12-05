#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 ll;
const int maxn = 100005;
ll a[maxn];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0;i<n;i++)
		{
			scanf("%I64d",a+i);
		}
		ll ans = 0;
		sort(a,a+n);
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<32;j++)
			{
				const ll aj = (1<<j) - a[i];
				const ll * lr = lower_bound(a,a+i,aj);
				const ll * up = upper_bound(a,a+i,aj);
				if(lr != a+i && *lr == aj)
				{
					ans+= up - lr;
				}
			}
		}
		printf("%I64d\n",ans);
	}
}
