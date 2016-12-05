#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
#include<sstream>
using namespace std;
int main()
{
	int t;
	string tl;
	string line;
	while (getline(cin, tl))
	{
		stringstream st(tl);
		st >> t;
		while (t--)
		{
			getline(cin, line);
			int cnt = 0;
			int cnt_sps = 0;
			for_each(line.begin(), line.end(), [&](char & a) {a == ' '?cnt_sps++:cnt++; });
			cout << cnt << " " << cnt_sps << endl;
		}
	}
}