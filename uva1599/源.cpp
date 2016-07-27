#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
/*
-----------Answered by Lonelam---------
*
*          ┌─┐       ┌─┐
*       ┌──┘ ┴───────┘ ┴──┐
*       │                 │
*       │       ───       │
*       │  ─┬┘       └┬─  │
*       │                 │
*       │       ─┴─       │
*       │                 │
*       └───┐         ┌───┘
*           │         │
*           │          
*           │         │
*           │         └──────────────┐
*           │                        │
*           │                        ├─┐
*           │                        ┌─┘
*           │                        │
*           └─┐  ┐  ┌───────┬──┐  ┌──┘
*             │ ─┤ ─┤       │ ─┤ ─┤
*             └──┴──┘       └──┴──┘
*                 神兽保佑
*                 代码无BUG!
*/


using namespace std;
struct path
{
	int to, color;
};
const int inf = 0x3f3f3f3f;
const int maxn = 100020;
const int maxm = 200020;
int m, n;
vector<vector<path>> rooms(maxn);
vector<int> d2n(maxn);
bool visited[maxn];
void bfs1()
{
	memset(visited, 0, sizeof(visited));
	vector<int> cur, nex;
	cur.push_back(n);
	int d = 0;
	d2n[n] = 0;
	visited[n] = true;
	while (!cur.empty())
	{
		d++;
		for (auto i : cur)
		{
			for (auto j : rooms[i])
			{
				if (!visited[j.to])
				{
					visited[j.to] = true;
					nex.push_back(j.to);
					d2n[j.to] = d; 
				}
			}
		}
		cur = nex;
		nex.clear();
	}
}

void searchfrom1()
{
	vector<int> colors;
	vector<int> curs(1,1);
	vector<int> nex;
	int cnt = d2n[1];
	cout << cnt << endl;
	while (cnt--)
	{
		int cl = inf;
		for (int cur : curs)
			for (path i : rooms[cur])
			{
				if (d2n[i.to] < d2n[cur] && i.color < cl)
				{
					cl = i.color;

				}
			}
		for (int cur : curs)
		{
			for (path i : rooms[cur])
			{
				if (d2n[i.to] < d2n[cur] && i.color == cl)
				{
					nex.push_back(i.to);
				}
			}
		}
		curs = nex;
		nex.clear();
		colors.push_back(cl);
	}
	bool started = false;
	for (int i : colors)
	{
		if (started)
		{
			cout << ' ' << i;
		}
		else
		{
			started = true;
			cout << i;
		}
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> n >> m)
	{
		int a, b, c;

		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			rooms[a].push_back({ b,c });
			rooms[b].push_back({ a,c });
		}
		
		bfs1();
		searchfrom1();
		for (int i = 1; i <= n; i++)
		{
			rooms[i].clear();
		}
	}
}
