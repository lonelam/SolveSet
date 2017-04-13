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
int pre[maxn], ch[maxn][2];
bool rev[maxn];
int n, q;
int key[maxn], lazy[maxn], sum[maxn], mx[maxn];
void debug()
{
	for (int i = 0; i <= n; i++)
	{
		cout << "node #" << i << " chs:" << ch[i][0] << " " << ch[i][1] << " , pre" << pre[i] << ", key/ mx" << key[i] << " / " << mx[i] << endl;
	}
}

void push_down(int r)
{
	if (!r) return;
	if (rev[r])
	{
		swap(ch[r][0], ch[r][1]);
		if (ch[r][0]) rev[ch[r][0]] ^= 1;
		if (ch[r][1]) rev[ch[r][1]] ^= 1;
		rev[r] = 0;
	}
	if (lazy[r])
	{
		if (ch[r][0])
		{
			lazy[ch[r][0]] += lazy[r];
			key[ch[r][0]] += lazy[r];
			//        sum[ch[r][0]] += lazy[r];
			mx[ch[r][0]] += lazy[r];
		}
		if (ch[r][1])
		{
			lazy[ch[r][1]] += lazy[r];
			key[ch[r][1]] += lazy[r];
			//            sum[ch[r][1]] += lazy[r];
			mx[ch[r][1]] += lazy[r];
		}
		lazy[r] = 0;
	}
}
void push_up(int x)
{
	if (!x) return;
	mx[x] = max({ mx[ch[x][0]], mx[ch[x][1]], key[x] });
}

void rotate(int x, int d)
{
	const int y = pre[x];
	ch[y][!d] = ch[x][d];
	if (ch[x][d]) pre[ch[x][d]] = y;
	pre[x] = pre[y];
	if (ch[pre[y]][0] == y) ch[pre[x]][0] = x;
	else if (ch[pre[y]][1] == y) ch[pre[x]][1] = x;
	pre[y] = x;
	ch[x][d] = y;
	push_up(y);
}

bool _splay_parent(int x, int & y, int goal)
{
	return (y = pre[x]) != goal && (ch[y][0] == x || ch[y][1] == x);
}

void splay(int x, int goal = 0)
{
	push_down(x);
	for (int y, z; _splay_parent(x, y, goal);)
	{
		if (_splay_parent(y, z, goal))
		{
			push_down(z);
			push_down(y);
			push_down(x);
			int d = y == ch[z][0];
			if (x == ch[y][d]) rotate(x, d ^ 1), rotate(x, d);
			else rotate(y, d), rotate(x, d);
		}
		else
		{
			push_down(y), push_down(x);
			rotate(x, x == ch[y][0]);
			break;
		}
	}
	push_up(x);
}

int access(int u)
{
	int v = 0;
	for (; u; u = pre[u])
	{
		splay(u);
		ch[u][1] = v;
		push_up(v = u);
	}
	return v;
}
void makeroot(int x)
{
	rev[access(x)] ^= 1;
	splay(x);
}
void link(int x, int y)
{
	makeroot(x);
	pre[x] = y;
}
void cut(int x, int y)
{
	makeroot(x);
	access(y);
	splay(y);
	pre[ch[y][0]] = 0;
	ch[y][0] = 0;
	push_up(y);
}

vector<int> G[maxn];
void dfs(int u, int p)
{
	for (int i = 0; i < G[u].size(); i++)
	{
		if (G[u][i] != p) pre[G[u][i]] = u, dfs(G[u][i], u);
	}
}
void init()
{
	for (int i = 0; i <= n; i++)
	{
		G[i].clear();
	}
	memset(pre, 0, sizeof(pre));
	memset(lazy, 0, sizeof(lazy));
	memset(ch, 0, sizeof(ch));
}
int getroot(int x)
{
	for (x = access(x); push_down(x), ch[x][0]; x = ch[x][0]);
	return x;
}

void increase(int w, int x, int y)
{
	makeroot(x);
	access(y);
	splay(x);
	lazy[x] += w;
	key[x] += w;
}

int getfa(int x)
{
	int p = ch[x][0];
	while (ch[p][1])
	{
		p = ch[p][1];
	}
	return p;
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		init();
		int u, v;
		
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!pre[i]) dfs(i, 0);
		}

		key[0] = 0;
		mx[0] = INT_MIN;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", key + i);
			mx[i] = key[i];
		}
		//debug();
		scanf("%d", &q);
		while (q--)
		{
			int cmd, a, b, c, d;
			scanf("%d", &cmd);
			if (cmd == 1)
			{
				scanf("%d%d", &a, &b);
				if (getroot(a) == getroot(b))
				{
					printf("-1\n");
				}
				else
				{
					link(a, b);
				}
			}
			else if (cmd == 2)
			{
				scanf("%d%d", &a, &b);
				if (a != b && getroot(a) == getroot(b))
				{
					makeroot(a);
					access(b);
					splay(b);
					int fab = getfa(b);
					cut(fab, b);
				}
				else
				{
					printf("-1\n");
				}
			}
			else if (cmd == 3)
			{
				scanf("%d%d%d", &a, &b, &c);
				if (getroot(b) == getroot(c)) increase(a, b, c);
				else printf("-1\n");
			}
			else if (cmd == 4)
			{
				scanf("%d%d", &a, &b);
				if (getroot(a) != getroot(b))
				{
					printf("-1\n");
				}
				else
				{
					makeroot(a);
					access(b);
					splay(a);
					printf("%d\n", mx[a]);
				}
			}
			else
			{
				printf("-1\n");
			}
			debug();
		}
		printf("\n");
	}
}