#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<unordered_map>
#include<set>
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
*           │         │
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
int cnt;
char M[5][5];
int n, m;
int mint;
int useda[5][5];
int usedb[5][5];
unordered_map<int, int> mem;
int mvx[] = { 1,-1,0,0,0 };
int mvy[] = { 0,0,1,-1 ,0};
bool isnvalid(int x, int n)
{
	return x < 0 || x >= n;
}
int select(int orig,int x,int y)
{
	return orig |= (1<<(x * 4 + y));
}
int m, n;
int rec(int S,int ax)
int main()
{
	int t,sx,sy;
	char ch;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n >> m;
			cnt = 0;
			mint = n*m;
			memset(useda, 0, sizeof(useda));
			memset(usedb, 0, sizeof(usedb));
			mem.clear();
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					while ((ch = cin.get()) == '\n');
					if (ch == 'S')
					{
						sx = i;
						sy = j;
						ch = 'O';
					}
					if (ch == 'O')
					{
						cnt++;
					}
					M[i][j] = ch;
				}
			}
			dfs(sx, sy, sx, sy, 0, cnt);
			cout << mint << endl;
		}
	}
}