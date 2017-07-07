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
const int maxn = 100 + 5;
typedef long long ll;
typedef long double ld;
set<int> dp[maxn];
int a[maxn];
int b[maxn];
int main()
{
	int n;
	int a, b;
	set<int> st;
	scanf("%d", &n);
	dp[0].insert(9);
	for (int i = 0; i < n; i++)
	{
		//scanf("%d%d", &a, &b);
		a = 0, b = 100;
		for (int j = a; j <= b; j++)
		{
			for (int x : dp[i])
			{
				dp[i + 1].insert(x + j * j);
			}
		}
	}
	printf("%d", dp[n].size());
}