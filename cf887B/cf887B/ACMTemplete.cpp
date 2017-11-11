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
const int maxn = 10 + 100;
typedef long long ll;
typedef long double ld;
int n;
set<int> a[maxn];
set<int> cnt;
void dfs(int c, int pre)
{
	cnt.insert(pre);
	if (c == -1)
	{
		return;
	}
	for (int digi : a[c])
	{
		dfs(c - 1, pre * 10 + digi);
	}

}
int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				static int tmp;
				cin >> tmp;
				a[i].insert(tmp);
			}
		}
		sort(a, a + n);
		do
		{
			dfs(n - 1, 0);
		} while (next_permutation(a, a + n));
		cnt.insert(0);
		int mx = -1;
		for (int x : cnt)
		{
			if (x != mx + 1)
			{
				break;
			}
			mx = x;
		}
		cout << mx << endl;
	}
}
