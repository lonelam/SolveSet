#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn = 100000 + 100;
int dis[maxn];
typedef pair<int, int> pii;
vector<int> G[maxn];
set<int> rmed;
struct cmp
{
	bool operator()(const pii & lhs, const pii & rhs)
	{
		if (lhs.first != rhs.first) return lhs.first < rhs.first;
		return lhs.second > rhs.second;
	}
};
priority_queue<pii,vector<pii>, cmp> diser;
int cnt;
void rmv(int u)
{
	rmed.insert(u);
	for (int i = 0; i < G[u].size(); i++)
	{
		rmv(G[u][i]);
	}
}
void add(int u)
{
	dis[++cnt] = dis[u] + 1;
	diser.push({ dis[cnt], cnt });
	G[u].push_back(cnt);
	G[cnt].clear();
}
int main()
{
	int T;
	int n;
	ios::sync_with_stdio(false);
	cin >> T;
	{
		while (T--)
		{
			cin >> n;
			cnt = 1;
			dis[1] = 0;
			G[1].clear();
			rmed.clear();
			while (!diser.empty())
			{
				diser.pop();
			}
			diser.push({ 0, 1 });
			string cmd;
			for (int i = 0; i < n; i++)
			{
				cin >> cmd;
				if (cmd[0] == '+')
				{
					int u = 0;
					for (int j = 1; j < cmd.size(); j++)
					{
						u *= 10;
						u += cmd[j] - '0';
					}
					add(u);
					while (rmed.find(diser.top().second) != rmed.end())
					{
						diser.pop();
					}
					cout << diser.top().second << endl;
				}
				else
				{
					int u = 0;
					for (int j = 1; j < cmd.size(); j++)
					{
						u *= 10;
						u += cmd[j] - '0';
					}
					rmv(u);
					while (rmed.find(diser.top().second) != rmed.end())
					{
						diser.pop();
					}
					cout << diser.top().second << endl;
				}
			}
		}
	}
	return 0;
}