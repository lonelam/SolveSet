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
	string line;
	cin >> line;
	int cnt = 0;
	for (int i = 1; i < line.size(); i++)
	{
		if (line[i] == 'K' && line[i - 1] == 'V')
		{
			line[i] = line[i - 1] = '*';
			cnt++;
		}
	}
	for (int i = 1; i < line.size(); i++)
	{
		if (line[i] == 'K' && line[i - 1] != '*' || line[i] != '*' && line[i - 1] == 'V')
		{
			cnt++;
			break;
		}
	}
	cout << cnt << endl;
}