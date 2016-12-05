#include<vector>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn = 2000 + 20;
vector<int> G[maxn];
vector<int> rG[maxn];
vector<int> vs;
bool used[maxn];

int sccno[maxn];

void add_edge(int from,int to)
{
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++)
	{
		if(!used[G[v][i]]) dfs(G[v][i]);
	}
	vs.push_back(v);
}
void rdfs(int v, int k)
{
	sccno[v] = k;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++)
	{
		if (!used[G[v][i]]) rdfs(G[v][i], k);
	}
}
int scc(int n)
{
	memset(used, 0, sizeof(used));
	vs.clear();
	for (int v = 0; v < n; v++)
	{
		if (!used[v]) dfs(v);
	}
	int k = 0;
	memset(used, 0, sizeof(used));
	for (int i = vs.size() - 1; i >= 0; i--)
	{
		if (!used[vs[i]])
		{
			rdfs(vs[i], k++);
		}
	}
	return k;

}
int S[maxn], T[maxn], D[maxn];

void solve(int n)
{
	int V = n * 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (min(S[i] + D[i], S[j] + D[j]) > max(S[i], S[j]))
			{
				add_edge(i, n + j);
				add_edge(j, n + i);
			}
			if (min(S[i] + D[i], T[j]) > max(S[i], T[j] - D[j]))
			{
				add_edge(i, j);
				add_edge(n + j, n + i);
			}
			if (min(T[i], S[j] + D[j] ) > max(T[i] - D[i], S[j]))
			{
				add_edge(n + i, n +j);
				add_edge(j, i);
			}
			if (min(T[i], T[j]) > max(T[i] - D[i], T[j] - D[j]))
			{
				add_edge(n + i, j);
				add_edge(n + j, i);
			}
		}
	}
	scc(n);
	for (int i = 0; i < n; i ++)
	{
		if (sccno[i] == sccno[i +n])
		{
			printf("NO\n");
			return ;
		}
	}

	printf("YES\n");
	for (int i = 0; i < n; i++)
	{
		if (sccno[i] < sccno[n + i])
		{
			printf("%02d:%02d %02d:%02d\n", S[i] / 60, S[i] % 60, (S[i] + D[i]) / 60, (S[i] + D[i]) % 60);
		}
		else
		{
			printf("%02d:%02d %02d:%02d\n", (T[i] - D[i]) / 60, (T[i] - D[i]) % 60, T[i] / 60, T[i] % 60);
		}
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int hh0, mm0, hh1, mm1, tt;

		for (int i = 0; i < n; i++)
		{
			scanf("%d:%d %d:%d %d", &hh0, &mm0, &hh1, &mm1, &tt);
			S[i] = hh0 * 60 + mm0;
			T[i] = hh1 * 60 + mm1;
			D[i] = tt;
		}
		for (int i = 0; i < n; i++)
		{
			G[i*2].clear();
			rG[i*2].clear();
			G[i * 2 + 1].clear();
			rG[i * 2 + 1].clear();
		}
		solve(n);
	}
}

