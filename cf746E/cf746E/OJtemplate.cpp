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
const int maxn = 400000 + 100;
set<int> aset;
int ai[maxn];
bool vis[maxn];
bool overlap[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m)
	{
		int oddnum = 0, evennum = 0;
		memset(overlap, 0, sizeof(overlap));
		memset(vis, 0, sizeof(vis));
		aset.clear();
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> ai[i];
			if (ai[i] & 1)
			{
				oddnum++;
			}
			else
			{
				evennum++;
			}
			if (ai[i] < maxn)
			{
				vis[ai[i]] = true;
			}
			if (aset.find(ai[i]) != aset.end())
			{
				overlap[i] = true;
			}
			aset.insert(ai[i]);
		}
		if (n & 1)
		{
			cout << -1 << endl;
			return 0;
		}
		int oddp = 1, evenp = 2;
		//assume there's more odds.and evenp is operated.
		if (oddnum < evennum)
		{
			swap(oddnum, evennum);
			swap(oddp, evenp);
		}
		for (int i = 0; i < n; i++)
		{
			if (overlap[i])
			{
				while (vis[evenp])
				{
					evenp += 2;
				}
				if (evenp > m)
				{
					cout << -1 << endl;
					return 0;
				}
				if ((ai[i] & 1) ^ (evenp & 1) == 1)
				{
					evennum++;
					oddnum--;
				}
				ai[i] = evenp;
				vis[evenp] = true;
				cnt++;
				if (oddnum < evennum)
				{
					swap(oddnum, evennum);
					swap(oddp, evenp);
				}
				while (vis[evenp])
				{
					evenp += 2;
				}
				if (evenp > m)
				{
					swap(oddnum, evennum);
					swap(oddp, evenp);
				}
			}
		}
		if (oddnum != evennum)
		{
			for (int i = 0; i < n && oddnum != evennum; i++)
			{
				if (!overlap[i] && (ai[i] & 1) ^ (evenp & 1) == 1)
				{
					while (vis[evenp])
					{
						evenp += 2;
					}
					if (evenp > m)
					{
						cout << -1 << endl;
						return 0;
					}
					ai[i] = evenp;
					cnt++;
					vis[evenp] = true;
					evennum++;
					oddnum--;
				}
			}
			if (oddnum != evennum)
			{
				cout << -1 << endl;
				return 0;
			}
		}
		cout << cnt << endl;
		cout << ai[0];
		for (int i = 1; i < n; i++)
		{
			cout << " " << ai[i];
		}
		cout << endl;
	}
	return 0;
}