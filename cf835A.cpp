#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
  int s, v1,v2,t1,t2;
  while(cin >> s >> v1 >> v2 >> t1 >> t2)
  {
    int a1 = s * v1 + t1 * 2;
    int a2 = s * v2 + t2 * 2;
    if (a1 == a2)
    {
      cout << "Friendship\n";
    }
    else if (a1 < a2)
    {
      cout << "First\n";
    }
    else
    {
      cout << "Second\n";
    }

  }
}
