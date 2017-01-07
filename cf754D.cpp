#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 1000;
const ll moder = 1e9+7;
ll li[maxn], ri[maxn];
int lazy[maxn * 4];
//int cnt[maxn * 4];
ll disc[maxn * 2];
int n, k;
int dn;

void build(int l = 0, int r = dn, int rt = 1)
{
    if (l >= r)
    {
        return;
    }
    lazy[rt] = 0;
    if (l + 1 == r)
    {
        return;
    }
    const int mid = (l + r) /2 ;
    build(l, mid, rt << 1);
    build(mid, r, rt <<1 | 1);
}
void pushdown(int rt)
{
    if (lazy[rt] == 0)
    {
        return;
    }
    lazy[rt << 1] += lazy[rt];
    lazy[rt <<1 | 1] += lazy[rt];
    lazy[rt] = 0;
}
void add(int L, int R, int l = 0, int r= dn, int rt = 1)
{
    if (l >= r)
    {
        return;
    }
    if (L <= l && r <= R)
    {
    //    cout << l <<" "<< r << endl;
        lazy[rt]++;
        return;
    }
    if (l + 1 == r)
    {
        return;
    }
    pushdown(rt);
    const int mid = (l + r) / 2;
    if (L < mid)
    {
        add(L, R, l, mid, rt << 1);
    }
    if (mid <= R)
    {
        add(L,R,mid, r, rt << 1 | 1);
    }
}
void alldown(int l = 0, int r = dn, int rt = 1)
{
    if (l + 1 == r)
    {
    //    cout << lazy[rt] << " ";
        return;
    }
    pushdown(rt);
    const int mid = (l + r) / 2;
    alldown(l, mid, rt << 1 );
    alldown(mid, r, rt << 1 | 1);
}
int query(int q, int l = 0, int r = dn, int rt = 1)
{
    if (l + 1 == r)
    {
        //if (l == q)
        return lazy[rt];
        //else return -1;
    }
    const int mid = (l + r) / 2;
    if (q < mid)
    {
        return query(q,l, mid, rt << 1);
    }
    else
    {
        return query(q,mid, r, rt << 1 | 1);
    }
}
void init()
{
    dn = 0;
    for (int i = 0; i < n; i++)
    {
        disc[dn++] = li[i] * 2 + 1;
        disc[dn++] = ri[i] * 2;
    }
    sort(disc, disc + dn);
    dn = unique(disc, disc + dn) - disc;
    build();
    //memset(cnt, 0, sizeof(cnt));
}
void solve()
{
//    cout << "degb";
    init();
//    cout <<"deb";
    for (int i = 0; i < n;i ++)
    {
        int lpos = lower_bound(disc, disc + dn, li[i] * 2 + 1) - disc;
        int rpos = lower_bound(disc, disc + dn, ri[i] * 2  ) - disc;
    //    cout << lpos <<" "<< rpos << endl;
        add(lpos, rpos );
    }
    alldown();
    ll pre = 0;
    ll ansL = 0;
    ll ansR = 0;
    ll ans = 0;
    for (int i = 0; i < dn; i++)
    {
        int tt = query(i);
        cout <<disc[i] << " "<< tt <<"  "<< pre << "  "<<i <<endl;
        if (tt < k && pre != i )
        {
            ll len = disc[i] / 2LL - disc[pre] / 2LL;
            if (len > ans)
            {
                ans = len;
                ansL = disc[pre] / 2LL;
                ansR = disc[i] / 2LL;
            }
        }
        if (tt < k)
        {
            pre = i+1;
        }
    }

    if (pre != dn)
    {
        cout << "error";
        int len = disc[dn - 1] / 2 - disc[pre] / 2 ;
        if (len > ans)
        {
            ans = len;
            ansL = disc[pre] / 2;
            ansR = disc[dn - 1] / 2;
        }
    }
    //cout << "deg";
    if (ans == 0)
    {
        printf("0\n");
        for (int i = 1; i < k; i++)
        {
            printf("%d ", i);
        }
        printf("%d\n",k);
    }
    else
    {
        cout << ansL <<" "<<ansR << endl;
        printf("%d\n", ans);
        for (int i = 0;k && i < n; i++)
        {
            if (li[i] <= ansL && ansR <= ri[i])
            {
                k--;
                printf("%d%c", i + 1, k?' ':'\n');
            }
        }
    }
//    cout <<"wegtj";
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
    //    cout << n << endl;
        for (int j = 0; j < n; j++)
        {
        //    cout <<"debug";
    //    cout << n << endl;
        scanf("%lld%lld", li + j, ri+j);
        li[j] += moder;
        ri[j] += moder + 1LL;
            //cin >> li[j] >> ri[j];
        }
//        cout << "deubg";
        solve();
    }
}
