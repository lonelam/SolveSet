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

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}


int main()
{
	ll n;
	while (cin >> n)
	{
		if (n == 1)
			cout << -1 << endl;
		else

			cout << n << " " << n + 1 << " " << n * (n + 1) << endl;
	}
	return 0;
}