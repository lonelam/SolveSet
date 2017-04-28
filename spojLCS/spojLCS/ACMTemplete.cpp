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
const int maxn = 400000 + 100;
const int chsize = 26;
typedef long long ll;
typedef long double ld;
int ch[maxn][chsize], f[maxn], len[maxn];

int tot, head, tail;

void add(int x)
{
	int p = tail, np = tot++;
	len[np] = len[p] + 1;
	for (; p!= -1 && !ch[p][x]; p = f[p])
	{
		ch[p][x] = np;
	}
	tail = np;
	if (p == -1)
		f[np] = head;
	else if (len[p] + 1 == len[ch[p][x]])
		f[np] = ch[p][x];
	else
	{
		int q = ch[p][x], nq = tot++;
		memcpy(ch[nq], ch[q], sizeof(ch[q]));
		len[nq] = len[p] + 1;
		f[nq] = f[q];
		f[q] = f[np] = nq;
		for (; p!= -1 && ch[p][x] == q; p = f[p])
		{
			ch[p][x] = nq;
		}
	}
}
char a[maxn], b[maxn];
int main()
{
	while (scanf("%s", a) != EOF)
	{
		scanf("%s", b);
		tot = 0;
		memset(ch, 0, sizeof(ch));
		len[tot++] = 0;
		head = tail = 0;
		f[head] = -1;
		int n = strlen(a);
		for (int i = 0; i < n; i++)
		{
			add(a[i] - 'a');
		}
		int m = strlen(b);
		int lcs = 0, ans = 0, p = head;
		for (int i = 0; i < m; i++)
		{
			int x = b[i] - 'a';
			if (ch[p][x])
			{
				p = ch[p][x];
				lcs++;
				ans = max(ans, lcs);
				continue;
			}
			while (p !=-1 && !ch[p][x]) 
				p = f[p];
			if (p == -1)
			{
				p = head;
				lcs = 0;
			}
			else
			{
				lcs = len[p] + 1;
				p = ch[p][x];
				ans = max(ans, lcs);
			}
		}
		printf("%d\n", ans);
	}
}