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
#include <cassert>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef long double ld;
const int maxn = 400000 + 10;
char raw[maxn];
char s[maxn];
int N;
void trans()
{
	N = strlen(raw);
	s[0] = raw[0];
	int cnt = 0;
	//if (s[0] != '0') cnt += s[0] - '0';
	for (int i = 0; i < N; i++)
	{
		s[i << 1] = raw[i];
		s[i << 1 | 1] = '+';
		if (raw[i] != '0') cnt+=raw[i] - '0';
	}
	s[(N << 1) - 1] = '\0';
	printf("%s\n", s);
	strcpy(raw, to_string(cnt).c_str());
}
int main()
{
	scanf("%d%s", &N, raw);
	for (int i = 0; i < 3; i++) trans();
	assert(strlen(raw) == 1);
//	system("pause");
}