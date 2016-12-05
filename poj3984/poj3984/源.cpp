#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<utility>
using namespace std;

const int n = 5;
bool maze[n][n];
int parx[n][n];
int pary[n][n];
int sx, sy, ex, ey;
void gener()
{
	stack<pair<int, int> >  result;
	int x = 4, y = 4;
	while (x != 0 || y != 0)
	{
		result.push({ x,y });
		int tx = parx[x][y];
		y = pary[x][y];
		x = tx;
	}
	cout << "(0, 0)\n";
	while (!result.empty())
	{
		x = result.top().first;
		y = result.top().second;
		result.pop();
		cout << '(' << x << ", " << y << ')' << endl;
	}
}
void bfs()
{
	queue<pair<int, int> > q;
	q.push({ 0,0 });
	int x, y;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		if (x == 4 && y == 4)
		{
			return;
		}
		q.pop();
		if (x > 0 && !maze[x - 1][y])
		{
			q.push({ x - 1,y });
			maze[x - 1][y] = true;
			parx[x - 1][y] = x;
			pary[x - 1][y] = y;
		}
		if (y > 0 && !maze[x][y - 1])
		{
			q.push({ x,y - 1 });
			maze[x][y - 1] = true;
			parx[x ][y-1] = x;
			pary[x ][y-1] = y;
		}
		if (x + 1 < n && !maze[x + 1][y])
		{
			q.push({ x + 1,y });
			maze[x + 1][y] = true;
			parx[x + 1][y] = x;
			pary[x + 1][y] = y;
		}
		if (y + 1 < n && !maze[x][y + 1])
		{
			q.push({ x,y + 1 });
			maze[x][y + 1] = true;
			parx[x][y + 1] = x;
			pary[x][y + 1] = y;
		}
	}
}
int main()
{
	int tmp;
	while (cin >> tmp)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(i!=0||j!=0)
				cin >> tmp;
				if (tmp == 1)
				{
					maze[i][j] = true;
				}
			}
		}
		maze[0][0] = true;
		bfs();
		gener();
	}
}