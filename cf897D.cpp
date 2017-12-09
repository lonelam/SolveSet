#include <bits/stdc++.h>
using namespace std;
int g[1000 + 5];
int main()
{
    int n, m, c;
    scanf("%d%d%d", &n, &m, &c);
    memset(g, -1, sizeof(g));
    while(m--)
    {
        int p;
        if (scanf("%d", &p) == -1) return 0;
        int L = 0, R = n - 1;
        while(g[L] != -1 && g[L] <= p) L++;
        while(g[R] != -1 && g[R] >= p) R--;
        if (L < n - R - 1 || L == n - R - 1 && p <= (c + 1)/ 2.0)
            printf("%d\n", L+1), g[L] = p;
        else
            printf("%d\n", R+1), g[R] = p;
        fflush(stdout);
        if (L == R) {cout <<"suc"<< endl; return 0;}
    }
    return 0;
}
