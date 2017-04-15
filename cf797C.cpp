#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
char s[maxn];
int m[maxn << 2];
int n;
char t[maxn];
char ans[maxn];
void pushup(int x)
{
    if (s[m[x << 1]] > s[m[x << 1 | 1]])
    {
        m[x] = m[x << 1 | 1];
    }
    else if (s[m[x << 1]] < s[m[x << 1 | 1]])
    {
        m[x] = m[x << 1];
    }
    else
    {
        m[x] = min(m[x << 1], m[x << 1 | 1]);
    }
}
void init(int L = 0, int R = n, int x = 1)
{
    if (L + 1 == R)
    {
        m[x] = L;
        return;
    }
    const int mid = L + (R - L )/ 2;
    init(L, mid, x << 1);
    init(mid, R, x << 1 | 1);
    pushup(x);
}
int query(int ql, int qr, int L = 0, int R = n, int x = 1)
{
    if (L + 1 == R)
    {
        return m[x];
    }
    if (ql <= L && R <= qr)
    {
        return m[x];
    }
    if (ql >= R || qr <= L)
    {
        //cout <<"debug"<<endl;
        return -1;
    }
    const int mid = L + (R - L) / 2;
    int ret = -1;
    if (ql < mid)
    {
        ret = query(ql, qr, L, mid, x << 1);
    }
    if (mid < qr)
    {
        if (ret == -1) ret = query(ql, qr, mid, R, x << 1 | 1);
        else
        {
            int rr = query(ql, qr, mid, R, x << 1 | 1);
            if (s[rr] == s[ret])
            {
                return min(rr, ret);
            }
            if (s[rr] > s[ret])
            {
                return ret;
            }
            else
            {
                return rr;
            }
        }
    }
    return ret;
}
int main()
{
    scanf("%s", s);
    n = strlen(s);
    int p = 0;
    int tp = -1;
    int ap = 0;
    init();
    while(p < n)
    {
        int c = query(p, n);
        if (tp == -1 || s[c] < t[tp])
        {
            for (int i = p; i < c; i++)
            {
                t[++tp] = s[i];
            }
            ans[ap++] = s[c];
            p = c + 1;
        }
        else
        {
            ans[ap++] = t[tp--];
        }
    }
    while(tp > -1)
    {
        ans[ap++] = t[tp--];
    }
    ans[ap] = '\0';
    printf("%s\n", ans);
}
