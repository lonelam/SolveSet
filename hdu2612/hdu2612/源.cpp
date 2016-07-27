#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
int yx, yy, mx, my;
char maze[200][200];
int ts[200][200];
int tm[200][200];
struct step
{
	int x, y, t;
};
int bfs()
{
	step yif = { yx,yy,0 }, cur;
	queue<step> q;
	q.push(yif);
	memset(ts, inf, sizeof(ts));
	
	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		if (cur.x>=0&&cur.x<n&&cur.y>=0&&cur.y<m&&maze[cur.x][cur.y]!='#'&&ts[cur.x][cur.y] == inf)
		{
			ts[cur.x][cur.y] = cur.t;
			q.push({ cur.x + 1,cur.y,cur.t + 1 });
			q.push({ cur.x,cur.y + 1,cur.t + 1 });
			q.push({ cur.x - 1,cur.y,cur.t + 1 });
			q.push({ cur.x ,cur.y - 1,cur.t + 1 });
		}
	}
	
	memset(tm, inf, sizeof(tm));
	q.push({ mx,my,0 });
	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		if (cur.x >= 0 && cur.x<n&&cur.y >= 0 && cur.y<m&&maze[cur.x][cur.y] != '#'&&tm[cur.x][cur.y] == inf)
		{
			tm[cur.x][cur.y] = cur.t;
			q.push({ cur.x + 1,cur.y,cur.t + 1 });
			q.push({ cur.x,cur.y + 1,cur.t + 1 });
			q.push({ cur.x - 1,cur.y,cur.t + 1 });
			q.push({ cur.x ,cur.y - 1,cur.t + 1 });
		}
	}
	int total = inf;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maze[i][j] == '@')
			{
				total = min(total, tm[i][j] + ts[i][j]);
			}
		}
	}
	cout << total *11<< endl;
	return total;
}
int main()
{
	while ( cin >> n >> m)
	{
		cin.get();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> maze[i][j];
				if (maze[i][j] == 'Y')
				{
					yx = i;
					yy = j;
				}
				if (maze[i][j] == 'M')
				{
					mx = i;
					my = j;
				}
			}
			cin.get();
		}
		bfs();
	}

}