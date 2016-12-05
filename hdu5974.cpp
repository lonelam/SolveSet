#include<stdio.h>
#include<assert.h>
#include<math.h>
using namespace std;

int gcd(int a, int b)
{
    return b == 0? a : gcd(b, a % b);
}

int main()
{
    int a, b, c, d, e, f, g, x, y;
    while(scanf("%d%d", &a, &b) != EOF)
    {
        assert(a <= 2 * 10000 && a >= 1);
        assert(b <= 1000000000 && b >= 1);
        c = gcd(a, b);
        d = a / c;
        e = b / c;
        f = d * d - 4 * e;
        if (f < 0)
        {
            printf("No Solution\n");
            continue;
        }
        g = (int) sqrt(f);

        if (g * g != f)
        {
            printf("No Solution\n");
            continue;
        }
        g = -g;
        x = (g + d) / 2 * c;
        y = a - x;
        assert(x > 0 && y > 0);
        printf("%d %d\n", x, y);
    }
    return 0;
}
