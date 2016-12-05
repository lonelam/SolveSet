#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
const char dd[] = "durl";
const int ans = 46234;
int fac[] = { 1,1,2,6,24,120,720,5040,40320,362880 };
int ct(int s[])
{
	int sum = 0, tmp;
	for (int i = 0; i < 9; i++)
	{
		tmp = 0;
		for (int j = i + 1; j < 9; j++)
		{
			if (s[j] < s[i]) tmp++;
		}
		sum += (tmp * fac[9 - i - 1]);
	}
	return sum + 1;
}

struct Node
{
	int g[10], x, st;
} h;
struct No
{
	int fa;
	char mo;
} moo[400000];
bool vis[400000];
void bfs()
{
	queue<Node> q;
	q.push(h);
	vis[h.st] = 1;
	while (!q.empty())
	{
		h = q.front(); 
		q.pop();
		int x = h.x / 3;
		int y = h.x % 3;
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && yy >= 0 && xx < 3 && yy < 3)
			{
				Node nx = h;
				nx.x = xx * 3 + yy;
				swap(nx.g[h.x], nx.g[nx.x]);
				nx.st = ct(nx.g);
				if (!vis[nx.st])
				{
					vis[nx.st] = 1;
					moo[nx.st].mo = dd[i];
					moo[nx.st].fa = h.st;
					q.push(nx);
				}
			}
		}
	}
}
void init()
{
	for (int i = 0; i < 8; i++)
	{
		h.g[i] = i + 1;
	}
	h.g[8] = 0;
	h.x = 8;
	h.st = ans;
	moo[ans].fa = -1;
	bfs();
}
int main()
{
	char tmp;
	init();
	int s[10];
	while (cin >> tmp)
	{
		if (tmp == 'x')
		{
			s[0] = 0;

		}
		else
		{
			s[0] = tmp - '0';
		}
		for (int i = 1; i < 9; i++)
		{
			cin >> tmp;
			if (tmp == 'x')
			{
				s[i] = 0;
			}
			else
			{
				s[i] = tmp - '0';
			}
		}
		int st = ct(s);
		if (st == ans)
		{
			cout << endl;
			continue;
		}
		if (!vis[st])
		{
			cout << "unsolvable\n";
		}
		else
		{
			while (moo[st].fa != -1)
			{
				cout << moo[st].mo;
				st = moo[st].fa;
			}
			cout << endl;
		}
	}
}
