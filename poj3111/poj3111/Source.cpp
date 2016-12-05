#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100005;
int v[maxn], w[maxn];
double g[maxn];
struct node
{
	double val;
	int no;
	bool operator < (const node & rhs) const
	{
		return val < rhs.val;
	}
}ns[maxn];
double eps = 1e-8;
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		double r = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i] >> w[i];
			r = max(r, (double)v[i] / w[i]);
		}
		double l = 0;
		while (r - l > eps)
		{
			const double mid = (l + r) / 2;
			for (int i = 0; i < n; i++)
			{
				g[i] = v[i] - mid * w[i];
			}
			sort(g, g + n);
			double hs = 0;
			for (int i = n - k; i < n; i++)
			{
				hs += g[i];
			}
			if (hs < 0)
			{
				r = mid;
			}
			else
			{
				l = mid;
			}
		}
		for (int i = 0; i < n; i++)
		{
			ns[i].no = i + 1;
			ns[i].val = v[i] - l * w[i];
		}
		sort(ns, ns + n);
		vector<int> ans;
		for (int i = n - k; i < n; i++)
		{
			ans.push_back(ns[i].no);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
		}

		
	}
}