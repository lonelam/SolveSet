#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 222
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
using namespace std;
int cover[maxn<<2];
double sum[maxn<<2], x[maxn];
struct seg
{
    double l, r, h;
    int flag;
    seg() {}
    seg(double a,double b,double c,int d) : l(a), r(b), h(c), flag(d) {}
    bool operator < (const seg &cmp) const
    {
        return h < cmp.h;
    }
}ss[maxn];
int bin(double key, int len, double x[])
{
    int l = 0, r = len - 1;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (key == x[m]) return m;
        else if (key < x[m]) r = m - 1;
        else l = m + 1;
    }
    return -1;
}
void PushUp(int rt,int l,int r)
{
    if (cover[rt]) sum[rt] = x[r+1] - x[l];
    else if (l == r) sum[rt] = 0;
    else sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void update(int L,int R,int f,int l,int r,int rt)
{
    if (L <= l && r <= R)
    {
        cover[rt] += f;
        PushUp(rt, l, r);
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, f, lson);
    if (m < R) update(L, R, f, rson);
    PushUp(rt, l, r);
}
int main()
{
    int n;
    int cas = 1;
    //freopen("data.in","r",stdin);
    while (~scanf("%d",&n) && n)
    {
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            double x1,y1,x2,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            x[m] = x1;
            ss[m++] = seg(x1, x2, y1, 1);
            x[m] = x2;
            ss[m++] = seg(x1, x2, y2, -1);
        }
        sort(x, x + m);
        sort(ss, ss + m);
        int k = 1;
        for (int i = 1; i < m; i++)
            if (x[i] != x[i-1]) x[k++] = x[i];
        memset(cover, 0, sizeof(cover));
        memset(sum, 0, sizeof(sum));
        double ret = 0;
        for (int i = 0; i < m - 1; i++)
        {
            int l = bin(ss[i].l, k, x);
            int r = bin(ss[i].r, k, x) - 1;
            if (l <= r) update(l, r, ss[i].flag, 0, k - 1, 1);
            ret += sum[1] * (ss[i+1].h - ss[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",cas++,ret);
    }
    return 0;
}
