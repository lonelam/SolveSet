#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50010;
const int maxm = 50010;
struct Query
{
    int L, R, id;
} node[maxm];
ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
struct ans{
    ll a, b;
    void reduce()
    {
        ll d = gcd(a, b);
        a /= d;
        b /= d;
    }
}ans[maxm];

int a[maxn];
int num[maxn];
int n, m, unit;
bool cmp(Query a, Query b)
{
    if (a.L/ unit != b.L / unit) return a.L / unit < b.L / unit;
    else return a.R < b.R;
}

void work()
{
    ll temp = 0;
    memset(num, 0, sizeof(num));
    int L = 1;
    int R = 0;
    for (int i = 0; i < m; i++)
    {
        while( R < node[i].R)
        {
            R++;
            temp -= (ll) num[a[R]] * num[a[R]];
            num[a[R]]++;
            temp += (ll) num[a[R]] * num[a[R]];
        }
        while(R > node[i].R)
        {
            temp -= (ll) num[a[R]] * num[a[R]];
            num[a[R]]--;
            temp += (ll) num[a[R]] * num[a[R]];
            R--;
        }
        while(L < node[i].L)
        {
            temp -= (ll) num[a[L]] * num[a[L]];
            num[a[L]]--;
            temp += (ll) num[a[L]] * num[a[L]];
            L++;
        }
        while(L > node[i].L)
        {
            L--;
            temp -= (ll) num[a[L]] * num[a[L]];
            num[a[L]]++;
            temp += (ll) num[a[L]] * num[a[L]];
        }
        ans[node[i].id].a = temp - (R - L + 1);
        ans[node[i].id].b = (ll) (R - L + 1) * (R - L);
        ans[node[i].id].reduce();
    }
}
int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++)
        {
            node[i].id = i;
            scanf("%d%d", &node[i].L, &node[i].R);
        }
        unit = (int) sqrt(n);
        sort(node, node + m, cmp);
        work();
        for (int i = 0; i < m; i++)
        {
            printf("%lld/%lld\n", ans[i].a, ans[i].b);
        }
    }
    return 0;
}
