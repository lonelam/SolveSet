#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<vector>
#include<set>
#include<cctype>
#include<queue>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	string line;
	int T;
	while (getline(cin, line))
	{
		stringstream lines(line);
		lines >> T;
		while (T--)
		{
			getline(cin, line);
			if (isdigit(line[0]))
			{
				reverse(line.begin(), line.end());
				string ans;
				int j = 0;
				int pt = 0;
				for (int i = 0; i < line.length(); i++)
				{
					pt *= 10;
					pt += line[i] - '0';
					if (pt > 30)
					{
						ans.push_back((char)(pt));
						pt = 0;
					}
				}
				cout << ans << endl;
			}
			else
			{
				stringstream sout;
				for (int i = 0; i < line.length(); i++)
				{
					sout << (int)(line[i]);
				}
				string ans;
				sout >> ans;
				reverse(ans.begin(), ans.end());
				cout << ans << endl;
			}
		}
	}
	return 0;
}