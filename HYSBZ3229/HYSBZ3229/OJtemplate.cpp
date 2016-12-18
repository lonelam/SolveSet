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
const int maxn = 40000;
int dp[maxn];
int s[maxn];
int sum[maxn];
int main()
{
	int N;
	while (cin >> N)
	{
		for (int i = 1; i <= N; i++)
		{
			cin >> s[i];
			sum[i] = sum[i - 1] + s[i];
		}
		int j = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int k = j; k < i; k++)
			{

			}
		}
	}

	return 0;
}