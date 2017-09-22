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
long long hgcd(long long a, long long b) {
	long long ret = 0;
	while (a > 0 && b > 0) {
		a -= b;
		swap(a, b);
		ret++;
	}
	return ret;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long n;
		scanf("%lld", &n);

	}
}