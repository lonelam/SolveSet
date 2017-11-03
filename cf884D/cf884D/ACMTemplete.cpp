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
const int maxn = 200000 + 100;
typedef long long ll;
typedef long double ld;
int a[maxn];
struct node
{
	ll num;
	bool operator<(const node & rhs) const
	{
		return num > rhs.num;
	}
};
int n;
int main()
{
	while (cin >> n)
	{
		
		priority_queue<node> Q;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			Q.push({ a[i] });
		}
		ll ans = 0;
		int flg = n & 1;

		while (Q.size() > 1)
		{
			node c1 = Q.top();
			Q.pop();
			node c2 = Q.top();
			Q.pop();
			if (flg)
			{
				node c3 = Q.top();
				Q.pop();
				ans += c1.num + c2.num + c3.num;
				Q.push({ c1.num + c2.num + c3.num });
			}
			else
			{
				flg = 1;
				ans += c1.num + c2.num;
				Q.push({ c1.num + c2.num });
			}
		}
		cout << ans << endl;
	}
}