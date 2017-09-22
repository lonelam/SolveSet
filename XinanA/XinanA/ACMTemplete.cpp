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
#include <numeric>
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
int W[maxn];
int D[maxn];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, w, d;
		scanf("%d%d%d", &n, &w, &d);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", W + i);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", D + i);
		}
		int totw = accumulate(W, W + n, 0);
		int totC = accumulate(D, D + n, 0);
		if (w >= totw && d >= totC)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}

	}
}