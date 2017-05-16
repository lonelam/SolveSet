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
const int maxn = 1000 + 100;
typedef long long ll;
typedef long double ld;
ld dh[maxn];
void init()
{
	dh[0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		dh[i] = sqrt(dh[i - 1] * dh[i - 1] + 1);
	}
}
int main()
{
	init();
	int n;
	ld h;
	ios::sync_with_stdio(false);
	while (cin >> n >> h)
	{
		ld acc = dh[n - 1];
		ld m = h / acc;
		cout.setf(ios::fixed);
		cout.precision(20);
		for (int i = 0; i < n - 1; i++)
		{
			cout << dh[i] *m << " ";
		}
	}
}