#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
char a[maxn];
char b[maxn];
int d[maxn];
int vp[maxn];
int main()
{
    while(scanf("%s%s", a, b)!=EOF)
    {
        int alen = strlen(a), blen = strlen(b);
        for (int i = 0; i < alen; i++)
        {
            scanf("%d", d + i);
            vp[d[i] - 1] = i + 1;
        }
        int L = 0, R = alen;
        while(L + 1 < R)
        {
            const int mid = L + (R - L) / 2;
            int j = alen - 1;
            bool ok = true;

            for (int i = blen - 1; i >= 0; i--)
            {
                while(j >= 0)
                {
                    j--;
                    if (vp[j+1] > mid && a[j+1] == b[i]) break;
                    else if (j < 0)
                    {
                        ok= false;
                    }
                }
                if (i && j < 0) ok = false;
                if (!ok) break;
            }
            if (!ok)
            {
                R = mid;
            }
            else
            {
                L = mid;
            }
        }

        printf("%d\n", L);
    }
}
