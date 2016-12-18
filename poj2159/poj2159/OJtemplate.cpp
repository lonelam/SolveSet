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

int main()
{
	string line;
	string line2;
	while (cin >> line >> line2)
	{
		map<char, int> cnt1, cnt2;
		for (int i = 0; i < line.size(); i++)
		{
			cnt1[line[i]]++;
			cnt2[line2[i]]++;
		}
		multiset<int> st1, st2;
		for (map<char, int>::iterator i = cnt1.begin(); i != cnt1.end(); i++)
		{
			st1.insert(i->second);
		}
		for (map<char, int>::iterator i = cnt2.begin(); i != cnt2.end(); i++)
		{
			st2.insert(i->second);
		}
		if (st1 == st2)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}