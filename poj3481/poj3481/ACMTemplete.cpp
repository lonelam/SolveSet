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
int n, q, root, tot;
int pre[maxn], ch[maxn][2];
int key[maxn], id[maxn];
void push_down(int r)
{
	if (!r) return;
}
void push_up(int r)
{
	if (!r) return;
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
int new_node(int k, int )
{
	
}
int get_most()
{
	int x = ch[0][1];
	while (ch[x][1] != -1)
	{
		x = ch[x][1];
	}
	return x;
}
int insert(int val)
{
	while(x = )
}
int main()
{
	
}