#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
bool hole[maxn];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int holepos;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &holepos);
        hole[holepos] = true;
    }
    int bone = 1;
    int u,v;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d",&u,&v);
        if (hole[bone])
        {
            printf("%d\n",bone);
            return 0;
        }
        if (u == bone)
        {
            bone = v;
        }
        else if (v == bone)
        {
            bone = u;
        }
    }
    printf("%d\n", bone);
}
