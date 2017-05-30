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
int num[4];
int main()
{
	for (int i = 0; i < 4; i++)
	{
		cin >> num[i];
	}
	int ans = 0;
	int kk, d;
	cin >> kk >> d;
	d--; kk--;
	for (int i = 1; i <= 6; i++)
	{
		for (int j = i; j <= 6; j++)
		{
			int starter = (i + j - 1) % 4;
			pair<int, int> p = { starter, 0};
			int step = min(i , j);
			while (step--)
			{
				p.second++;
				if (p.second == num[p.first])
				{
					p.first = (p.first + 3) % 4;
					p.second = 0;
				}
			}
			pair<int, int> init = p;
			bool finish = false;
			for (int k = 0; k < 3 && !finish; k++)
			{
				for (int t = 0; t < 4 && !finish; t++)
				{
					bool flg = false;
					if (t == 0 && p.first == kk && p.second == d)
					{
						flg = true;
					}
					for (int f = 0; f < 2 && !finish; f++)
					{
						p.second++;
						if (p.second == num[p.first])
						{
							p.first = (p.first + 3) % 4;
							p.second = 0;
						}
						if (f == 1 && flg)
						{
							ans++;
							//cout << i << " " << j << endl;
							finish = true;
						}
						if (p == init)
						{
							finish = true;
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
}