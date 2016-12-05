#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	int kase = 1;
	string tl, line, wd;
	while (getline(cin, wd))
	{
		getline(cin, line);
	//	for_each(line.begin(), line.end(), [](char & a) {if (!isdigit(a)) { a = ' '; }});
		int cnt = 0;
		for (int i = 0; i + wd.length() <= line.length(); i++)
		{
			if (line.substr(i, wd.length())== wd)
			{
				cnt++;
			}
		}
		cout << "Case " << kase++ << ": " << cnt << endl;
	}
}