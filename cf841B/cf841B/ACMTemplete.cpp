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
const int maxn = 1000000 + 100;
typedef long long ll;
typedef long double ld;
int a[maxn];
int main()
{
	int sum = 0;
	int n;
	scanf("%d", &n);
	bool odd = false;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		if (a[i] & 1) odd = true;
		sum ^= a[i] & 1;
	}
	if (sum & 1 || odd)
	{
		printf("First\n");
	}
	else
	{
		printf("Second\n");
	}
}