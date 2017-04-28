
//这道题要用到LCT可是不会做，所以只好不会了


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
const int maxn = 1200000 + 100;
const int chsize = 26;
typedef long long ll;
typedef long double ld;
int len[maxn], ch[maxn][chsize], sz[maxn], f[maxn];
int head, tail, tot;

void add(int x)
{
	int p = tail, np = tot++;
	len[np] = len[p] + 1;
	//sz[np] = 1;
	for (; p != -1 && ch[p][x] == -1; p = f[p])
	{
		ch[p][x] = np;
	}
	tail = np;
	if (p == -1)
	{
		f[np] = head;
		//sz[head] += sz[np];
	}
	else if (len[p] + 1 == len[ch[p][x]])
	{
		f[np] = ch[p][x];
		//sz[ch[p][x]] += sz[np];
	}
	else
	{
		int q = ch[p][q], nq = tot++;
		memcpy(ch[nq], ch[q], sizeof(ch[q]));
		len[nq] = len[p] + 1;
		f[nq] = f[q];
		f[q] = f[np] = nq;
		for (; p != -1 && ch[p][x] == q; p = f[p])
		{
			ch[p][x] = nq;
		}
	}
}
int main()
{
	
}