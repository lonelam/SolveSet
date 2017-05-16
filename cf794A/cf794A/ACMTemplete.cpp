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
	int a, b, c;
	ios::sync_with_stdio(false);
	int n;
	while (cin >> a >> b >> c)
	{
		int cnt = 0;
		int tmp;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			if (tmp > b && tmp < c)
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}