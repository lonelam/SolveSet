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
const int lbound = 0, rbound = 20001;
struct seg
{
	int L, R;
	int y, type;
	seg() {}
	bool operator<(const seg & rhs)
	{
		return y < rhs.y;
	}
} ss[maxn];
int n;
struct node
{
	int sum, occ, oc;
}ns[maxn * 4];

int main()
{
	int x_0, x_1, y_0, y_1;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d", &x_0, &y_0, &x_1, &y_1);
			ss[i << 1 | 1].L = ss[i << 1].L = x_0 + 10000;
			ss[i << 1 | 1].R = ss[i << 1].R = x_1 + 10000;
			ss[i << 1].y = y_0;
			ss[i << 1].type = 1;
			ss[i << 1 | 1].y = y_1;
			ss[i << 1 | 1].type = -1;
		}
		sort(ss, ss + 2 * n);
	}
}