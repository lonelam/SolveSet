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
int n, t;
int a[maxn];
int presum[maxn];
int main()
{
	cin >> n >> t;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] = 86400 - a[i];
		t -= a[i];
		if (!ans && t <= 0)
		{
			ans = i;
		}
	}
	cout << ans << endl;

}