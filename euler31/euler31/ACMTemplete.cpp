#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
typedef long long ll;
typedef long double ld;
int v[] = { 1,2,5,10,20,50,100,200 };
ll dp[maxn];
ll moder = 1e9 + 7;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	dp[0] = 1;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < maxn; j++)
		{
			if (j >= v[i]) dp[j] = (dp[j] + dp[j - v[i]]) % moder;
		}
	}
	int t;
	while (cin >> t)
	{
		int n;
		while (t--)
		{
			cin >> n;
			cout << dp[n] << endl;
		}
	}
}