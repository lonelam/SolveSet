#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

string merge(string &lhs, string & rhs)
{
	string ans;
	for (int i = 0; i < lhs.size(); i++)
	{
		ans.push_back(lhs[i]);
		ans.push_back(rhs[i]);
	}
	return ans;
}

int main()
{
	string s1, s2, tar, tmp;
	int n;
	int t;
	while (cin >> t)
	{
		for (int k = 1; k <= t; k++)
		{
			cin >> n;
			cin >> s1 >> s2;
			cin >> tar;
			tmp = merge(s2, s1);
			int cnt = 0;
			int ans = -1;
			for (int i = 0; i < n * n; i++)
			{
				cnt++;
				if (tmp == tar)
				{
					ans = cnt;
					break;
				}
				s1 = tmp.substr(0, n);
				s2 = tmp.substr(n, n);
				tmp = merge(s2, s1);
			}
			cout << k << " " << ans << endl;
		}
	}
}