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
		while (getline(cin, line))
		{
			for_each(line.begin(), line.end(), [](char & a) {if (!isdigit(a)) { a = ' '; }});
			int cnt = 0;
			stringstream ss(line);
			while (ss >> wd)
			{
				cnt++;
			}
			cout << "Case " << kase++ << ": " << cnt << endl;
		}
}