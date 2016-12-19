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
	int a[4], b[4];
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i] >> b[i];
	}
	cout << 3 << endl;
	set<pair<int, int> > st;
	for (int i = 0; i < 3; i++)
	{
		int dx = a[(i + 1) % 3] - a[(i + 2) % 3];
		int dy = b[(i + 1) % 3] - b[(i + 2) % 3];
		st.insert({ a[i] + dx, b[i] + dy });
		st.insert({ a[i] - dx, b[i] - dy });
	}
	for (pair<int, int> pp : st)
	{
		cout << pp.first << " " << pp.second << endl;
	}
	return 0;
}