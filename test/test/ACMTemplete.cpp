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
void perm(int list[], int k, int m)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << list[i] << " ";
		}
		cout << endl;
	}
	for (int i = k; i < m; i++)
	{
		swap(list[i], list[k]);
		perm(list, k + 1, m);
		swap(list[i], list[k]);
	}
}
int main()
{
	int l[3] = { 1,2,3 };
	perm(l, 0, 3);

}