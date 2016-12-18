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
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		int cnt = min({ a , b / 2, c / 4 });
		cout << cnt * 7 << endl;
	}

	return 0;
}