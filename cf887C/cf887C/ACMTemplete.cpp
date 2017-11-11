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
int a[25];
int back[25];
int trans[25];
bool check()
{
	for (int i = 1; i <= 24; i+=4)
	{
		for (int j = 1; j < 4; j++)
		{
			if (trans[j + i] != trans[i]) return false;
		}
	}
	return true;
}
vector<pair<int, int> > go[6] = {
	{ { 1, 2 },{ 2, 4 },{ 4, 3 },{ 3, 1 },{ 6, 14 },{ 5, 13 },{ 13, 21 },{ 14, 22 },{ 22, 18 },{ 21, 17 },{ 18, 6 },{ 17, 5 } },
	{{5, 6}, {6, 8}, {8, 7}, {7, 5}, {4, 19}, {3, 17}, {19, 9}, {17, 10}, {9, 14}, {10, 16}, {14, 4}, {16, 3}},
{{17, 18}, {18, 20}, {20, 19}, {19, 17}, {6, 2}, {2, 23}, {23, 10}, {10, 6}, {8, 4}, {4, 21}, {21, 12}, {12, 8}},
{{13, 14}, {14, 16}, {16, 15}, {15, 13}, {1, 5}, {5, 9}, {9, 24}, {24, 1}, {3, 7}, {7, 11}, {11, 22}, {22, 3}},
{{9, 10}, {10, 12}, {12, 11}, {11, 9}, {7, 19}, {8, 20}, {20, 24}, {19, 23}, {23, 15}, {24, 16}, {16, 8}, {15, 7}},
{{21, 22}, {22, 24}, {24, 23}, {23, 21}, {20, 2}, {18, 1}, {1, 15}, {2, 13}, {13, 11}, {15, 12}, {12, 18}, {11, 20}}
};
int main()
{
	while (cin >> a[1])
	{
		back[1] = a[1];
		for (int i = 2; i <= 24; i++)
		{
			cin >> a[i];
			back[i] = a[i];
		}
		// check mat
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				memcpy(trans, a, sizeof(a));
				for (pair<int, int> p : go[i])
				{
					trans[p.second] = a[p.first];
				}
				memcpy(a, trans, sizeof(a));
			}
			for (int j = 1; j <= 24; j++)
			{
				if (a[j] != back[j])
				{
					break;
				}
			}
		}
		
		bool ans = false;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 1; j <= 24; j++)
			{
				trans[j] = a[j];
			}
			for (pair<int, int> p : go[i])

			{
				trans[p.second] = a[p.first];
			}
			if (check())
			{
				ans = true;
				break;
			}
			for (int j = 1; j <= 24; j++)
			{
				trans[j] = a[j];
			}
			for (pair<int, int> p : go[i])
			{
				trans[p.first] = a[p.second];
			}
			if (check())
			{
				ans = true;
				break;
			}
		}
		if (ans)
		{
			cout <<
				"YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}