#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;
const int INF = 0x3f3f3f3f;
const int msz = 1e5;
const int mod = 1e9+7;
const double eps = 1e-8;

struct Edge
{
	int v,w,next;
};

Edge eg[233333];
int head[50050];
bool vis[50050];
int dis[50050];
int tp,st,en;

void Add(int u,int v,int w)
{
	eg[tp].v = v;
	eg[tp].w = w;
	eg[tp].next = head[u];
	head[u] = tp++;
}

int SPFA()
{
	memset(vis,0,sizeof(vis));
	memset(dis,-INF,sizeof(dis));
	queue <int> q;
	dis[st] = 0;
	vis[st] = 1;
	int u,v,w;

	q.push(st);

	while(!q.empty())
	{
		u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = head[u]; i != -1; i = eg[i].next)
		{
			v = eg[i].v;
			w = eg[i].w;
			if(dis[v] < dis[u]+w)
			{
				dis[v] = dis[u]+w;
				if(!vis[v])
				{
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
	return dis[en];
}

int main(int argc,char **argv)
{
	int n;
	int u,v,w;

	while(~scanf("%d",&n))
	{
		tp = 0;
		memset(head,-1,sizeof(head));

		en = 0,st = INF;

		while(n--)
		{
			scanf("%d%d%d",&u,&v,&w);
			Add(u,v+1,w);
			en = max(en,v+1);
			st = min(st,u);
		}

		for(int i = st; i < en; ++i)
		{
			Add(i,i+1,0);
			Add(i+1,i,-1);
		}
		printf("%d\n",SPFA());
	}
	return 0;
}
