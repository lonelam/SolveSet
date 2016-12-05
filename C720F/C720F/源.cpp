#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 2000;
int par[maxn];
int rk[maxn];
bool used[maxn];
void init(int n)
{
	memset(used, 0, sizeof(used));
	for (int i = 1; i <= n; i++)
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
	int n, m,a,b;
	while (cin >> n)
	{
		if (n == 0)
			return 0;
		cin >> m;
		init(n);
		while (m--)
		{
			cin >> a >> b;
			joint(a, b);
		}
		int cnt = -1;
		for (int i = 1; i <= n; i++)
		{
			int pi = pfind(i);
			if (!used[pi])
			{
				used[pi] = true;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}