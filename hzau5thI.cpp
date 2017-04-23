#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
int n, m;
char S[maxn];
int lseg[maxn << 2];
int rseg[maxn << 2];
int midseg[maxn << 2];
int lazy[maxn << 2];
void pushup(int x, int L, int R)
{
    const int mid = L + (R - L) / 2;
    if (lseg[x << 1] == mid - L)
    {
        lseg[x] = lseg[x << 1] + lseg[x << 1 | 1];
    }
    else
    {
        lseg[x] = lseg[x << 1];
    }
    if (rseg[x << 1 | 1] == R - mid)
    {
        rseg[x] = rseg[x << 1 | 1] + rseg[x << 1];
    }
    else
    {
        rseg[x] = rseg[x << 1 | 1];
    }
    midseg[x] = max({midseg[x << 1], rseg[x << 1] + lseg[x << 1 | 1], midseg[x << 1 | 1]});
}

void pushdown(int x, int L, int R)
{
    if (lazy[x] == -1) return;
    if (lazy[x] == 1)
    {
        lazy[x << 1] = lazy[x << 1 | 1] = 1;
        lazy[x] = -1;
        lseg[x << 1] = rseg[x << 1] = midseg[x << 1] = lseg[x << 1 | 1]  = rseg[x << 1 | 1] = midseg[x << 1 | 1] = 0;
    }
    else if (lazy[x] == 2)
    {
        const int mid = L + (R - L) / 2;
        lazy[x << 1] = lazy[x << 1 | 1] = 2;
        lazy[x] = -1;
        lseg[x << 1] = rseg[x << 1] = midseg[x << 1] = mid - L;
        lseg[x << 1 | 1] = rseg[x << 1 | 1] = midseg[x << 1 | 1] = R - mid;
    }
}
void modify(int ql, int qr, int v, int L = 0, int R = n, int x = 1)
{
    if (ql <=L && R <= qr)
    {
        lazy[x] = v;
        if (v == 1)
        {
            lseg[x] = rseg[x] = midseg[x] = 0;
        }
        else if (v == 2)
        {
            lseg[x] = rseg[x] = midseg[x] = R - L;
        }
        return;
    }
    if (qr <= L || R <= ql)
    {
        return;
    }
    const int mid = L + (R - L) / 2;
    pushdown(x, L, R);
    if (ql < mid) modify(ql, qr, v, L, mid, x << 1);
    if (mid < qr) modify(ql, qr, v, mid, R, x << 1 | 1);
    pushup(x, L, R);
}
struct qret
{
    int l, r, m;
};
qret query(int ql, int qr, int L = 0, int R = n, int x = 1)
{
    if (ql <= L && R <= qr)
    {
        return {lseg[x], rseg[x], midseg[x]};
    }
    if (qr <= L || R <= ql)
    {
        return {0, 0, 0};
    }
    const int mid = L + (R - L) / 2;
    qret ret = {0, 0, 0};
    pushdown(x, L, R);
    qret lans = query(ql, qr, L, mid, x << 1);
    qret rans = query(ql, qr, mid, R , x << 1 | 1);
    if (lans.l == mid - L)
    {
        ret.l = lans.l + rans.l;
    }
    else
    {
        ret.l = lans.l;
    }
    if (rans.r == R - mid)
    {
        ret.r = rans.r + lans.r;
    }
    else
    {
        ret.r = rans.r;
    }
    ret.m = max({lans.m, rans.m, lans.r + rans.l});
    pushup(x, L, R);
    return ret;
}

void build(int L = 0, int R = n, int x = 1)
{
    if (L + 1 == R)
    {
        if (S[L] == 'A')
        {
            lseg[x] = rseg[x] = midseg[x] = 0;
        }
        else if (S[L] == 'B')
        {
            lseg[x] = rseg[x] = midseg[x] = 1;
        }
        return;
    }
    const int mid = L + (R - L) / 2;
    build(L, mid, x << 1);
    build(mid, R, x << 1 | 1);
    pushup(x, L, R);
}
int main()
{
    int T;
    int kase = 1;
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            memset(lazy, -1, sizeof(lazy));
            scanf("%d%d", &n, &m);
            scanf("%s", S);
            build();
            printf("Case #%d:\n", kase++);
            int cmd, ll, rr, v;
            for (int i = 0; i < m; i++)
            {
                scanf("%d", &cmd);
                if (cmd == 1)
                {
                    scanf("%d%d%d", &ll, &rr, &v);
                    modify(ll - 1, rr, v);
                }
                else if (cmd == 2)
                {
                    scanf("%d%d", &ll, &rr);
                    qret ans = query(ll - 1, rr);
                    printf("%d\n", ans.m);
                }
            }
        }
    }
}
