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
const int maxn = 500000 + 100;
const int chsize = 26;
typedef long long ll;
typedef long double ld;
int last, tot, ch[maxn][26], pre[maxn], len[maxn], cnt[maxn], Q[maxn], g[maxn], f[maxn];
char s[maxn];
void ins(int x, int m)
{
	int p = last, np = ++tot;
	len[np] = m, last = np, g[np]++;
	for (; !ch[p][x] && p != -1; p = pre[p]) ch[p][x] = np;
	if (p == -1) return;
	else
	{
		int q = ch[p][x];
		if (len[q] == len[p] + 1)
			pre[np] = q;
		else
		{
			len[++tot] = len[p] + 1;
			int nq = tot;
			memcpy(ch[nq], ch[q], sizeof(ch[q]));
			pre[nq] = pre[q];
			pre[q] = pre[np] = nq;
			for (; p != -1 && ch[p][x] == q; p = pre[p]) ch[p][x] = nq;
		}
	}
}

int main()
{
	pre[0] = -1;
	scanf("%s", s);
	int l = strlen(s);
	for (int i = 0; i < l; i++) ins(s[i] - 'a', i + 1);
	for (int i = 1; i <= tot; ++i) cnt[len[i]]++;
	for (int i = 1; i <= tot; ++i) cnt[i] += cnt[i - 1];
	for (int i = 1; i <= tot; ++i) Q[cnt[len[i]]--] = i;
	for (int i = tot; i >= 1; --i) f[len[Q[i]]] = max(f[len[Q[i]]], g[Q[i]]), g[pre[Q[i]]] += g[Q[i]];
	for (int i = 1; i <= l; ++i) printf("%d\n", f[i]);
	return 0;
}