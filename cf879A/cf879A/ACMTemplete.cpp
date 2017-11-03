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
const int maxn = 500000 + 100;
typedef long long ll;
typedef long double ld;
int n;
char op[maxn][4];
int x[maxn];
// -1: no op,0: go 0, 1: go 1, 2: go rev
int st[11];
int main()
{
	scanf("%d", &n);
	memset(st, -1, sizeof(st));
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d", op[i], x + i);
		for (int j = 0; j < 10; j++)
		{
			if (op[i][0] == '|' && (x[i] >> j & 1) == 1)
			{
				st[j] = 1;
			}
			else if (op[i][0] == '&' && (x[i] >> j & 1) == 0)
			{
				st[j] = 0;
			}
			else if (op[i][0] == '^' && (x[i] >> j & 1) == 1)
			{
				if (st[j] == -1)
				{
					st[j] = 2;
				}
				else if (st[j] == 2)
				{
					st[j] = -1;
				}
				else
				{
					st[j] ^= 1;
				}
			}
		}
		
	}
	int rev = 0, and = 1023, or = 0;
	for (int j = 0; j < 10; j++)
	{
		if (st[j] == 0)
		{
			and ^= (1 << j);
		}
		else if (st[j] == 1)
		{
			or |= 1 << j;
		}
		else if (st[j] == 2)
		{
			rev |= 1 << j;
		}
	}
	printf("%d\n", 3);
	printf("| %d\n", or );
	printf("& %d\n", and);
	printf("^ %d\n", rev);
	return 0;
}