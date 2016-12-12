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
int rec(int last)
{
	if (last == 2)
	{
		return 1;
	}
	if (last < 2)
	{
		return 0;
	}
	return last / 3 + rec(last / 3 + last % 3);
}
int main()
{

	int n;
	while (cin >> n && n)
	{
		cout << rec(n) << endl;
	}
	return 0;
}