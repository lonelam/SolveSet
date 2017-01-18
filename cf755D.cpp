#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 1000;
int n;
int BIT[maxn];

void add(int x)
{
    if (x <= 0) return;
    while(x <= n)
    {
        BIT[x] ++;
        x += x & (-x);
    }
}
int query(int x)
{
    int ans = 0;
    while(x > 0)
    {
        ans += BIT[x];
        x -= x & ( -x);
    }
    return ans;
}
int main()
{
    int k;

    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(BIT, 0 ,sizeof(BIT));
        if (k > n / 2)
        {
            k = n - k;
        }
        ll area = 1;
        int p = 1;
        for (int i = 1; i < n; i++)
        {

            if (p + k <= n)
            {
                area += (query(p + k - 1) - query(p ))+ 1;
                add(p);
                p += k;
                add(p);
            }
            else
            {
                area += query(n) - query(p) + 1;
                area += query((p + k - n - 1));
                add(p);
                p = p + k - n;
                add(p);
            }
            printf("%lld ",area);
        //    cout << area << (i == n ? "\n":" ");
        }
        if (p + k <= n)
        {
            area += (query(p + k - 1) - query(p ))+ 1;
            add(p);
            p += k;
            add(p);
        }
        else
        {
            area += query(n) - query(p) + 1;
            area += query((p + k - n - 1));
            add(p);
            p = p + k - n;
            add(p);
        }
        printf("%lld\n",area);
    }
}
