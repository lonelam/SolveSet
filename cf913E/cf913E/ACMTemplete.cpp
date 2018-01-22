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

map<int, string> table = {
	
};
int n;
int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
		{
			char line[10];
			scanf("%s", line);
			int base = 0;
			for (int j = 0; j < 8; j++)
			{
				base <<= 1;
				if (line[j] == '1')
				{
					base |= 1;
				}
			}
			printf("%s\n", table[base].c_str());
		}
	}
}