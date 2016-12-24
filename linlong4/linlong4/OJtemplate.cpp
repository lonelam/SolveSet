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
const int maxn = 100000 + 200;
int a[maxn];
int b[maxn];
int c[maxn];
int main()
{
	int T;
	int n;
	while (cin >> T)
	{
		while (T--)
		{
			cin >> n;
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
				c[i] = a[i];
				sum += a[i];
			}
			int bsum = 0;
			for (int i = 0; i < n; i++)
			{
				cin >> b[i];
				bsum += b[i];
			}
			if (bsum >= sum)
			{
				cout << "No\n";
			}
			else
			{
				cout << "Yes\n";
			}
			a[1] += a[0];
			a[0] = -a[0];
			bool ok = true;
			for (int i = 1; i < n; i++)
			{
				if (b[i - 1] == a[i - 1])
				{
					continue;
				}
				else if (b[i - 1] == a[i - 1] + a[i])
				{
					a[i - 1] += a[i];
					a[i + 1] += a[i];
					a[i] = -a[i];
				}
				else
				{
					ok = false;
					break;
				}
			}
			if (ok && a[n - 1] == b[n - 1])
			{
				cout << "Yes\n";
				continue;
			}
			ok = true;
			for (int i = 1; i < n; i++)
			{
				if (b[i - 1] == c[i - 1])
				{
					continue;
				}
				else if (b[i - 1] == c[i - 1] + c[i])
				{
					c[i + 1] += c[i];
					c[i - 1] += c[i];
					c[i] = -c[i];
				}
				else
				{
					ok = false;
					break;
				}
			}
			if (ok && c[n - 1] == b[n - 1])
			{
				cout << "Yes\n";
			}
			else
			{
				cout << "No\n";
			}
		}
	}
	return 0;
}