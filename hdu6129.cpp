
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200000 +10;
int a[maxn];
int n, m;
void solve()
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a +i);
    }
    int step = 1;
    while(m)
    {
        if (m & 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (i + step < n) a[i + step] ^= a[i];
            }
        }
        m >>= 1;
        step <<= 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", a[i], i==(n-1)?'\n':' ');
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        solve();
    }
}
