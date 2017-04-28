#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int a[maxn], b[maxn];

int main()
{
    int n, T;
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", a + i);
            }
            int cnt = 0, tar = -1;
            for (int i = 0; i < n;i ++)
            {
                scanf("%d", b + i);
                if (b[i] == 2 || b[i] == 1 && a[i] > 1)
                {
                    tar = i;
                    cnt++;
                }
            }
            int awin = -1;
            int xsum =0;
            if (!cnt)
            {
                for (int i = 0; i < n; i++)
                {
                    xsum ^= a[i];
                }
                if (xsum)
                {
                    awin = 1;
                }
                else
                {
                    awin = 0;
                }
            }
            else if (cnt == 1)
            {
                //cout << tar << " "<< a[tar] << endl;
                if (b[tar] == 1)
                {
                    if (a[tar] & 1)
                    {
                        a[tar] = 0;
                    }
                    else
                    {
                        a[tar] = 1;
                    }
                }
                else
                {
                    if (a[tar] & 1)
                    {
                        awin = 0;
                    }
                    else
                    {
                        a[tar] = 0;
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    xsum ^= a[i];
                }
                if (awin == 0 || xsum)
                {
                    awin = 0;
                }
                else
                {
                    awin = 1;
                }
            }
            else
            {
                awin = 0;
            }
            if (awin)
            {
                printf("Alice\n");
            }
            else
            {
                printf("Bob\n");
            }
        }
    }
}
