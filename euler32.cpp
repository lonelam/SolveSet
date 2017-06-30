#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n;
int digit[maxn];
int main()
{
  while(cin >> n)
  {
    set<int> cnt;
    for (int i = 0; i < n; i++) digit[i] = i + 1;
    do
    {
      for (int i = 1; i +1< n; i++)
      {
        for (int j = i; j < n; j++)
        {
          int m1 = 0;
          for (int k = 0; k < i; k++)
          {
            m1 *= 10;
            m1 += digit[k];
          }
          int m2 = 0;
          for (int k = i; k < j; k++)
          {
            m2 *= 10;
            m2 += digit[k];
          }
          int ans = 0;
          for(int k = j; k < n; k++)
          {
            ans *= 10;
            ans += digit[k];
          }
          if (m1 * m2 == ans) cnt.insert(ans);
        //  cout << m1 <<" "<< m2 << " "<< ans << endl;
        }
      }
    }
    while(next_permutation(digit, digit + n));
    cout << accumulate(cnt.begin(), cnt.end(), 0) << endl;
  }
}
