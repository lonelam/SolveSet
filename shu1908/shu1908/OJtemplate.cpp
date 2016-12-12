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
ll dp[100];
int main()
{
	int n;
	dp[0] = dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i < 25; i++)
	{
		dp[i] = (dp[i - 1] +dp[i -2])* (ll)(i - 1) ;
	}
	while (cin >> n)
	{
		cout << dp[n] << endl;
	}

	return 0;
}