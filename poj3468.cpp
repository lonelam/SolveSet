#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
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
const int maxn = 100000 + 1000;
const int maxb = 1000 + 10;
ll a[maxn];
int belong[maxn];
ll buffer[maxb];
ll A[maxb];
int bsize, bnum, n;
int L[maxb], R[maxb];

void build()
{
//    cout << "debug";
    bsize = sqrt(n);
    bnum = n / bsize;
    if (n % bsize) bnum++;
    for (int i = 0; i < bnum; i++)
    {
        A[i] = 0;
        buffer[i] = 0;
        L[i] = i * bsize;
        R[i] = (i + 1) * bsize;
    }
    R[bnum - 1] = n;
    for (int i = 0; i < n; i++)
    {
        belong[i] = i / bsize;
        A[belong[i]] += a[i];
    }
}

void add(int f,int t, ll adder)
{
    if (belong[f] == belong[t])
    {
        for (int i = f; i <= t; i++)
        {
            a[i] += adder;
        }
        A[belong[f]] += adder * (t - f + 1);
        return;
    }
    for (int i = f; i < R[belong[f]]; i++)
    {
        a[i] += adder;
    }
    A[belong[f]] += adder * (R[belong[f]] - f);
    for (int i = belong[f] + 1; i < belong[t]; i++)
    {
        buffer[i] += adder;
    }
    for (int i = L[belong[t]]; i <= t; i++)
    {
        a[i] += adder;
    }
    A[belong[t]] += adder * (t - L[belong[t]] + 1);
}

ll query(int l, int r)
{
    if (belong[l] == belong[r])
    {
        ll sum = 0;
        for (int k = l; k <= r; k++)
        {
            sum += a[k];
        }
        return sum + buffer[belong[l]] * (r - l + 1);
    }
    ll sum = 0;
    for (int i = L[belong[l]]; i < R[belong[l]]; i++)
    {
        a[i] += buffer[belong[l]];
    }
    A[belong[l]] += buffer[belong[l]] * bsize;
    buffer[belong[l]] = 0;
    for (int i = l; i < R[belong[l]]; i++)
    {
        sum += a[i];
    }
    for (int i = belong[l] + 1; i < belong[r]; i++)
    {
        sum += A[i] + buffer[i] * bsize;
    }
    for (int i = L[belong[r]]; i < R[belong[r]]; i++)
    {
        a[i] += buffer[belong[r]];
    }
    A[belong[r]] += buffer[belong[r]] * bsize;
    buffer[belong[r]] = 0;
    for (int i = L[belong[r]]; i<= r; i++)
    {
        sum += a[i];
    }
    return sum;
}

int main()
{
    int Q;
    while(scanf("%d%d", &n, &Q)!=EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", a + i);
        }
        build();
        char cmd[100];
        int op1, op2;
        for (int i = 0; i < Q; i++)
        {
            scanf("%s", cmd);
            if (cmd[0] == 'Q')
            {
                scanf("%d%d", &op1, &op2);
                printf("%lld\n", query(op1 - 1, op2 - 1));
            }
            else if (cmd[0] == 'C')
            {
                int from, to, adder;
                scanf("%d%d%d", &from, &to, &adder);
                add(from - 1, to - 1, adder);
            }
        }
    }
}
