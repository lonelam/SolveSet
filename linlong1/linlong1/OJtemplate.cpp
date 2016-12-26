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

int main()
{

	int T;
	int n, a;
	ios::sync_with_stdio(false);
	while (cin >> T)
	{
		while (T--)
		{
			cin >> n;
			map<int, int> cnt;
			for (int i = 0; i < n; i++)
			{
				cin >> a;
				cnt[a]++;
			}
			vector<int> ans;
			for (pair<int, int> p : cnt)
			{
				if (p.second >= 2)
				{
					ans.push_back(p.first);
				}
			}
			if (ans.empty())
			{
				cout << "none\n";
			}
			else
			{
				cout << ans[0];
				for (int i = 1; i < ans.size(); i++)
				{
					cout << " " << ans[i];
				}
				cout << endl;
			}
		}
	}
	return 0;
}