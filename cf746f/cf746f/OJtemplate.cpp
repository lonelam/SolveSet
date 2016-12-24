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
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<functional>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 200000 + 100;
int a[maxn];
int t[maxn];
int main()
{
	int n, w, k;
	while (cin >> n >> w >> k)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> t[i];
		}
		priority_queue<pii, vector<pii>, greater<pii>> cuted;
		priority_queue<pii, vector<pii>, less<pii>> fulplayed;
		int pre_left = k;
		int time_left = k;
		int pleasu = 0;
		int i;
		for (i = 0; i < n; i++)
		{
			pre_left = time_left;
			time_left -= t[i];
			if (w)
			{
				w--;
				time_left += t[i] / 2;
				cuted.push({ t[i], i });
				if (time_left < 0) break;
				pleasu += a[i];
				continue;
			}
			else fulplayed.push({ t[i], i });
			while (fulplayed.top().first > cuted.top().first)
			{
				pii tmp1 = fulplayed.top();
				pii tmp2 = cuted.top();
				time_left += tmp1.first / 2 - tmp2.first / 2;
				fulplayed.pop();
				cuted.pop();
				fulplayed.push(tmp2);
				cuted.push(tmp1);
			}
			if (time_left < 0) break;
			pleasu += a[i];
		}
		if (i != n && pre_left >= (t[i] + 1) / 2)
		{
			pleasu += a[i];
		}
		cout << pleasu << endl;
	}
	return 0;
}