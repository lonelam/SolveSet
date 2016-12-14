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
	int n, a, b;
	string line;
	while (cin >> n >> a >> b)
	{
		cin >> line;
		if (line[a - 1] == line[b - 1])
		{
			cout << 0 << endl;
		}
		else
			cout << 1 << endl;
	}

	return 0;
}