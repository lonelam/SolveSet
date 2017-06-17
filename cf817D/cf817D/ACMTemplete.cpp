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
int leftinfo[2][maxn];
int rightinfo[2][maxn];
int n;
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		map<int, int> mem;
		for (int i = 0; i < n; i++)
		{
			auto lb = mem.lower_bound(a[i]);
			auto ub = mem.upper_bound(a[i]);
			if (lb == mem.begin()) leftinfo[0][i] = i + 1;
			else
			{
				lb--;
				leftinfo[0][i] = i - lb->second;
			}
			if (ub == mem.end())
			{
				leftinfo[1][i] = n - i;
			}
			else 
			if (mem.find(a[i]) == mem.end()) mem[a[i]] = i;
		}
	}
}