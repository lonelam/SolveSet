#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
#include<sstream>
using namespace std;
int main()
{
	string tl, line;
	int t;
	int kase = 1;
	while (getline(cin, tl))
	{
		stringstream ts(tl);
		ts >> t;
		while (t--)
		{
			getline(cin, line);
			reverse(line.begin(), line.end());
			cout << "Case " << kase++ << ": " << line << endl;
		}
	}
}