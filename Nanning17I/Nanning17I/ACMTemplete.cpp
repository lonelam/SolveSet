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
const int maxn = 20;
typedef long long ll;
typedef long double ld;
const ld shifterx = 5.0L * sqrtl(3.0L) * 0.5L, shiftery = 7.5L;
ld px[maxn][maxn], py[maxn][maxn];
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return sqrtl((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
int main()
{
	int x, y;
	for (int i = -9; i < 11; i++)
	{
		for (int j = -9; j < 11; j++)
		{
			px[i + 9][j + 9] = (i*2+j) * shifterx;
			py[i + 9][j + 9] = j * shiftery;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		scanf("%d%d", &x, &y);
		int dx = 0, dy = 0;
		ld mis = dist(x, y, px[dx][dy], py[dx][dy]);
		for (int j = 0; j < 20; j++)
		{
			for (int k = 0; k < 20; k++)
			{
				ld tmp = dist(x, y, px[j][k], py[j][k]);
				if (tmp < mis)
				{
					mis = tmp;
					dx = j;
					dy = k;
				}
			}
		}
		//cout << mis << endl;
		printf("[%d,%d]", dx-9, dy-9);
		if (i != 9) printf(", ");
		else printf("\n");
	}
}