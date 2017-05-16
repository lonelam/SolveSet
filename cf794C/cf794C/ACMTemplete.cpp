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
#include <string>
#include <cstring>
#include <bitset>
#include <deque>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 100;
typedef long long ll;
typedef long double ld;
char s[maxn], t[maxn];
char ans[maxn];
int main()
{
	while (scanf("%s%s",s, t) !=EOF)
	{
		int n = strlen(s);
		sort(s, s + n);
		sort(t, t + n);
		reverse(t, t + n);
		int sb = 0, se = (n+1) / 2 - 1, tb = 0, te = n / 2 - 1;
		int head = 0, tail = n - 1;
		for (int i = 0; i < n; i++)
		{
			if (i & 1)
			{
				if (t[tb] <= s[sb])
				{
					ans[tail--] = t[te--];
				}
				else ans[head++] = t[tb++];
			}
			else if (s[sb] >= t[tb])
			{
				ans[tail--] = s[se--];
			}
			else
			{
				ans[head++] = s[sb++];
			}
		}
		ans[n] = 0;
		printf("%s\n", ans);
	}
}