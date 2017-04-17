#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
typedef long long ll;
typedef long double ld;
const ld eps = 1e-9;
ld a[maxn], b[maxn];
int main()
{
	int n;
	ld p;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> p;
	ld tot_cost = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		tot_cost += a[i];
	}
	if (tot_cost <= p)
	{
		cout << -1 << endl;
		return 0;
	}
	ld L = 0, R = 1e18;
	while (abs(L-R) > eps)
	{
		ld mid = (L + R) / 2;
		ld need = 0;
		for (int i = 0; i < n; i++)
		{
			need += max(a[i] * mid - b[i], (ld)0);
		}
		if (need <= p * mid)
		{
			L = mid;
		}
		else
		{
			R = mid;
		}
	}
	//cout.setf(ios::fixed);
	//cout.precision(10);
	cout << L << endl;
	return 0;
}