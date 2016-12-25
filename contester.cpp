#include <bits/stdc++.h>
using namespace std;

int main()
{
	string orig;
	string tar;
	while(cin >> orig >> tar)
	{
		map<char, char> proj;
		if (orig.size() != tar.size())
		{
			cout << -1 << endl;
			continue;
		}
		for (int i = 0; i < orig.length(); i++)
		{
			if (tar[i] != orig[i])
			{
				if (proj.find(tar[i]) != proj.end() || proj.find(orig[i]) != proj.end())
				{
					if (proj[tar[i]] == orig[i] && proj[orig[i]] == tar[i])
					{
						continue;
					}
					else
					{
						cout << -1 << endl;
						return 0;
					}
				}
				else
				{
					proj[tar[i]] = orig[i];
					proj[orig[i]] = tar[i];
				}
			}
		}
		cout << proj.size() / 2 << endl;
		for (char i = 'a'; i <= 'z'; i++)
		{
			if (proj.find(i) != proj.end())
			{
				cout << i << " "<< proj[i] << endl;
				proj.erase(proj[i]);
				proj.erase(i);
			}
		}
	}
}
