#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
string digit[] = {"Zero","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string under20[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> undertrans(int x)
{
  vector<string> ans;
  assert(x < 1000);
  if (!x) return ans;
  if (x/100)
  {
    ans.push_back(digit[x/100]);
    ans.push_back("Hundred");
  }
  x %= 100;
  if (x < 10)
  {
    ans.push_back(digit[x]);
  }
  else if (x < 20)
  {
    ans.push_back(under20[x-10]);
  }
  else
  {
    ans.push_back(tens[x / 10]);
    x%=10;
    if (x) ans.push_back(digit[x]);
  }
  return ans;
}
int main()
{
  int T;
  ll n;
  cin >> T;
  while(T--)
  {
    cin >> n;
    vector<string> output;
    ll tri_part = n / 1000000000000LL;
    n %= 1000000000000LL;
    ll bil_part = n / 1000000000LL;
    n %=1000000000LL;
    ll mil_part = n / 1000000LL;
    n %=1000000LL;
    ll tho_part = n / 1000LL;
    n %= 1000LL;
    ll sin_part = n;
    if (tri_part)
    {
      vector<string> tmp = undertrans(tri_part);
      output.insert(output.end(), tmp.begin(), tmp.end());
      output.push_back("Trillion");
    }
    if (bil_part)
    {
      vector<string> tmp = undertrans(bil_part);
      output.insert(output.end(), tmp.begin(), tmp.end());
      output.push_back("Billion");
    }
    if (mil_part)
    {
      vector<string> tmp = undertrans(mil_part);
      output.insert(output.end(), tmp.begin(), tmp.end());
      output.push_back("Million");
    }
    if (tho_part)
    {
      vector<string> tmp = undertrans(tho_part);
      output.insert(output.end(), tmp.begin(), tmp.end());
      output.push_back("Thousand");
    }
    if (sin_part)
    {
      vector<string> tmp = undertrans(sin_part);
      output.insert(output.end(), tmp.begin(), tmp.end());
    }
    for (int i = 0; i < output.size(); i++)
    {
      if (i) cout << " ";
      cout << output[i];
    }
    cout << endl;
  }
}
