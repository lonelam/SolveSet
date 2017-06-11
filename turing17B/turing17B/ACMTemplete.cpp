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
int a[maxn];
int main()
{
	int n = 11, T;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			for (int i = 0; i < n; i++) scanf("%d", a + i);
			sort(a + 1, a + n);
			printf("%d %d\n", a[0], a[8]);
		}
	}
	
}