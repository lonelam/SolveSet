#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;

char A[maxn];
int main()
{
    int T;
    int kase = 1;
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            printf("Case #%d:\n", kase++);
            scanf("%s", A);
            int len = strlen(A);
            int cnt = 0;
            for (int i = 1; i < len; i++)
            {
                if ( A[i] == 'B' && A [i - 1] == 'A')
                {
                    A[i] = A[i - 1] = ' ';
                    cnt++;
                }
            }
            printf("%d\n", cnt);
        }
    }
}
