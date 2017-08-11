#include <bits/stdc++.h>
#include <cmath>
using namespace std;
const int maxn = 100000 + 100;
typedef long double ld;
typedef long long ll;
int n;
int bitnum[maxn], digitnum[maxn];
int main()
{
    int kase = 1;
    while(scanf("%d", &n) != EOF)
    {
        ld k = (ld)n * log10((ld)2);
       // cout << k << endl;
        printf("Case #%d: %lld\n", kase++, (ll)k);
    }
}
