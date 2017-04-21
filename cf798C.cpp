#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int a[maxn];
int ra[maxn];
int gcd(int x, int y)
{
    //if (x == 0) return y;
    return y ? gcd(y, x % y) : x;
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {

        for (int i = 0 ; i < n; i++)
        {
            scanf("%d", a + i);
            ra[i] = a[i];
        }
        int g = a[0];
        for (int i = 1; i < n; i++)
        {
            g = gcd(g, a[i]);
        }
        if (g != 1)
        {
            printf("YES\n0\n");
        }
        else
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                while (a[i - 1] & 1 || a[i] & 1)
                {
                    int t = a[i - 1];
                    a[i - 1] = a[i] - a[i - 1];
                    a[i] += t;
                    cnt++;
                }
            }

                printf("YES\n%d\n", cnt);
        }

    }
}
