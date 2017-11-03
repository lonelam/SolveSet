#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
  int n;
  while(cin >> n)
  {
    set<string> st;
    for (int i = 0; i < n; i++)
    {
      string tmp, tar;
      cin >> tmp;
      for (char x: tmp)
      {
        if (x == 'h')
        {
          while(!tar.empty() && tar.back() == 'k') tar.pop_back();
          tar.push_back('h');
        }
        else if (x == 'u')
        {
          tar.push_back('o');
          tar.push_back('o');
        }
        else
        {
          tar.push_back(x);
        }
      }
      st.insert(tar);
    }
    cout << st.size() << endl;
  }
}
