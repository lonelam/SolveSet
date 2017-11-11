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
string line;
int main()
{
	while (cin >> line)
	{
		int prez = 0, ans = 0;
		for (int i = line.size() - 1; i >= 0; i--)
		{
			if (line[i] == '0')
			{
				prez++;
			}
			else
			{
				ans = max(prez, ans);
			}
		}
		if (ans >= 6)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
}