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
const int maxn = 500000 + 100;
typedef long long ll;
typedef long double ld;
int n, k;
int a[maxn];
int b[maxn];
//vector<int> disc;
int main()
{
	//disc.reserve(maxn);
	while (~scanf("%d%d", &n, &k))
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
			b[i] = a[i];
			//disc.push_back(a[i]);
		}
		a[n] = 0;
		/*sort(disc.begin(), disc.end());
		disc.erase(unique(disc.begin(), disc.end()), disc.end());*/
		multiset<int> cnt;
		for (int i = n; i > n - k; i--)
		{
			cnt.insert(a[i]);
		}
		int pre = n, tar = -1, down = -1;
		bool swapped = false, ans = true;
		for (int i = n - k; i >= 0; i--)
		{
			if (tar != -1)
			{
				if (a[i] > a[tar] && a[i] > down && a[tar] < *cnt.begin())
				{
					pre = i;
					ans = true;
				}
			}
			if (*cnt.begin() >= a[i])
			{
				if (tar != -1)
				{
					if (swapped || pre == n)
					{
						ans = false;
						break;
					}
					else
					{
						swap(a[pre], a[tar]);
						swapped = true;
						if (pre <= i + k && tar > i + k)
						{
							cnt.erase(cnt.find(a[tar]));
							cnt.insert(a[pre]);
						}
						ans = true;
						if (*cnt.begin() >= a[i])
						{
							ans = false;
							break;
						}
					}
				}
				else
				{
					tar = i;
					down = *cnt.begin();
					ans = false;
				}
			}
			cnt.erase(cnt.find(a[i + k]));
			cnt.insert(a[i]);
		}
		
		if (ans)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}