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
int cnt[maxn];
int last[maxn];
int last2[maxn];
char cmd[10];
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		memset(cnt, 0, sizeof(cnt));
		memset(last, -1, sizeof(last));
		memset(last2, -1, sizeof(last2));
		int acc = 0, x;
		bool ans = true;
		int line;
		set<int> buy;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", cmd);
			if (cmd[0] == '?')
			{
				buy.insert(i);
			}
			if (cmd[0] == 'I')
			{
				scanf("%d", &x);
				if (!cnt[x])
				{
					cnt[x] = 1;
				}
				else if (buy.lower_bound(last2[x]) != buy.end())
				{
					buy.erase(buy.lower_bound(last2[x]));
				}
				else if (ans)
				{
					ans = false;
					line = i + 1;
				}
				last2[x] = i;
			}
			if (cmd[0] == 'O')
			{
				scanf("%d", &x);
				if (cnt[x])
				{
					cnt[x]--;
				}
				else if (buy.upper_bound(last[x]) != buy.end())
				{
					buy.erase(buy.upper_bound(last[x]));
				}
				else if (ans)
				{
					ans = false;
					line = i + 1;
				}
				last[x] = i;
			}
		}
		if (ans)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", line);
		}

	}
	
}