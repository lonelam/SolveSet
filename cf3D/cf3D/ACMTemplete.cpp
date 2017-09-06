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
#include <functional>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
char s[maxn];
priority_queue < pii, vector<pii>, greater<pii> > q;
int main(void) {
	ll sum = 0;
	scanf("%s", s);
	int n = strlen(s);
	int level = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
		{
			level++;
		}
		else
		{
			level--;
		}
		if (s[i] == '?')
		{
			s[i] = ')';
			static ll a, b;
			scanf("%lld%lld", &a, &b);
			sum += b;
			q.push({ a - b, i });
		}
		if (level < 0)
		{
			if (q.empty())
			{
				printf("-1\n");
				return 0;
			}
			sum += q.top().first;
			s[q.top().second] = '(';
			q.pop();
			level += 2;
		}
	}
	if (level != 0)
	{
		printf("-1\n");
		return 0;
	}
	printf("%lld\n%s\n", sum, s);
}