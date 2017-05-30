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
int F[maxn];
int val[maxn];
int find(int x)
{
	if (F[x] == -1) return x;
	int tmp = find(F[x]);
	val[x] += val[F[x]];
	val[x] %= 3;
	return F[x] = tmp;
}
int main()
{
	int N, K;
	int t, X, Y;
	scanf("%d%d", &N, &K);
	int ans = 0;
	memset(F, -1, sizeof(F));
	memset(val, 0, sizeof(val));
	while (K--)
	{
		scanf("%d%d%d", &t, &X, &Y);
		if (X > N || Y > N)
		{
			ans++;
			continue;
		}
		int t1 = find(X);
		int t2 = find(Y);
		if (t1 == t2)
		{
			if (t == 1 && val[X] != val[Y]) ans++;
			if (t == 2 && (val[X] + 1) % 3 != val[Y]) ans++;
		}
		else
		{
			if (t == 1)
			{
				F[t2] = t1;
				val[t2] = val[X] - val[Y];
				val[t2] = (val[t2] + 3) % 3;
			}
			else
			{
				F[t2] = t1;
				val[t2] = val[X] - val[Y] + 1;
				val[t2] = (val[t2] + 3) % 3;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
