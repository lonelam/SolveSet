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
int pairr[maxn * 2];
bool vis[maxn * 2];
int meal[maxn * 2];
int pa[maxn], pb[maxn];
int main()
{
	int n;
	int u, v;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> u >> v;
			u--;
			v--;
			pa[i] = u;
			pb[i] = v;
			pairr[u] = v;
			pairr[v] = u;
		}
		memset(vis, 0, sizeof(vis));
		int N = n * 2;
		for (int i = 0; i < N; i++)
		{
			if (!vis[i])
			{
				int p = i;
				int flip = 0;
				while (!vis[p])
				{
					vis[p] = true;
					meal[p] = flip + 1;
					flip ^= 1;
					if (!vis[pairr[p]])
					{
						p = pairr[p];
					}
					else
					{
						p = p ^ 1;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << meal[pa[i]] << " " << meal[pb[i]] <<endl;
		}
	}
	return 0;
}