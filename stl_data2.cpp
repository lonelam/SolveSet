#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
random_device rd;
char randchar()
{
  static uniform_int_distribution<int> rchar((int)'a', (int)'z');
  return (char) rchar(rd);
}
string rndname()
{
  static uniform_int_distribution<int> lenrand(5, 30);
  int len = lenrand(rd);
  string ret;
  for (int i = 0; i < len; i++)
  {
    ret += randchar();
  }
  return ret;
}
int main()
{
  for (int i = 1; i <= 9; i++)
  {
    string fext = ".in";
    string fname(1, '0' + i);
    string ffull = fname + fext;
    freopen(ffull.c_str(), "w", stdout);
    vector<string> st;
    for (int i = 0; i < 300000; i++)
    {
      st.push_back(rndname());
    }
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    int n = st.size();
    random_shuffle(st.begin(), st.end());
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
      cout << st[i] << endl;
    }
  }
}
