
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
using namespace std;
const int maxf = 2005;
bool nprime[maxf];
int ps[maxf];
int np = 0;
void init()
{
    nprime[1] = nprime[0] = true;
    for(int i = 2; i < maxf; i++)
    {
        if(!nprime[i])
        {
          cout << i << endl;
            for(int j = i + i; j < maxf; j+= i)
            {
                nprime[j] = true;
            }
            ps[np++] = i;
        }
    }
}
int main()
{
  cin.get();
  np = 0;
  init();
  cout << np << endl;
}
