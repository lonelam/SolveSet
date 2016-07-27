#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int l, r, c;
const int maxs = 31;
bool D[maxs][maxs][maxs];
struct state
{
	int x, y, z;
};
state start, exi;
bool operator==(const state & a, const state &b)
{
	return a.x == b.x && a.y == b.y && a.z == b.z;
}
int bfs()
{
	state pos;
	queue<state> cur, nex;
	cur.push(start);
	int t = 0;
	while (!cur.empty())
	{
		while (!cur.empty())
		{
			pos = cur.front();
			if (pos == exi)
			{
				return t;
			}
			cur.pop();
			if (pos.x >= 0 && pos.x < l&&pos.y >= 0 && pos.y < r&&pos.z >= 0 && pos.z < c && D[pos.x][pos.y][pos.z])
			{
				D[pos.x][pos.y][pos.z] = false;
				nex.push({ pos.x + 1,pos.y,pos.z });
				nex.push({ pos.x - 1,pos.y,pos.z });
				nex.push({ pos.x,pos.y+1,pos.z });
				nex.push({ pos.x,pos.y-1,pos.z });
				nex.push({ pos.x,pos.y,pos.z+1 });
				nex.push({ pos.x,pos.y,pos.z-1 });
			}
		}
		t++;
		swap(cur, nex);
	}
	return  -1;
}
int main()
{
	char tmp;
	while (cin >> l >> r >> c)
	{
		if (l == 0 && r == 0 && c == 0)
		{
			return 0;
		}
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					tmp = cin.get();
					if (tmp == '\n' || tmp == ' ')
					{
						k--;
						continue;
					}
					if (tmp == 'S')
					{
						start = { i,j,k };
						D[i][j][k] = true;
					}
					else if (tmp == 'E')
					{
						D[i][j][k] = true;
						exi = { i,j,k };
					}
					else if (tmp == '.')
					{
						D[i][j][k] = true;
					}
					else
					{
						D[i][j][k] = false;
					}
				}
			}
		}
		int ans = bfs();
		if (ans == -1)
		{
			cout << "Trapped!\n";
		}
		else
		{
			cout << "Escaped in "<<ans<<" minute(s).\n";
		}
	}
}