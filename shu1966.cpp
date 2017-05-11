#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1 << 18;
#define _USE_MATH_DEFINES
const ld PI = M_PI;

complex<ld> as[maxn], bs[maxn], cs[maxn], ap[maxn], bp[maxn], cp[maxn];
complex<ld> dump[18][2][maxn / 2];

void FFT(complex<ld> A[],int d, int n, complex<ld> tar[])
{
  //cout <<"debug" << endl;
  if (n == 1)
  {
    tar[0] = A[0];
    return;
  }
  complex<ld> omega_n (cos(2 * PI / n), sin(2 * PI / n));
  complex<ld> omega = 1;
  auto tmp = dump[d];
  for (int i = 0; i < n / 2; i++)
  {
    tmp[0][i] = A[i << 1];
    tmp[1][i] = A[i << 1 | 1];
  }
  for (int i = 0; i < n / 2; i++)
  {
    A[i] = tmp[0][i];
    A[i + n / 2] = tmp[1][i];
  }
  FFT(A, d+1,n / 2, tmp[0]);
  FFT(A + n / 2, d+1,n / 2, tmp[1]);
  for (int i = 0; i < n / 2; i++)
  {
    tar[i] = tmp[0][i] + omega * tmp[1][i];
    tar[i + n / 2] = tmp[0][i] - omega * tmp[1][i];
    omega *= omega_n;
  }
}
void rFFT(complex<ld> * ys, int n, complex<ld> * ans, int d)
{
  if (n == 1)
  {
    ans[0] = ys[0];
    return;
  }
  auto tmp = dump[d];
  complex<ld> omega_n (cos(-2 * PI / n), sin(-2 * PI / n));
  complex<ld> omega = 1;
  for (int i = 0; i < n / 2; i++)
  {
    tmp[0][i] = ys[i << 1];
    tmp[1][i] = ys[i << 1 | 1];
  }
  for (int i = 0; i < n / 2; i++)
  {
    ys[i] = tmp[0][i];
    ys[i + n / 2] = tmp[1][i];
  }
  rFFT(ys, n / 2, tmp[0], d+1);
  rFFT(ys + n / 2, n / 2, tmp[1],d+1);
  for (int i = 0; i < n / 2; i++)
  {
    ans[i] = (tmp[0][i] + omega * tmp[1][i]);
    ans[i + n / 2] = tmp[0][i] - omega * tmp[1][i];
    omega *= omega_n;
  }
}
int main()
{
  int n;
  ld tmp;
  while(scanf("%d", &n) != EOF)
  {
    memset(as, 0, sizeof(as));
    memset(bs, 0, sizeof(bs));
    int up = 1;
    while(up < n)
    {
      up <<= 1;
    }
    for (int i = 0; i < n; i++)
    {
      scanf("%llf", &tmp);
      as[i].real(tmp);
    }
    for (int i = 0; i < n; i++)
    {
      scanf("%llf", &tmp);
      bs[i].real(tmp);
    }
    up <<= 1;
    FFT(as,0, up, ap);
    FFT(bs,0, up, bp);

    for (int i = 0; i < up; i++)
    {
      cp[i] = ap[i] * bp[i];
    }
    rFFT(cp, up, cs,0);
    printf("%d", (int)(round(cs[0].real()/up)));
    for (int i = 1; i < n; i++)
    {
      printf(" %d", (int)(round(cs[i].real()/up)));
    }
    printf("\n");
  }
}
