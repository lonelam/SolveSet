
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;

struct edge
{
	int from, to, cap, flow, index;
	edge(int from, int to, int cap, int flow, int index) : from(from), to(to), cap(cap), flow(flow), index(index) {}
};
struct pushrelabel
{
	int n;
	vector<vector<edge> > G;
	vector<ll> excess;
	vector<int> dist, active, count;
	queue<int> Q;
	pushrelabel(int n) :n(n), G(n), excess(n), dist(n), active(n), count(2 * n) {}
	void addedge(int from, int to, int cap)
	{
		G[from].push_back(edge(from, to, cap, 0, G[to].size()));
		if (from == to) G[from].back().index++;
		G[to].push_back(edge(to, from, 0, 0, G[from].size() - 1));
	}
	void enqueue(int v)
	{
		if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); }
	}
	void push(edge & e)
	{
		int amt = int(min(excess[e.from], ll(e.cap - e.flow)));
		if (dist[e.from] <= dist[e.to] || amt == 0) return;
		e.flow += amt;
		G[e.to][e.index].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
		enqueue(e.to);
	}
	void gap(int k)
	{
		for (int v = 0; v < n; v++)
		{
			if (dist[v] < k) continue;
			count[dist[v]]--;
			dist[v] = max(dist[v], n + 1);
			count[dist[v]]++;
			enqueue(v);
		}
	}
	void relabel(int v)
	{
		count[dist[v]] --;
		dist[v] = 2 * n;
		for (int i = 0; i < G[v].size(); i++)
		{
			if (G[v][i].cap - G[v][i].flow > 0)
			{
				dist[v] = min(dist[v], dist[G[v][i].to]);
			}
		}
		count[dist[v]]++;
		enqueue(v);
	}
	void discharge(int v)
	{
		for (int i = 0; excess[v] > 0 && i < G[v].size(); i++)
		{
			push(G[v][i]);
		}
		if (excess[v] > 0)
		{
			if (count[dist[v]] == 1)
			{
				gap(dist[v]);
			}
			else
			{
				relabel(v);
			}
		}
	}
	ll getmaxflow(int s, int t)
	{
		count[0] = n - 1;
		count[n] = 1;
		dist[s] = n;
		active[s] = active[t] = true;
		for (int i = 0; i < G[s].size(); i++)
		{
			excess[s] += G[s][i].cap;
			push(G[s][i]);
		}
		while (!Q.empty())
		{
			int v = Q.front();
			Q.pop();
			active[v] = false;
			discharge(v);
		}
		ll totflow = 0;
		for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
		return totflow;
	}
};
