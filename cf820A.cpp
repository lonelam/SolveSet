#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
   ll c,v0,v1,a,l;
   while(cin >> c >> v0 >> v1 >> a >> l)
   {
     ll rd = 0;
     for (int i = 0;; i++)
     {
       rd += min(v0 + a * i,v1);
       if (rd >= c)
       {
         cout << i+1<<endl;
         break;
       }
       rd -= l;
     }
   }
}
