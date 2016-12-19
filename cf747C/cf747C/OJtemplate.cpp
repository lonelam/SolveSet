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
#include<functional>
using namespace std;
const int maxn = 100000 + 100;
int t[maxn], k[maxn], d[maxn];
int inq[maxn];
int ans[maxn];
int main()
{
	int n, q;
	ios::sync_with_stdio(false);
	while (cin >> n >> q)
	{
		memset(ans, 0, sizeof(ans));
		memset(inq, 0, sizeof(inq));
		priority_queue < pair<int, int>, vector < pair<int, int> >, greater<pair<int, int>> > Q;
		int lef = n;
		for (int i = 0; i < q; i++)
		{
			cin >> t[i] >> k[i] >> d[i];
		}
		
		int tm = 0;
		for (int i = 0; i < q; i++)
		{
			tm = t[i];
			while (!Q.empty())
			{
				if (Q.top().first <= tm)
				{
					inq[Q.top().second] = false;
					lef++;
					Q.pop();
				}
				else
				{
					break;
				}
			}
			if (lef >= k[i])
			{
				int pp = 1;
				
				for (int j = 0; j < k[i]; j++)
				{
					while (inq[pp])
					{
						pp++;
					}
					Q.push({ tm + d[i], pp });
					inq[pp] = true;
					lef--;
					ans[i] += pp;
				}
			}
			else
			{
				ans[i] = -1;
			}
		}
		for (int i = 0; i < q; i++)
		{
			cout << ans[i] << endl;
		}
	}
	return 0;
}