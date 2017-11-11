#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 100000 + 10;
int a[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        int j = 1;
        for (int i = 1; i <= n; i+= 2)
        {
            a[i] = j++;
        }
        for (int i = 2; i <= n; i+= 2)
        {
            a[i] = j++;
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d%c", a[i], i==n?'\n':' ');
        }
    }
}
