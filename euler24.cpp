#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int fac[maxn];
int main()
{
  fac[0] = 1;
  for (int i = 1; i < 14; i++)
  {
    fac[i] = fac[i-1] * i;
  }
  int n, T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    n--;
    string init = "abcdefghijklm";
    set<char> rem(init.begin(), init.end());
    string ans;
    for (int k = 12; k >= 0; k--)
    {
      int pos = n / fac[k];
      n %= fac[k];
      auto it = rem.begin();
      for (int i = 0; i < pos; i++) it++;
      ans.push_back(*it);
      rem.erase(it);
    }
    printf("%s\n",ans.c_str());
  }
}
