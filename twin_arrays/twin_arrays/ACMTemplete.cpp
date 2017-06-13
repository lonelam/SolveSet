#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <climits>
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
	static multiset<int> st;
	int n;
	while (scanf("%d", &n) != EOF)
	{
		st.clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
			st.insert(a[i]);
		}
		static 	int tmp;
		int ans = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			st.erase(st.find(a[i]));
			ans = min(ans, tmp + *st.begin());
			st.insert(a[i]);
		}
		printf("%d\n", ans);
	}

}