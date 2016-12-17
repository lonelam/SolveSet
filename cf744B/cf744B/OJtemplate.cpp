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
char grid[600][600];
int main()
{

	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> grid[i];
		}
		int l = 0, r = n - 1;
		while (l < r)
		{
			bool isemp = true;
			for (int i = 0; i < m; i++)
			{
				if (grid[l][i] == 'X')
				{
					isemp = false;
					break;
				}
			}
			if (isemp)
			{
				l++;
			}
			else
			{
				break;
			}
		}
		while (l < r)
		{
			bool isemp = true;
			for (int i = 0; i < m; i++)
			{
				if (grid[r][i] == 'X')
				{
					isemp = false;
					break;
				}
			}
			if (isemp)
			{
				r--;
			}
			else
			{
				break;
			}
		}
		int cl = 0, cr = m - 1;
		while (cl < cr)
		{
			bool isemp = true;
			for (int i = l; i <= r; i++)
			{
				if (grid[i][cl] == 'X')
				{
					isemp = false;
					break;
				}
			}
			if (isemp)
			{
				cl++;
			}
			else
			{
				break;
			}
		}
		while (cl < cr)
		{
			bool isemp = true;
			for (int i = l; i <= r; i++)
			{
				if (grid[i][cr] == 'X')
				{
					isemp = false;
					break;
				}
			}
			if (isemp)
			{
				cr--;
			}
			else
			{
				break;
			}
		}
		bool issolid = true;
		for (int i = l; i <= r; i++)
		{
			for (int j = cl; j <= cr; j++)
			{
				if (grid[i][j] == '.')
				{
					issolid = false;
				}
			}
		}
		if (issolid)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}