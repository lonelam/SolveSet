#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXN = 52;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS

int n, d[MAXN];
int64 f[2][MAXN][MAXN][MAXN][MAXN] = {{{{{ 0 }}}}};

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &d[i]);

    int cur = 0, next = 1;
    f[cur][d[0] == 2][d[0] == 3][d[1] == 2][d[1] == 3] = 1;
    for (int i = 1; i < n - 1; ++i) {
        memset(f[next], 0, sizeof f[next]);
        for (int p1 = 0; p1 <= n; ++p1)
            for (int p2 = 0; p1 + p2 <= n; ++p2)
                for (int c1 = 0; c1 + p1 + p2 <= n; ++c1)
                    for (int c2 = 0; c1 + c2 + p1 + p2 <= n; ++c2) if (f[cur][p1][p2][c1][c2] > 0) {
                        int64 val = f[cur][p1][p2][c1][c2];
                        // (1) Start a new level
                        if (p1 == 0 && p2 == 0) {
                            (f[cur][c1][c2][0][0] += val)__;
                            continue;
                        }
                        // (2) Stay on current level
                        // Which type of vertex in the last level?
                        for (int last_level = 0; last_level <= 1; ++last_level) {
                            int last_ways;
                            if (last_level == 0) {
                                last_ways = p1;
                                if (--p1 < 0) { ++p1; continue; }
                            } else {
                                last_ways = p2;
                                if (--p2 < 0) { ++p2; continue; } else ++p1;
                            }
                            // Which type of vertices in the current level?
                            if (d[i + 1] == 2) {
                                // a) Leave as it is
                                (f[next][p1][p2][c1 + 1][c2] += val * last_ways)__;
                                // b) 1-plug
                                if (c1 >= 1)
                                    (f[next][p1][p2][c1 - 1][c2] += val * last_ways * c1)__;
                                // c) 2-plug
                                if (c2 >= 1)
                                    (f[next][p1][p2][c1 + 1][c2 - 1] += val * last_ways * c2)__;
                            } else {
                                // a) Leave as it is
                                (f[next][p1][p2][c1][c2 + 1] += val * last_ways)__;
                                // b) 1-plug
                                if (c1 >= 1)
                                    (f[next][p1][p2][c1][c2] += val * last_ways * c1)__;
                                // c) 2-plug
                                if (c2 >= 1)
                                    (f[next][p1][p2][c1 + 2][c2 - 1] += val * last_ways * c2)__;
                                // d) 1-plug + 1-plug
                                if (c1 >= 2)
                                    (f[next][p1][p2][c1 - 2][c2] += val * last_ways * c1 * (c1 - 1) / 2)__;
                                // e) 2-plug + 2-plug
                                if (c2 >= 2)
                                    (f[next][p1][p2][c1 + 2][c2 - 2] += val * last_ways * c2 * (c2 - 1) / 2)__;
                                // f) 1-plug + 2-plug
                                if (c1 >= 1 && c2 >= 1)
                                    (f[next][p1][p2][c1][c2 - 1] += val * last_ways * c1 * c2)__;
                            }
                            if (last_level == 0) ++p1; else ++p2, --p1;
                        }
                    }
        cur ^= 1, next ^= 1;
    }

    printf("%lld\n", f[cur][0][0][0][0]);
    return 0;
}
