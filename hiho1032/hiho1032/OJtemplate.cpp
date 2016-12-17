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
const int maxs = 1e6 + 100;
char raws[maxs];
char exs[maxs * 2];
int f[maxs * 2];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	while (cin >> T)
	{
		while (T--)
		{
			int ans = 0;
			cin >> raws;
			int n;
			for (n = 0; raws[n]; n++)
			{
				exs[n << 1] = '$';
				exs[(n << 1) | 1] = raws[n];
			}
			n *= 2;
			exs[n++] = '$';
			int j = 0;
			exs[n] = '\0';
			f[0] = 1;
			for (int i = 0; i < n; i++)
			{
				int tlen = 0;
				if (i < j + f[j] / 2)
				{
					tlen = min( f[j] - (i - j) * 2, f[2 * j - i] ) / 2;
				}
				else
				{
					tlen = 0;
				}
				while (i - tlen >= 0 && i + tlen < n && exs[i - tlen] == exs[i + tlen])
				{
					tlen++;
				}
				f[i] = tlen * 2 - 1;
				if (i + f[i] / 2 > j + f[j] / 2)
				{
					j = i;
				}
					ans = max(ans, tlen - 1);
			}
			cout << ans << endl;
		}
	}
	return 0;
}