#include<set>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100, maxk = 100,maxx = 100;
int n, k, x[maxn], a[maxk];
int grundy[maxx + 1];
void solve()
{
	grundy[0] = 0;
	int mx = *max_element(x, x + n);
	for (int j = 1; j <= mx; j++)
	{
		set<int> s;
		for (int i = 0; i < k; i++)
		{
			if (a[i] <= j) s.insert(grundy[j - a[i]]);
		}
		int g = 0;
		while (s.count(g) != 0)
		{
			g++;
		}
		grundy[j] = g;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans ^= grundy[x[i]];
	}
	if (x != 0)
	{


	}
	else
	{

	}
}