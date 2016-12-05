#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
int main()
{
	string nline, line;
	int n;
	while (getline(cin, nline))
	{
		stringstream ss(nline);
		ss >> n;
		for (int i = 1; i <= n; i++)
		{
			getline(cin, line);
			cout << "Case " << i << ": \"" << line;
			if (line.length() & 1)
			{
				line.pop_back();
			}
			reverse(line.begin(), line.end());
			cout << line << "\"\n";
		}
	}
}