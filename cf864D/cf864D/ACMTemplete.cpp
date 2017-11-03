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
#include <functional>
#include <cassert>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
typedef long long ll;
typedef long double ld;
int n;
int cnt[maxn];
vector<int> trail[maxn];
int a[maxn];
bool vis[maxn];
int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
			trail[a[i]].push_back(i);
			cnt[a[i]]++;
		}
		set<int> rem;
		//set<int> tag;
		for (int i = 1; i <= n; i++)
		{
			if (!cnt[i])rem.insert(i);
			//if (cnt[a[i]] > 1) tag.insert(i);
		}
		printf("%d\n", rem.size());
		//set<pair<int, int> , greater<pair<int,int> > > st;
		for (int i = 1; i <= n; i++)
		{
			if (cnt[a[i]] > 1)
			{
				if (*rem.begin() < a[i])
				{
					cnt[a[i]]--;
					a[i] = *rem.begin();
					cnt[a[i]]++;
					rem.erase(rem.begin());
				}
				else if (!vis[a[i]])
				{
					vis[a[i]] = true;
				}
				else
				{
					cnt[a[i]]--;
					a[i] = *rem.begin();
					cnt[a[i]]++;
					rem.erase(rem.begin());
				}
			}
		}
		
		assert(rem.empty());
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", a[i], i == n ? '\n' : ' ');
		}
	}
}