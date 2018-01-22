#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x, y;
    bool operator<(const point & rhs) const
    {
        if (x != rhs.x) return x > rhs.x;
        return y < rhs.y;
    }
} ps[500000 + 10], ans[500000 +10];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &ps[i].x, &ps[i].y);
    }
    sort(ps, ps + n);
    for (int i = 0; i < n; i++)
    {
    }
}
