#include<iostream>
using namespace std;
const int maxn = 30002;
int par[maxn];
int rk[maxn];
void init(int n)
{
	for (int i = 0; i < n; i++)
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
	int n, m,k,p0,s0;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
		{
			return 0;
		}
		init(n);
		for (int i = 0; i < m; i++)
		{
			cin >> k;
			cin >> s0;
			p0 = pfind(s0);
			k--;
			while (k--)
			{
				cin >> s0;
				joint(p0, s0);
			}
		}
		p0 = pfind(0);
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
		
			if (p0 == pfind(i))
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}