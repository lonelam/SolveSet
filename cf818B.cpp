#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int l[maxn];
int ans[maxn];
int pos[maxn];
int main(){
  int n, m;
  cin >> n >> m;
  set<int> rem;
  for (int i = 0; i < n; i++) rem.insert(i);
  for (int i = 0; i < m; i++)
  {
    cin >> l[i] ;
    l[i]--;
  }
  memset(ans,-1,sizeof(ans));
  for (int i = 1; i < m; i++)
  {
    int ai = (l[i] - l[i-1]+n)% n;
    if (ans[l[i-1]] == ai)
    {
      continue;
    }
    else if (rem.find(ai) != rem.end())
    {
      ans[l[i-1]] = ai;
      rem.erase(ai);
    }
    else
    {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (ans[i] == -1)
    {
      ans[i] = *rem.begin();
      rem.erase(rem.begin());
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << (ans[i]?ans[i]:n) << ((i==n-1)?"\n":" ");
  }
}
