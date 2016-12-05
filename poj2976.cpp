#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 1010;
const double eps = 1e-10;

int n, k;
double a[maxn], b[maxn], h[maxn];
int main()
{
    while(~scanf("%d%d", &n, &k)!=EOF)
    {
        if (n == 0 && k == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &b[i]);
        }
        double l = 0, r = 100, mid, sum;
        while(r-l > eps)
        {
            mid = (l + r) / 2;
            for (int i = 0; i < n;i++)
            {
                h[i] = 100 * a[i] - mid * b[i];
            }
            sort(h, h + n);
            sum = 0;
            for (int i = k; i < n; i++)
            {
                sum += h[i];
            }
            if (sum > 0)
                l = mid;
            else
                r = mid;
        }
        printf("%.0f\n", l);
    }
    return 0;
}
