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
	int a, b;
	while (cin >> a >> b)
	{
		if (a > b) swap(a, b);
		ll ans = 1;
		for (int i = 2; i <= a; i++)
		{
			ans *= i;
		}
		cout << ans << endl;
	}
}