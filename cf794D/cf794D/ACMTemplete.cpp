#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 100;
typedef long long ll;
typedef long double ld;
int cl[maxn];
vector<int> G[maxn];
int tmp[maxn];
vector<int> clique[maxn];
int tot;
bool get(int cur, int p)
{
	set<int> conn;
	set<int> notin;
	for (int i = 0; i < G[cur].size(); i++)
	{
		conn.insert(G[cur][i]);
	}
	for (int i = 0; i < G[cur].size(); i++)
	{
		int v = G[cur][i];
		int cnt = 0;
		for (int j = 0; j < G[v].size(); j++)
		{
			if (conn.find(G[v][j]) == conn.end())
			{
				notin.insert(v);
				break;
			}
		}
	}
	if (notin.size() > 2)
	{
		return false;
	}
	for (int i = 0; i < G[cur].size(); i++)
	{
		int v = G[cur][i];
		for (int i = 0; i < G[v].size(); i++)
		{
			if (notin.find(G[v][i]) != notin.end())
			{
				notin.insert(v);
				break;
			}
		}
		if (notin.find(v) != notin.end())
		{
			clique[tot].push_back(v);
		}
	}
}
int main()
{
	
}