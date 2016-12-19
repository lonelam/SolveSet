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
const int maxn = 300000 + 100;
int a[maxn], b[maxn];
struct bider
{
	int id, maxbd;
	bool operator<(const bider & rhs) const
	{
		return maxbd > rhs.maxbd;
	}
} biders[maxn];
vector<int> bs[maxn];
int absents[maxn];
int main()
{
	int n;
	ios::sync_with_stdio(false);
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			biders[i].id = i;
			cin >> a[i] >> b[i];
			bs[a[i]].push_back(b[i]);
			if (b[i] > biders[a[i]].maxbd)
			{
				biders[a[i]].maxbd = b[i];
			}
		}
		sort(biders + 1, biders + n + 1);
		int q;
		cin >> q;
		int k;
		while (q--)
		{
			cin >> k;
			set<int> abst;
			for (int i = 0; i < k; i++)
			{
				cin >> absents[i];
				abst.insert(absents[i]);
			}
			int pp = 1;
			while (biders[pp].maxbd > 0)
			{
				if (abst.find(biders[pp].id) != abst.end())
				{
					pp++;
				}
				else
				{
					break;
				}
			}
			if (biders[pp].maxbd == 0)
			{
				cout << "0 0\n";
				continue;
			}
			int winner = biders[pp].id;
			cout << winner<< " ";
			pp++;
			while (abst.find(biders[pp].id) != abst.end())
			{
				pp++;
			}
			int ans = *lower_bound(bs[winner].begin(), bs[winner].end(), biders[pp].maxbd);
			cout << ans << endl;
		}
	}
	return 0;
}