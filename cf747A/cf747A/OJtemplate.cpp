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
	int n;
	while (cin >> n)
	{
		int mi = 0;
		for (int i = 1; i * i <= n; i++)

		{
			if (n % i == 0)
			{
				mi = i;
			}
		}
		cout << mi << " " << n / mi << endl;
	}
	return 0;
}