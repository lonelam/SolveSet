#include <cstdio>
#include <set>
using namespace std;
const int  maxn = 5e5 + 10;
int a[maxn];
typedef long long ll;
multiset<int> mul;
int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf ("%d", a + i);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (mul.empty() || *mul.begin() >= a[i])
    {
      mul.insert(a[i]);
    }
    else
    {
      ans += a[i] - *mul.begin();
      mul.erase(mul.begin());
      mul.insert(a[i]);
      mul.insert(a[i]);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
