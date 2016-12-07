#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
const int maxn = 100000 + 50;
int b[maxn];
int p[maxn];
int presum[maxn];
int n, m, a;
int test(int k)
{
	int rem = a;
	for (int i = k - 1, j = 0; i >= 0; i--, j++)
	{
		if (b[j] + rem < p[i])
		{
			return -1;
		}
		else if (b[j] < p[i])
		{
			rem -= p[i] - b[j];
		}
	}
	int ans = presum[k - 1] - a;
	return ans < 0 ? 0 : ans;
}
int main()
{
	while (cin >> n >> m >> a)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> p[i];
		}
		int l = 0, r = min(n, m) + 1;
		sort(b, b + n, greater<int> ());
		sort(p, p + m);
		presum[0] = p[0];
		for (int i = 1; i < m; i++)
		{
			presum[i] = presum[i - 1] + p[i];
		}
		while (l + 1 < r)
		{
			const int mid = l + (r - l) / 2;
			if (test(mid) != -1)
			{
				l = mid;
			}
			else
			{
				r = mid;
			}
		}
		int res = test(l);
		if (res == -1)
		{
			cout << 0 << " " << 0 << endl;
		}
		else cout << l <<" "<< res << endl;
	}
}