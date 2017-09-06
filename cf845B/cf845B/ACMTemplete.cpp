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
char s[100];
int main()
{
	while (cin >> s)
	{
		int sum[2] = { 0,0 };
		for (int i = 0; i < 6; i++)
		{
			sum[i / 3] += s[i] - '0';
		}
		if (sum[0] > sum[1])
		{
			swap(sum[0], sum[1]);
			for (int i = 0; i < 3; i++)
			{
				swap(s[i], s[i + 3]);
			}
		}
		int diff = sum[1] - sum[0];
		vector<int> can;
		for (int i = 0; i < 3; i++)
		{
			can.push_back('9' - s[i]);
		}
		for (int i = 3; i < 6; i++)
		{
			can.push_back(s[i] - '0');
		}
		sort(can.begin(), can.end());
		int ans = 0;
		for (int i = 5; i >= 0 && diff > 0; i--)
		{
			ans++;
			diff -= can[i];
		}
		cout << ans << endl;
	}
}