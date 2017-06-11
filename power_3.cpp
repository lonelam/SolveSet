#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const ll moder = 1e9 + 7;
int main()
{
  set<ll> st;
  ll mul = 1;
  while(st.find(mul) == st.end())
  {
    st.insert(mul);
    if (st.size() % 10000 == 0) cout << st.size();
    mul = (mul * 3) % moder;
  }
  cout << st.size() << endl;
}
