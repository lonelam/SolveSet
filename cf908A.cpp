#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
string s;
string inset = "aeiou13579";
int main()
{
  while(cin >> s)
  {
    set<char> st(inset.begin(), inset.end());
    int cnt = 0;
    for (char cc: s)
    {
      if (st.find(cc) != st.end())
      {
        cnt++;
      }
    }
    cout << cnt << endl;
  }
}
