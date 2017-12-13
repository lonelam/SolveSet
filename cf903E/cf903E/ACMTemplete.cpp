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
const int maxn = 5000 + 100;
typedef long long ll;
typedef long double ld;
int k, n;
char buf[maxn];
string s[maxn];
bool vis[maxn];
int main()
{
	while (~scanf("%d%d", &k, &n))
	{
		for (int i = 0; i < k; i++)
		{
			scanf("%s", buf);
			s[i] = buf;
		}
		sort(s, s + k);
		int rk = unique(s, s + k) - s;
		bool even = false;
		if (rk == 1)
		{
			swap(s[0][0], s[0][1]);
			printf("%s\n", s[0].c_str());
			continue;
		}
		vector<int> dp;
		bool output = false;
		for (int i = 0; i < n; i++)
		{
			if (vis[s[0][i]])
			{
				even = true;
				break;
			}
			vis[s[0][i]] = true;
		}
		bool flg = false;
		for (int i = 1; i < rk; i++)
		{
			int cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (s[0][j] != s[i][j]) { dp.push_back(j); cnt++; }
			}
			if (cnt > 4)
			{
				flg = true;
			}
		}
		if (flg)
		{
			printf("-1\n");
			continue;
		}
		for (int i : dp)
		{
			if (output) break;
			for (int j = 0; j < n && !output; j++)
			{
				if (i == j) continue;
				string os = s[0];
				swap(os[i], os[j]);
				bool ans = true;
				for (int ii = 1; ii < rk; ii++)
				{
					//bool ok = false;
					vector<int> dp2;
					for (int jj = 0; jj < n; jj++)
					{
						if (s[ii][jj] != os[jj])
						{
							dp2.push_back(jj);
						}
					}
					if (dp2.size() == 0)
					{
						if (even)
						{
							continue;
						}
						else
						{
							ans = false;
							break;
						}

					}
					if (dp2.size() != 2)
					{
						ans = false;
						break;
					}
					if (s[ii][dp2[0]] == os[dp2[1]] && s[ii][dp2[1]] == os[dp2[0]])
					{
						continue;
					}
					else
					{
						ans = false;
						break;
					}
				}
				if (ans)
				{
					printf("%s\n", os.c_str());
					output = true;
					break;
				}
			}
		}
		if (!output)
		{
			printf("-1\n");
		}
	}
}