#include<iostream>
#include<string>
#include<sstream>
#include<set>

using namespace std;
set<char> vowels = { 'a', 'e', 'i', 'o','u', 'y' };
int p[105];
int main()
{
	string line;
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
		}
		while (cin.get() != '\n');
		bool ok = true;
		for (int i = 0; i < n; i++)
		{
			getline(cin, line);
			int cnt = 0;
			stringstream ls(line);
			string wd;
			int wdcnt = 0;
			while (ls >> wd)
			{
				for (char x : wd)
				{
					if (vowels.count(x) != 0)
					{
						wdcnt++;
						break;
					}
				}
			}

			if (wdcnt > p[i])
			{
				ok = false;
			}

			for (char x : line)
			{
				if (vowels.count(x) != 0)
				{
					cnt++;
				}
			}

			if (cnt < p[i])
			{
				ok = false;
			}
		}
		if (ok)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}

	}
}