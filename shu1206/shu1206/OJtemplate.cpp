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
string dates[20];
bool cmp(const string & a, const string & b)
{
	int da = 0;
	for (int i = 6; i < 10; i++)
	{
		da *= 10;
		da += a[i] - '0';
	}
	da *= 10;
	da += a[0];
	da *= 10;
	da += a[1];
	da *= 10;
	da += a[3];
	da *= 10;
	da += a[4];
	int dr = 0;
	for (int i = 6; i < 10; i++)
	{
		dr *= 10;
		dr += b[i] - '0';
	}
	dr *= 10;
	dr += b[0];
	dr *= 10;
	dr += b[1];
	dr *= 10;
	dr += b[3];
	dr *= 10;
	dr += b[4];
	return da < dr;
}

int main()
{
	int n = 0;
	while (cin >> dates[n++] );
	if (dates[n - 1] == "") n--;
	sort(dates, dates + n, cmp);
	for (int i = 0; i < n; i++)
	{
		cout << dates[i] << endl;
	}
	return 0;
}