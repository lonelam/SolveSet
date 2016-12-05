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
			for_each(line.begin(), line.end(), [](char & a) {a = toupper(a); });
			cout << line << endl;
		}
	}
}