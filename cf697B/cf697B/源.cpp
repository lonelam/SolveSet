#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
void cutfront(string &s)
{
	int fst = 0;
	while (s[fst] == '0')
	{
		fst++;
	}
	s = s.substr(fst, s.length());
}
string cut(const string &s)
{
	int fst = 0;
	while (s[fst] == '0')
	{
		fst++;
		if (fst == s.length())
		{
			return "0";
		}
	}
	return s.substr(fst, s.length() - fst);
}
int main()
{
	string line, a, d, b;
	ios::sync_with_stdio(false);
	while (cin >> line)
	{
		int dp = line.find('.'), ep = line.find('e');
		a = line.substr(0, dp);
		d = line.substr(dp + 1, ep - dp - 1);
		b = line.substr(ep + 1, line.length() - ep -1);
		int expo = stoi(b);
		
		if (expo >= 0 && expo >= d.length())
		{
			string ans = a + d;
			cutfront(ans);
			cout << ans;
			for (int i = 0; i < expo - d.length(); i++)
			{
				cout << '0';
			}
		}
		else if (expo < 0 && abs(expo) >= a.length())
		{
			cout << "0.";
			for (int i = 0; i < abs(expo) - a.length(); i++)
			{
				cout << '0';
			}
			cout<<a << d;
		}
		else
		{
			string ans = a + d;
			if (ans.substr(a.length() + expo, d.length() - expo) == "0")
			{
				cout << cut(ans.substr(0, a.length() + expo));
			}
			else
			cout << cut(ans.substr(0, a.length() + expo)) << '.' << ans.substr(a.length() + expo, d.length() - expo);
		}
		cout << endl;
	}
}