#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
set<string> ss;

int main()
{

	string line;
	while (cin >> line)
	{
		ss.clear();
		while (ss.count(line) == 0)
		{
			ss.insert(line);
			line = line[line.size() - 1] + line.substr(0, line.size() - 1);
		}
		cout << ss.size() << endl;

	}
	return 0;
}