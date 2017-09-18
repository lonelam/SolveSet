#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int r[maxn];

int main()
{
  int K;
  scanf("%d", &K);
  for (int i = 0; i < K; i++)
  {
    scanf("%d", r + i);
  }
  printf("%d\n", max(*max_element(r, r + K) - 25, 0));

}
