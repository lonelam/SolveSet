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

	ll n, m;
	while (cin >> m >> n)
	{
		ll ans = 1;
		for (ll i = n - 1; i > 1; i--)
		{
			ans *= i;
		}
		for (ll i = n - m + 1; i <= n; i++)
		{
			ans *= i;
		}
		cout << ans << endl;
	}

	return 0;
}