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
int n;
int a[maxn];
vector<int> arrange(int sum)
{
	int digi[32];
	int p = 0;
	while (sum)
	{
		digi[p++] = sum % 10;
		sum /= 10;
	}
	vector<int> ret;
	sort(digi, digi + p);
	do
	{
		int tmp = 0;
		for (int i = 0; i < p; i++)
		{
			tmp *= 10;
			tmp += digi[i];
		}
		ret.push_back(tmp);
	} 
	while (next_permutation(digi, digi + p));
	return ret;
}
int main()
{
	while(cin >> n)
	{
		int su = 0;
		int ans = 0;
		set<int> cur, nex;
		cur.insert(0);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			for (int x : cur)
			{
				vector<int> tmp = 
				nex.insert(x + a[i]);
			}
			swap(nex, cur);
		}
		cout << ans << endl;
	}
}