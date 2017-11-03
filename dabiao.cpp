#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
int sq(int x)
{
    return x * x % 2017;
}
int main()
{
    int ans = 0;

    cout << ans << endl;
=======
typedef long long ll;
typedef long double ld;
std::mt19937 rng_engine{(size_t)(new char)};
std::uniform_int_distribution<int> dist{1, 1000};
ld calc(ld a, ld b, ld c)
{
  ld p = (a + b + c) / 2.0;
  return sqrtl(p * (p-a) * (p-b) * (p-c));
}
int main()
{
  int x, y, z;
  for (int t = 4; t < 1000000; t++)
  {
    ld S = calc(t-1, t, t + 1);
    if (S == (ll)S)
    printf("%d : %.10Lf\n", t, S);

  }
>>>>>>> 817eba630853489426811920a70a68f97e50f7d7
}
