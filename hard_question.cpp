#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n;
char vin[maxn];
char cath[maxn];
int main()
{
  while(scanf("%d", &n) != EOF)
  {
    scanf("%s%s", vin, cath);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (vin[i] != '.' && vin[i] != cath[i])
      {
        ans++;
      }
    }
    printf("%d\n", ans);
  }
}
