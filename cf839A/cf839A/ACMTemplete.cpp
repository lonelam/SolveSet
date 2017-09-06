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
	int n, k;
	while (cin >> n >> k)
	{
		int a, cnt = 0, rem = 0;
		int ans = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			rem += a;
			if (rem > 8)
			{
				rem -= 8;
				cnt += 8;
			}
			else
			{
				cnt += rem;
				rem = 0;
			}
			if (cnt >= k)
			{
				ans = i + 1;
				break;
			}
		}
		cout << ans << endl;
		break;
	}
}