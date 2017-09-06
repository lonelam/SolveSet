#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int a[maxn];
pair<int,int>  b[maxn];
int ans[maxn];
int n;
int main()
{
  scanf(
    "%d", &n
  );
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", &b[i].first), b[i].second = i;
  sort(a, a + n);
  sort(b, b + n);
  reverse(b, b + n);
  for (int i = 0; i < n; i++)
  {
    ans[b[i].second] = a[i];
  }
  for (int i = 0; i < n; i++)
  {
    printf("%d ", ans[i]);
  }
}
