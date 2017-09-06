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
  int T;
  scanf("%d", &T);
  while(T--)
  {
    int P;
    scanf("%d", &P);
    P--;
    int cnt = 0;
    for (int i = 1; i * i <= P; i++)
    {
      if (P % i == 0)
      {
        if (i * i != P) cnt+=2;
        else cnt++;
      }
    }
    printf("%d\n", cnt);
    
  }
}
