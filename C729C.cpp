#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;
const int maxn = 500000;
ll a[maxn];
ll b[maxn];
int n;
ll cnt[maxn];
int sum(int pos)
{
	ll ans = 0;
	while(pos > 0)
	{
		ans += cnt[pos];
		pos -= pos & (-pos);
	}
	return ans;

}
void plusone(int pos)
{
	while(pos <= n)
	{
		cnt[pos]++;
		pos+= pos & (-pos);
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i = 0;i<n;i++)
		{
			scanf("%lld",a+i);
			b[i] = a[i];
		}
		sort(b,b+n);
		memset(cnt,0,sizeof(cnt));
		ll ans = 0;
		for(int i = 0;i<n;i++)
		{
			a[i] = lower_bound(b,b+n,a[i]) - b + 1;
			ans += i - sum(a[i]);
			//printf("a_%d = %d, i - sum(ai) = %d\n",i,a[i],i - sum(a[i]));
			plusone(a[i]);
		}
		printf("%lld\n",ans);
	}
}
