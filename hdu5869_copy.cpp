#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
#define INF 0x3f3f3f3f
#define N 100005
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int n,q,ans[N],f[N],a[N],last[N*10];
vector<int> G[N];
int _gcd(int a,int b)
{
   if(b == 0) return a;
   a %= b;
   return _gcd(b,a);
}
int lowbit(int x)
{
	return x & (-x);
}
void Insert(int k,int x)
{
	while(k <= n)
	{
		f[k] += x;
		k += lowbit(k);
	}
}
int Find(int k)
{
	int ans = 0;
	while(k)
	{
		ans += f[k];
		k -= lowbit(k);
	}
	return ans;
}
struct thing
{
	int l,r;
}ask[N];
int main()
{
	while(~scanf("%d%d",&n,&q))
	{
		memset(last,0,sizeof(last));
		memset(f,0,sizeof(f));
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			G[i].clear();
		}
		for(int i = 1;i <= q;i++)
		{
			scanf("%d%d",&ask[i].l,&ask[i].r);
			G[ask[i].r].push_back(i);
		}
		vector<pii> pre;
		for(int i = 1;i <= n;i++)
		{
			vector<pii> tmp;
			pre.push_back(make_pair(a[i],i));
			for(pii v : pre)
			{
				if(tmp.size() && _gcd(v.first,a[i]) == tmp[tmp.size()-1].first)
          tmp[tmp.size()-1] = make_pair(_gcd(v.first,a[i]),v.second);
				else tmp.push_back(make_pair(_gcd(v.first,a[i]),v.second));
			}
			for(pii v : tmp)
			{
				if(!last[v.first] || last[v.first] < v.second)
				{
					if(last[v.first]) Insert(last[v.first],-1);
					last[v.first] = v.second;
					Insert(last[v.first],1);
				}
			}
			pre = tmp;
			for(int v : G[i]) ans[v] = Find(ask[v].r) - Find(ask[v].l-1);
		}
		for(int i = 1;i <= q;i++) printf("%d\n",ans[i]);
	}
}
