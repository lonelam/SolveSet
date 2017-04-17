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
	char x[maxn];
	char y[maxn];
	char z[maxn];
	cin >> x >> z;
	int n = strlen(x);
	for (int i = 0; i < n; i++)
	{
		if (x[i] < z[i])
		{
			cout << -1 << endl;
			return 0;
		}
		else
		{
			y[i] = z[i];
		}
	}
	y[n] = '\0';
	cout << y << endl;
}