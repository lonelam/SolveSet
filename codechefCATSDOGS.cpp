#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

int main()
{
    int T;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            int C, D, L;
            scanf("%d%d%d", &C,&D,&L);
            if (L % 4)
            {
                printf("no\n");
            }
            else
            {
                int upcat = min(C , D*2);
                if (L/4 > (C + D)  || L/4 < (C - upcat + D))
                {
                    printf("no\n");
                }
                else
                {
                    printf("yes\n");
                }
            }
        }
    }
}
