#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 400 + 10;
int n;
int a[maxn];
int b[maxn];
ll dfs(set<int> rema, set<int> remb)
