#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 100;
int a[maxn], b[maxn];
int main()
{
    int T;
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            int n;
            scanf("%d", &n);
            int cnt = 0;
            int xsum = 0;
            for (int i = 0; i < n; i++)
            {
                scanf("%d", a + i);
            }
            int bi;
            for (int i = 0; i < n ; i++)
            {
                scanf("%d", &b[i]);
                if (b[i] == 1)
                {
                    cnt++;

                }
                if (b[i] == 2)
                {
                    cnt++;
                    if (a[i] & 1)
                    {
                        cnt++;
                    }
                }
            }
            if (cnt > 1)
            {
                printf("Bob\n");
            }
            else if (cnt == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    if (b[i] == 1)
                    {
                        if (a[i] & 1)
                        {
                            xsum ^= 0;
                           // break;
                        }
                        else xsum ^= 1;
                    }
                    else if (b[i] == 2)
                    {
                        if (a[i] & 1)
                        {
                            xsum = 0;
                            break;
                        }
                        xsum ^= 0;
                    }
                    else
                    {
                        xsum ^= a[i];
                    }
                }
                if (!xsum)
                    printf("Alice\n");
                else
                    printf("Bob\n");
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    xsum ^= a[i];
                }
                if (xsum == 0)
                {
                    printf("Bob\n");

                }
                else
                    printf("Alice\n");
            }
        }
    }
}
