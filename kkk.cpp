#include <bits/stdc++.h>
int main()
{
    int n, m, S, T, a, b, c, sum = 0;
    scanf("%d%d", &n, &m);
    S = 0;
    T = n + m + 1;
    isap mf(T + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c);
        mf.add_edge(m + i, T, c);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        mf.add_edge(i, m + a, inf);
        mf.add_edge(i, m + b, inf);
        mf.add_edge(S, i, c);
        sum += c;
    }
    printf("%d\n", sum - mf.maxflow(S, T));
    return 0;
}
