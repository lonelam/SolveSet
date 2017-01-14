#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 110000+100;
int n,k;
int a[maxn];
bool scan_d(int & ret)
{
    int c;
    if (c = getchar(), c==EOF) return 0;
    while(c < '0' || c > '9') c = getchar();
    ret = c - '0';
    while(c = getchar(),c>='0' && c <= '9') ret = ret * 10 + (c - '0');
    return 1;
}
int main()
{
    while(scan_d(n)&& scan_d(k))
    {
        for (int i = 0; i < n; i++)
        {
            scan_d(a[i]);
        //    scanf("%d", a + i);
        }
            ll ans = 0;
            ll sum = 0;
            for (int i = 0; i < k; i++)
            {
                sum += a[i];
            }
            for (int i = k; i <= n; i++)
            {
                ans = max(ans, sum);
                sum -= a[i - k];
                sum += a[i];
            }
            printf("%.2lf\n", (double)ans / k);
    }
}
