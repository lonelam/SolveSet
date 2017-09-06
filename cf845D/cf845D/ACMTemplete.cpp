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
	int n, t;
	stack<int> spdpad;
	spdpad.push(inf);
	int cnt = 0;
	int ans = 0;
	int spdnow;
	scanf("%d", &n);
	int s;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		if (t == 1)
		{
			scanf("%d", &s);
			spdnow = s;
				while (spdpad.top() < spdnow)
				{
					ans++;
					spdpad.pop();
				}
		}
		else if (t == 2)
		{
			if (cnt)
			{
				ans += cnt;
				cnt = 0;
			}
		}
		else if (t == 3)
		{
			scanf("%d", &s);
			spdpad.push(s);
				while (spdpad.top() < spdnow)
				{
					ans++;
					spdpad.pop();
				}
		}
		else if (t == 4)
		{
			cnt = 0;
		}
		else if (t == 5)
		{
			spdpad.push(inf);
		}
		else if (t == 6)
		{
			cnt++;
		}
	}
	printf("%d\n", ans);

}