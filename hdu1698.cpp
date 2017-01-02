#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

int lazy[maxn << 2];
int sum[maxn << 2];

void pushup(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void pushdown(int rt, int m)
{
    if (lazy[rt])
    {
        lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
        sum[rt << 1] = (m - (m >> 1)) * lazy[rt];
        sum[rt << 1 | 1] = (m >> 1) * lazy[rt];
        lazy[rt] = 0;
    }
}

void build(int l, int r, int rt)
{
    lazy[rt] = 0;
    if (l == r)
    {
        sum[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int L, int R, int c, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        lazy[rt] = c;
        sum[rt] = c * ( r - l + 1);
        return;
    }
    pushdown(rt, r - l  + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, c, lson);
    if (R > m) update(L, R, c, rson);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += query(L, R, lson);
    if (m < R) ret += query(L, R, rson);
    return ret;
}
int main()
{
    int T, kase = 1;
    while(scanf("%d", &T) !=EOF )
    {
        while(T--)
        {
            int n, q;
            scanf("%d%d", &n, &q);
            build(1, n, 1);
            //cout << "djeb"<<endl;
            int f,t,c;
            while(q--)
            {
                scanf("%d%d%d",&f,&t,&c);
                update(f, t, c, 1, n, 1);
            }
            //cout <<"ewgjio"<<endl;
            printf("Case %d: The total value of the hook is %d.\n", kase++, query(1, n, 1, n, 1));
        }

    }
}
