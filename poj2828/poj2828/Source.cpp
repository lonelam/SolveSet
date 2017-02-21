#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int maxn = 200000 + 1000;
int sz[maxn], pre[maxn], ch[maxn][2];
int val[maxn], root, tot;

void pushup(int x)
{
	if (!x) return;
	sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
}
void rotate(int x, int d)
{
	const int y = pre[x];
	ch[y][!d] = ch[x][d];
	pre[ch[x][d]] = y;
	ch[x][d] = y;
	pre[x] = pre[y];
	if (ch[pre[y]][0] == y) ch[pre[y]][0] = x;
	else if (ch[pre[y]][1] == y) ch[pre[y]][1] = x;
	pre[y] = x;
	pushup(y);
}
bool _splay_parent(int x, int & y, int goal)
{
	return (y = pre[x]) != goal && (ch[y][0] == x || ch[y][1] == x);
}
void splay(int x, int goal = 0)
{
	if (goal == 0)
	{
		root = x;
	}
	for (int y, z; _splay_parent(x, y, goal); )
	{
		if (_splay_parent(y, z, goal))
		{
			int d = ch[z][0] == y;
			if (ch[y][d] == x) rotate(x, !d), rotate(x, d);
			else rotate(y, d), rotate(x, d);
		}
		else
		{
			rotate(x, x == ch[y][0]);
			break;
		}
	}
	pushup(x);
}

int getkth(int k, int u = root)
{
	if (k <= sz[ch[u][0]])
	{
		return getkth(k, ch[u][0] );
	}
	if (k == sz[ch[u][0]] + 1)
	{
		return u;
	}
	return getkth( k - sz[ch[u][0]] - 1, ch[u][1]);
}

int main()
{
	int N;
	ios::sync_with_stdio(false);
	while (cin >> N)
	{
		int p, v;
		for (int i = 0; i < N; i++)
		{
			cin >> p >> v;
			if (p)
			{
				int nono = getkth(p - 1);
				splay(nono);
				int no2 = getkth(p);
				splay(no2, ch[root][0])
			}
		}
	}
}
