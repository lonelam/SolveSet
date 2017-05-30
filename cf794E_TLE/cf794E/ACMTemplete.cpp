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
const int maxn = 300000 + 100;
typedef long long ll;
typedef long double ld;
int a[maxn];
int b[maxn];
bool check(int L, int R)
{
	const int mid = (L + R) / 2;
	const int len = R - L;
	if (len == 1) return b[L];
	if (len == 2) return b[L] || b[L + 1];
	if (len & 1)
	{
		return (b[mid]&& (b[mid + 1] || b[mid - 1] ));
	}
	else
	{
		return b[mid] || b[mid - 1] ;
	}
}
int ans[maxn];
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
		}
		for (int k = 0; k < n; k++)
		{
			const int len = n - k;
			int L = 1, R = 1e9 + 1;
			while (L + 1 < R)
			{
				const int mid = L + (R - L) / 2;
				for (int i = 0; i < n; i++)
				{
					if (a[i] >= mid)
					{
						b[i] = 1;
					}
					else b[i] = 0;
				}
				bool ok = false;
				for (int i = 0; i <= k; i++)
				{
					if (check(i, i + len))
					{
						ok = true;
						break;
					}
				}
				if (ok)
				{
					L = mid;
				}
				else
				{
					R = mid;
				}
			}
			ans[k] = L;
		}
		for (int i = 0; i < n; i++)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
}