#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<functional>
#include<utility>
#include<cstring>
#include<queue>
using namespace std;
const int n = 12, m = 12;
const int inf = 0x3f3f3f3f;
const int colormax = 6;
int color_board[n][m];
class cell
{
public:
	int x, y;
	cell(int x_, int y_) :x(x_), y(y_) {}
	cell() :x(0), y(0) {}
};

cell board[n][m];
//belongs to which node
int code[n][m];
bool vis[n][m];
class Node
{
public:
	set<cell *> s;
	set<int> to;
	Node(int x, int y)
	{

	}
};
int gs[n * m];
int fs[n * m];
vector<Node> graph;
bool hvis[n * m];
int dis[n * m];
set<int> states[n  * m];//might be more states
//returns the furthest distance.
int h(int from, int to)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>  q;
	memset(hvis, 0, sizeof(hvis));
	q.push(make_pair(0, from));
	while (!q.empty())
	{
		int cd = q.top().first;
		
		int cur = q.top().second;
		q.pop();
		
		if (!hvis[cur])
		{
			dis[cur] = cd;
			hvis[cur] = true;
			for (int ii : graph[cur].to)
			{
				if (!hvis[ii])
				{
					q.push(make_pair(cd + 1, ii));
				}
			}
		}
	}
}

int A_star(int to)
{
	queue<set<int>> closed, open;
	open.push({ 0 });
	memset(gs, inf, sizeof(gs));
	memset(fs, inf, sizeof(fs));
	gs[0] = 0;
	fs[0] = h(0, to);
	
}