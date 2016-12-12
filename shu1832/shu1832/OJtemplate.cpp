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
typedef long long ll;
int main()
{
	ll n, r;
	while (cin >> n >> r)
	{
		ll sum = 1;
		ll up = r - 1;
		ll down = n + r - 1;
		up = min(n, r - 1);
		for (ll i = down; i >= down - up + 1; i--)
		{
			sum *= i;
		}
		for (ll i = 2; i <= up; i++)
		{
			sum /= i;
		}
		cout << sum << endl;
	}
	return 0;
}