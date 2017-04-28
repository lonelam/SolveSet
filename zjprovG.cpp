#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
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
=======
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
>>>>>>> 8fd939d8dec9d211f04cc0cb6c70ea0f57ff8e09
            for (int i = 0; i < n; i++)
            {
                scanf("%d", a + i);
            }
<<<<<<< HEAD
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
=======
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
>>>>>>> 8fd939d8dec9d211f04cc0cb6c70ea0f57ff8e09
                for (int i = 0; i < n; i++)
                {
                    xsum ^= a[i];
                }
<<<<<<< HEAD
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
=======
                if (xsum == 0)
                {
                    printf("Bob\n");

                }
                else
                    printf("Alice\n");
>>>>>>> 8fd939d8dec9d211f04cc0cb6c70ea0f57ff8e09
            }
        }
    }
}
