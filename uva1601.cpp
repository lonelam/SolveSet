#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
const int maxw = 16;
const int possiever = 0xff;
const int ysiever = 0xf;
bool grid[maxw][maxw];
typedef int state;
typedef int pos;
int w,h;
void gener(int i, queue<state> & q, state path, vector<vector<int>>& o_robots,int n)
{
	if(i == n)
	{
		q.push(path);
		return;
	}
	for(int dy = -1; dy <= 1; dy++ )
	{
		for(int dx = -1; dx <= 1; dx++ )
		{
			const int curx = o_robots[i][0] + dx, cury = o_robots[i][1] + dy;
			if(curx >= 0 && cury >= 0 && curx < h && cury < w)
			{
				bool nswp = true;
				for(int k = 0; k < i; k++)
				{
					int kpos = path >> k * 8 & possiever;
					int kx = kpos >> 4, ky = kpos & ysiever;
					if(curx == o_robots[k][0] && cury == o_robots[k][1] && kx == o_robots[i][0] &&ky == o_robots[i][1] )
					{
						nswp = false;
					}
				}
				if(nswp)
				{
					int curi = (curx << 4) + cury;
					gener(i, q, path + (curi << i * 8), o_robots, n);
				}
			}
		}
	}
}
int bfs(vector<pos> & orig, vector<pos> & target)
{
	const int n = orig.size();
	state cur = 0, tar = 0;
	for(int i = 0; i< n;i++)
	{
		cur += orig[i] << (i * 8);
		tar += target[i] << (i * 8);
	}
	queue<state> q, nex;
	unordered_set<state> vis;
	q.push(cur);
	int step = 0;
	while(!q.empty())
	{
		while(!q.empty())
		{
			cur = q.front();
			q.pop();
			if(vis.find(cur) != vis.end())
			{
				continue;
			}
			vis.insert(cur);
			if(cur == tar)
			{
				return step;
			}
			
			vector<vector<int> > robots(n, vector<int> (2));
			bool obstacle = false;
			for(int i = 0; i < n; i++)
			{
				int tmp = cur >> i * 8 & possiever;
				robots[i][0] = tmp >> 4;
				robots[i][1] = tmp & ysiever;
				if(!grid[robots[i][0]][robots[i][1]])
				{
					obstacle = true;
					break;
				}
			}
			if(obstacle)
			{
				continue;
			}
			gener(0, nex, 0,robots, n);
		}
		step++;
		swap(q, nex);
	}
	return -1;
}
int main()
{
	int n;
	char line[20];
	while(scanf("%d%d%d",&w,&h, &n)!=EOF)
	{
		if(w == 0 && h == 0 && n== 0)
		{
			return 0;
		}
		vector<pos> orig(n);
		vector<pos> tar(n);
		getchar();
		for(int i = 0; i< h; i++)
		{
			gets(line);
			for(int j = 0; j < w; j++)
			{
				if(line[j] == '#')
				{
					grid[i][j] = false;
				}
				else
				{
					switch(line[j])
					{
						case 'a':
							orig[0] = (i << 4) + j;
							break;
						case 'A':
							tar[0] = (i << 4) + j;
							break;
						case 'b':
							orig[1] = (i << 4) + j;
							break;
						case 'B':
							tar[1] = (i << 4) + j;
							break;
						case 'c':
							orig[2] = (i << 4) + j;
							break;
						case 'C':
							tar[2] = (i << 4) + j;
							break;
					}
					grid[i][j] = true;
				}
			}
			
		}
		printf("%d\n", bfs(orig, tar));
	}
}
