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

int main()
{
	int x1, y1, x2, y2;
	int x, y;
	while (cin >> x1 >> y1 >> x2 >> y2)
	{
		cin >> x >> y;
		int dx = abs(x2 - x1);
		int dy = abs(y2 - y1);
		if (dx % x || dy % y)
		{
			cout << "NO" << endl;
		}
		else if (((dx / x) & 1) ^ ((dy / y) & 1))
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
}