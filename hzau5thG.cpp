#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50000 + 100;
int disc[maxn];
int least[maxn << 2];
int A[maxn];
int dn;
void pushup(int x)
{
    least[x] = min(least[x << 1], least[x << 1 | 1]);
}
void add(int q, int val, int L = 0, int R = dn, int x = 1)
{
    if (L + 1 == R)
    {
        least[x] = min(least[x], val);
        //cout <<"-----" << L << " "<<least[L] << endl;
        return;
    }
    const int mid = L + (R - L) / 2;
    if (q < mid)
    {
        add(q, val, L, mid, x << 1);
    }
    else
    {
        add(q, val, mid, R, x << 1 | 1);
    }
    pushup(x);
}
int query(int ql, int qr, int L = 0, int R = dn, int x = 1)
{
    if (R <= ql || qr <= L)
    {
        return inf;
    }
    if (ql <= L && R <= qr)
    {
    //    cout << "----"<<L << " "<< R << endl;
        return least[x];
    }
    const int mid = L + (R - L) / 2;
    int ret = inf;
    if (ql < mid) ret = query(ql, qr, L, mid, x << 1);
    if (mid < qr) ret = min(ret, query(ql, qr, mid, R, x << 1 | 1));
    return ret;
}
int n;
int main()
{
    while(scanf("%d", &n)!=EOF)
    {
        for (int i = 0; i < n;i ++)
        {
            scanf("%d", A + i);
            disc[i] = A[i];
        }
        sort(disc, disc + n);
        dn = unique(disc, disc + n) - disc;
        for (int i = 0; i < n; i++)
        {
            A[i] = lower_bound(disc, disc + dn, A[i]) - disc;
        }
        memset(least, inf, sizeof(least));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
    //        cout << "**" << i <<" "<< A[i] <<" "<< ans << " "<< query(0, A[i] + 1) << endl;
            ans = max(ans, i - query(0, A[i] + 1));
            add(A[i], i);
        }
        printf("%d\n", ans);
    }

}
