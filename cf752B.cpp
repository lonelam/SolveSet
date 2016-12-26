#include <bits/stdc++.h>
using namespace std;
bool vis[1000];
int main()
{
	string orig;
	string tar;
	while(cin >> orig >> tar)
	{
		memset(vis, 0,sizeof(vis));
		map<char, char> slot, pos;
		if (orig.length() != tar.length())
		{
			cout << -1 << endl;
			continue;
		}
		for (int i = 0; i < orig.length(); i++)
		{
			if (slot.find(orig[i]) != slot.end() && slot[orig[i]] != tar[i])
			{
				cout << -1 << endl;
				return 0;
			}
			slot[orig[i]] = tar[i];
			if (pos.find(tar[i]) != pos.end() && pos[tar[i]] != orig[i])
			{
				cout << -1 << endl;
				return 0;
			}
			pos[tar[i]] = orig[i];
			slot[tar[i]] = orig[i];
			pos[orig[i]] = tar[i];
		}
		vector<pair<char, char> > ans;
		for (char i = 'a'; i<= 'z'; i++)
		{
			if (slot.find(i) != slot.end())
			{
				if (slot[i] != i)
				{
					ans.push_back({i, slot[i]});
				}
				slot.erase(slot[i]);
				slot.erase(i);
			}
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i ++)
		{
			cout << ans[i].first <<" "<< ans[i].second << endl;
		}
	}
}
