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
const int up = 3600 * 12;
int vis[up + 1];
int h, m, s, t1, t2;
bool check()
{
	int t = t1;
	for (int i = 0; i < up; i++)
	{
		if (t == t2)
		{
			return true;
		}
		t = (t + 1) % up;
		if (vis[t])
		{
			break;
		}
	}
	if (t == t2) return true;
	t = t1;
	for (int i = 0; i < up; i++)
	{
		if (t == t2)
		{
			return true;
		}
		t = (t + up - 1) % up;
		if (vis[t])
		{
			break;
		}
	}
	if (t == t2) return true;
	return false;
}
int main()
{
	while (cin >> h >> m >> s >> t1 >> t2)
	{
		memset(vis, 0, sizeof(vis));
		
		h %= 12;
		h *= 3600;
		h = (h + m * 60 + s) % up;
		m *= 720;
		m = (m + s * 60) % up;
		s *= 720;
		/*t1 += 11;*/
		//t2 += 11;
		t1 %= 12;
		t1 *= 3600;
		t2 %= 12;
		t2 *= 3600;

		vis[h] = vis[m] = vis[s] = 1;
		/*cout << h << " " << m << " " << s << endl;
		cout << t1 << " " << t2 << endl;*/
		if (check())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}