#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
string s;
int presum[maxn];
int main()
{
  cin >> s;
  for (int i = 0; i < s.size(); i++)
  {
    presum[i+1] = presum[i] + (s[i]=='a');
  //  cout << presum[i+1] << " ";
  }
  // cout << endl;
  int ans = 0;
  int n = s.size();
  for (int i = 0; i <= n; i++)
  {
    for (int j = i; j <= n; j++)
    {
      ans = max(ans, j - i - presum[j] + presum[i] + presum[i] + presum[n] - presum[j]);
    }
  }
  cout << ans << endl;
}
