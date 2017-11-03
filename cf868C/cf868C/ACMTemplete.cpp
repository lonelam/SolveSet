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
const int maxn = 1 << 4;
const int maxs = 1 << 20;
typedef long long ll;
typedef long double ld;
int n, k;
int cnt[maxn];
int vis[maxs];
int main()
{
	while (cin >> n >> k)
	{
		int up = 1 << k;
		for (int i = 0; i < n; i++)
		{
			int tmp, tar = 0;
			for (int j = 0; j < k; j++)
			{
				cin >> tmp;
				tar <<= 1;
				tar |= tmp;
			}
			cnt[tar]++;
		} 
		bool ok = (bool)cnt[0];

		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				if (cnt[i] && cnt[j] && ((i & j )== 0))
				{
					ok = true;
				}
			}
		}
		if (ok)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}
