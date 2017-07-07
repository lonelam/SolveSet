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
int A[maxn];
int ans[maxn];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", A + i);
	}
	for (int k = 1; k <= n; k++)
	{
		int sum = 0;
		for (int i = 0; i < k; i++)
		{
			sum += A[i];
		}
		ans[k] = sum;
		for (int i = k; i < n; i++)
		{
			sum -= A[i - k];
			sum += A[i];
			ans[k] = max(ans[k], sum);
		}
	}
	for (int i = n; i > 0; i--)
	{
		ans[i - 1] = max(ans[i], ans[i - 1]);
	}
	for (int i = 0; i < m; i++)
	{
		static int q;
		scanf("%d", &q);
		printf("%d\n", ans[q]);
	}
}