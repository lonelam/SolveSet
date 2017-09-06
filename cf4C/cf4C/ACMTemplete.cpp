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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<string, int> cnt;
	string name;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> name;
		if (cnt[name])
		{
			cout << name << cnt[name] << endl;
		}
		else
		{
			cout << "OK" << endl;
		}
		cnt[name]++;
	}
}