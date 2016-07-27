#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

struct edge
{
	int u, v, cost;
};
const int MAX_V = 102;
const int MAX_E = 6000;
bool comp(const edge & a, const edge & b)
{
	return a.cost < b.cost;
}
edge es[MAX_E];
int V, E;
int rk[MAX_V];
int par[MAX_V];
void init_union_find(int x)
{
	for (int i = 0; i < x; i++)
	{
		rk[i] = 1;
		par[i] = i;
	}
}
int pfind(int x)
{
	return par[x] == x ? x : par[x] = pfind(par[x]);
}
int unite(int a, int b)
{
	int pa = pfind(a);
	int pb = pfind(b);
}
int kruskal()
{
	sort(es, es + E, comp);
	init_union_find(V);
	int res = 0;
	for (int i = 0; i < E; i++)
	{
		unite()
	}
}