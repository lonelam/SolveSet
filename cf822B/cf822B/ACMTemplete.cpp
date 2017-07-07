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
int n, m;
char s[maxn];
char t[maxn];
int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		scanf("%s%s", s, t);
		int k = inf;
		vector<int> ans;
		for (int i = 0; i + n <= m; i++)
		{
			int cnt = 0;
			vector<int> tmp;
			for (int j = 0; j < n && cnt < k; j++)
			{
				if (t[j + i] != s[j])
				{
					cnt++;
					tmp.push_back(j);
				}
			}
			if (cnt < k)
			{
				ans = tmp;
				k = cnt;
			}
		}
		printf("%d\n", k);
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d%c", ans[i]+1, (i == ans.size() - 1)?'\n':' ');
		}

	}
}