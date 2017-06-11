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
char grid[11][1 << 11][1 << 11];
int main()
{
	strcpy(grid[1][0], " /\\ ");
	strcpy(grid[1][1], "/__\\");
	int ht = 4;
	for (int i = 2; i <= 10; i++)
	{
		int wt = ht * 2;
		for (int j = 0; j < ht / 2; j++)
		{
			for (int k = 0; k < i; k++) grid[i][j][k] = ' ';
			memcpy(grid[i][j] + ht / 2, grid[i - 1][j], ht);
			memcpy(grid[i][j + ht/2], grid[i - 1][j], ht);
			memcpy(grid[i][j + ht/2] + ht, grid[i - 1][j], ht);
		}
		/*for (int j = 0; j < ht; j++)
		{
			for (int k = 0; k < wt + j; k++)
			{
				printf("%c", grid[i][j][k]?grid[i][j][k]:' ');
			}
			printf("\n");
		}*/
		ht *= 2;
	}
	int i;
	while (scanf("%d", &i) != EOF)
	{
		ht = 1 << i;
		int wt = ht * 2;
		for (int j = 0; j < ht; j++)
		{
			for (int k = 0; k < wt + j; k++)
			{
				printf("%c", grid[i][j][k]?grid[i][j][k]:' ');
			}
			printf("\n");
		}
		printf("\n");
	}

}