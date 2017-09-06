#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const double eps = 1e-4;
ld gcd(ld a, ld b)
{
  if (a < b) swap(a, b);
  if (fabs(b) < eps)
  {
    return a;
  }
  return gcd(b, a - floor(a / b) * b);
}
int main()
{
  ld x[3], y[3];
  for (int i = 0; i < 3; i++)
  {
    cin >> x[i] >> y[i];
  }
  ld L[3];
  for (int i = 0; i < 3; i++)
  {
    L[i] = sqrt((x[i] - x[(i+1) % 3]) * (x[i] - x[(i+1) % 3]) + (y[i] - y[(i+1) % 3]) * (y[i] - y[(i+1) % 3]));
  }
  ld A[3];
  for (int i = 0; i < 3; i++)
  {
    A[i] = acos((L[i] * L[i] + L[(i+1) % 3] * L[(i+1) % 3] - L[(i+2)%3] * L[(i+2) % 3]) / (2 * L[i] * L[(i+1) % 3]));
    // cout << A[i] << endl;
  }
  ld alpha = 2 * gcd(A[0], gcd(A[1], A[2]));
  // cout << alpha / M_PI * 180 << endl;
  ld n = round( 2 * M_PI / alpha);
  // cout << n << endl;
  ld dy1 = y[2] - y[0], dy2 = y[1] - y[0], dx1 = x[2] - x[0], dx2 = x[1] - x[0];
  ld S = abs(dy1 * dx2 - dy2 * dx1) / 2.0;
  // cout << S << endl;
  ld R = (L[0] * L[1] * L[2]) / 4 / S;
  // cout << R << endl;
  ld ans = n * R * R * sin(2.0 * M_PI / n) / 2.0;
  // cout << ans << endl;
  cout.setf(ios::fixed);
  cout.precision(10);
  cout << ans << endl;

}
