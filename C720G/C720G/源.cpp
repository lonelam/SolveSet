#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 20002 * 2;
const int maxab = 20002;
int par[maxn];
int rk[maxn];
int cnt[maxn];
bool used[maxn];
void init()
{
	memset(used, 0, sizeof(used));
	for (int i = 0; i <= maxn; i++)
	{
		rk[i] = 1;
		par[i] = i;
	}
}
int pfind(int i)
{
	if (par[i] == i)
	{
		return i;
	}
	int ans = pfind(par[i]);
	par[i] = ans;
	return ans;
}
void joint(int a, int b)
{
	int pa = pfind(a);
	int pb = pfind(b);
	if (pa == pb)
	{
		return;
	}
	if (rk[pa] > rk[pb])
	{
		rk[pb]++;
		par[pa] = pb;
	}
	else
	{
		rk[pa]++;
		par[pb] = pa;
	}
}
int main()
{
	int t,n,a,b,kase = 1;
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d", &n);
			init();
			while (n--)
			{
				scanf("%d%d", &a, &b);
				joint(a, b + maxab);
				joint(a + maxab, b);
				used[a] = true;
				used[b] = true;
			}
			memset(cnt, 0, sizeof(cnt));
			int ans = 0;
			for (int i = 0; i < maxab; i++)
			{
				if (used[i])
				{
					int pi = pfind(i);
					cnt[pi]++;
				}
			}
			memset(used, 0, sizeof(used));
			for (int i = 0; i < maxn; i++)
			{
				if (cnt[i] >= 1 && !used[i])
				{
					used[i] = true;
					used[i + maxab] = true;
					ans += max(cnt[i], cnt[pfind(i + maxab)]);
				}
			}
			printf("Case %d: %d\n", kase++,ans);
		}
	}
}