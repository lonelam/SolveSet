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
const int maxn = 1000;
int p[maxn];
int q[maxn];
int main()
{
	int n;

	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> q[i];
		}
		sort(p, p + n);
		sort(q, q + n);
		int ans = 0;
		for (int i = 0; i < n; i++)

		{
			ans += p[i] * q[i];

		}
		cout << ans << endl;
	}
	return 0;
}