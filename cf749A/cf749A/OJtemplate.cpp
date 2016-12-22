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
		int num2 = n / 2;
		int num3 = 0;
		if (n & 1)
		{
			num3 = 1;
			num2--;
		}
		cout << num2 + num3 << endl;
		if (n == 3)
		{
			cout << 3 << endl;
			continue;
		}
		if (num2)
		{
			cout << 2;
		}
		for (int i = 1; i < num2; i++)
		{
			cout << " 2";
		}
		if (num3)
		{
			cout << " 3";
		}
		cout << endl;
	}
	return 0;
}