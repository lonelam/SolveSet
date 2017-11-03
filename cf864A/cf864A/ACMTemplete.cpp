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

int a[maxn];
map<int, int> cnt, cnt2;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)

	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	bool ok = false;
	if (cnt.size() == 2)
	for (auto p : cnt)
	{
		cnt2[p.second]++;
		if (cnt2[p.second] > 1) ok = true;
	}
	if (ok)
	{

		cout << "YES\n";
		cout << cnt.begin()->first << " " << (++cnt.begin())->first << endl;
	}
	else cout << "NO\n";


}