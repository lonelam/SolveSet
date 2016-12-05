#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

const int maxn = 10005;
bool inq[maxn];
int dis[maxn];
int ecnt;
vector<int> G[maxn];
const int inf = 0x3f3f3f3f;
struct edge
{
    int from, to, cost;
};
edge es[maxn * maxn];
void spfa(int s)
{
    queue<int> q;
    memset(inq, 0, sizeof(inq));
    q.push(s);
    dis[s] = 0;
    inq[s] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        inq[cur] = false;
        for (int i = 0; i < G[cur].size(); i++)
        {
            edge & e = es[G[cur][i]];
            if (dis[e.to] > dis[e.from] + e.cost)
            {
                dis[e.to] = dis[e.from] + e.cost;
                if (!inq[e.to])
                {
                    q.push(e.to);
                }
            }
        }

    }
}
void init(int n)
{
    for(int i = 0; i < n; i++)
    {
        G[i].clear();
    }
    memset(dis, inf, sizeof(dis));
    ecnt = 0;
}
void addedge(int u, int v, int w)
{
    es[ecnt] = {u, v, w};
    G[u].push_back(ecnt++);
}

