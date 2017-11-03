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
const int maxn = 2000000 + 100;
typedef long long ll;
typedef long double ld;
int xs[maxn];
int ys[maxn];
bool vis[maxn];
int n;
int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", xs + i);
			vis[xs[i]] = true;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", ys + i);
			vis[ys[i]] = true;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)

		{
			for (int j = 0; j < n; j++)
			{
				if (vis[xs[i] ^ ys[j]])
				{
					cnt++;
				}
			}
		}
		if (cnt & 1)
		{
			printf("Koyomi\n");
		}
		else
		{
			printf("Karen\n");
		}

	}
}