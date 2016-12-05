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
	while (getline(cin, tl))
	{
		stringstream st(tl);
		st >> t;
		while (t--)
		{
			int cnt = 0;
			getline(cin, line);
			stringstream ss(line);
			while (ss >> wd)
			{
				cnt++;
			}
			cout << "Case " << kase++ << ": " << cnt << endl;
		}
	}
}