#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int s[maxn];
int main()
{
    int T;
    int n;
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", s + i);
            }
            sort(s, s + n);
            bool ok = true;
            if (n < 10 || n > 13) ok = false;
            if (!ok || s[0] != 1 || s[1] != 1) ok = false;
            const int tn = n - 1;
            for (int i = 1; i < tn; i++)
            {
                if (s[i] - s[i - 1] > 2)
                {
                    ok = false;
                }
            }
            if (tn > 0 && s[tn] == s[tn - 1]) ok = false;
            if (ok)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
}
