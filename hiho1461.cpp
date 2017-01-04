#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int ans[65];

int gcd(int a, int b, int depth)
{
    if (b == 0) return a;
    ans[depth] = a / b;

}
