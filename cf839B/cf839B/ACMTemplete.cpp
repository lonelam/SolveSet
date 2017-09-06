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
int n, k;
bool solve()
{
	int two = n * 2;
	int four = n;
	int one = 0;
	for (int i = 0; i < k; i++)
	{
		if (four >= a[i] / 4)
		{
			four -= a[i] / 4;
			a[i] %= 4;
		}
		else
		{
			a[i] -= 4 * four;
			four = 0;
		}
	}
	for (int i = 0; i < k; i++)
	{
		if (two >= a[i] / 2)
		{
			two -= a[i] / 2;
			a[i] %= 2;
		}
		else
		{
			a[i] -= 2 * two;
			two = 0;
		}
	}
	for (int i = 0; i < k; i++)
	{
		if (a[i] == 3 && four)
		{
			four--;
		}
	}
	for (int i = 0; i < k; i++)
	{
		if (a[i] == 1)
		{
			if (one) one--;
			else if (two) two--;
			else if (four) four--, two++;
			else return false;
			a[i] = 0;
		}
		else if (a[i] > 1)
		{
			if (two >= (a[i] + 1) / 2)
			{
				two -= (a[i] + 1) / 2;
			}
			else return false;
		}
	}
	return true;
}
int main()
{
	while (cin >> n >> k)
	{
		
		for (int i = 0; i < k; i++)
		{
			cin >> a[i];
		}
		if (solve())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

}