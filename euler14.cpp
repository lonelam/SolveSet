#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const ll maxn = 100000000 + 100;
int mem[maxn];
const int ub = 5e6 + 100;
int dfs(ll n)
{
  //cout << n << endl;
  if (n>=maxn) return n&1?dfs(3*n+1)+1:dfs(n/2)+1;
  if (mem[n]) return mem[n];
  if (n & 1) return dfs((3 * n + 1)/2)+2;
  return mem[n]=dfs(n / 2)+1;
}
int ans[ub];
int main()
{
  mem[1] = 1;
  ans[1] = 1;
  for (int i = 2; i < ub; i++)
  {
    if (dfs(ans[i-1]) <= dfs(i))
    {
      ans[i] = i;
      //cout << i << endl;
    }
    else
    {
      ans[i] = ans[i-1];
    }
  }
//  cout << "done"<<endl;
  int T, n;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d", &n);
      printf("%d\n", ans[n]);
    }
  }

}
