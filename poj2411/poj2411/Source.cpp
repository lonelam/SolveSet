#include<iostream>

using namespace std;

const int maxw = 11;
const int maxs = 1 << maxw;
int dp[2][maxs];
int n, m;
void solve()
{
	int * crt = dp[0], *next = dp[1];
	crt[0] = 1;
	int ms = 1 << m;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			for (int used = 0; used < ms; used++)
			{
				if (used >> j & 1)
				{
					next[used] = crt[used & ~(1 << j)];
				}
				else
				{
					int res = 0;
					if (j + 1 < m && !(used >> (j + 1) & 1))
					{
						res += crt[used | 1 << (j + 1)];
					}
					if (i + 1 < n)
					{

					}
				}
			}
		}
	}
}