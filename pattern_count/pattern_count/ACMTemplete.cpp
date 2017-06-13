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
char s[maxn];
int main()
{
	int q;

	while (cin >> q)
	{
		while (q--)
		{
			cin >> s;
			int p = 0;
			int ans = 0;
			int n = strlen(s);
			while (p < n)
			{
				if (s[p] == '0')
				{
					int l = p - 1;
					while (s[p] == '0')
					{
						p++;
					}
					if (l >= 0 && p < n && s[l] == '1' && s[p] == '1')
					{
						ans++;
					}
				}
				p++;
			}
			cout << ans << endl;
		}
	}
}