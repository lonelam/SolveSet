#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
int a[maxn];
int acc[maxn];
inline int lsb(int x)
{
    return x & (-x);
}
int n;
void add(int x)
{
    while(x <= n)
    {
        ++acc[x];
        x += lsb(x);
    }
}
int query(int x)
{
    int ret = 0;
    while(x)
    {
        ret += acc[x];
        x -= lsb(x);
    }
    return ret;
}
int main()
{
    while(scanf("%d", &n)!=EOF)
    {
        memset(acc, 0, sizeof(acc));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a + i);
            if (a[i] < n) add(a[i]);
        }
        //sort(a + 1, a + n + 1);
        int e = 1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= n) continue;
            int q = query(a[i]);
            int te = (q) / a[i];
            if (q % a[i]) ++te;
            e = max(te, e);
        }
        printf("%d\n", e);
    }
}
