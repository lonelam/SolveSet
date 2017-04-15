#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int a[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int odd = 0, even = 0;
    bool ovis = false;
    for (int i = 0; i < n; i++)
    {
        if (!ovis)
        {
            if (abs(a[i]) & 1)
            {
                odd = max(a[i], even + a[i]);
                ovis = true;
            }
            else
            {
                even = max(even, even + a[i]);
            }
            continue;
        }
        if (abs(a[i]) & 1)
        {
            int todd = max(odd, even + a[i]);
            even = max(even, odd + a[i]);
            odd = todd;
        }
        else
        {
            odd = max(odd, odd + a[i]);
            even = max(even, even + a[i]);
        }
    }
    printf("%d\n", odd);
}
