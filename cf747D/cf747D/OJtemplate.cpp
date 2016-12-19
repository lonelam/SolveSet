#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<functional>
#include<utility>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 200000 + 50;
int t[maxn];
int main()
{
	int n, k;
	ios::sync_with_stdio(false);
	while (cin >> n >> k)
	{
		priority_queue<pii, vector<pii>, greater<pii> > Q, Q2;
		int ans = 0;
		int wintercnt = 0;
		int tcnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> t[i];
			if (t[i] < 0)
				wintercnt++;
			if (t[i] < 0 && t[i - 1] >= 0)
			{
				if (tcnt != 0)
				{
					Q.push({ tcnt, i });
					Q2.push({ tcnt, i });
				}
				ans++;
				tcnt = 0;
			}
			else if (t[i] >= 0 && ans)
			{
				tcnt++;
			}
		}
		if (wintercnt == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		if (wintercnt > k)
		{
			cout << -1 << endl;
			return 0;
		}
		k -= wintercnt;
		int tk = k;
		int ans2 = ans;
		while (!Q.empty() && tk >= Q.top().first)
		{
			tk -= Q.top().first;
			Q.pop();
			ans--;
		}
		ans *= 2;
		k -= tcnt;
		while (!Q2.empty() && k >= Q2.top().first)
		{
			k -= Q2.top().first;
			Q2.pop();
			ans2--;
		}
		if (k >= 0)
			ans2 = ans2 * 2 - 1;
		else
			ans2 = ans;
		cout << min(ans, ans2) << endl;
	}
	return 0;
	
}