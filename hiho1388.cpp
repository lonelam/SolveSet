#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1 << 19;
typedef complex<ld> cd;
int n, bmask, blen;
const double pi = M_PI;

void init()
{
  bmask = 1;
  blen = 1;
  while(bmask < n)
  {
    ++blen;
    bmask <<= 1;
  }
  bmask <<= 1;
}

inline int bitrev(int x)
{
  int r = 0;
  for (int i = 0; i < blen; i++)
  {
    r <<= 1;
    r |= x & 1;
    x >>= 1;
  }
  return r;
}

cd A[maxn], B[maxn], C[maxn];
void FFT(cd * alpha, int r = 1)
{
  for (int i = 0; i < bmask; i++)
  {
    int revi = bitrev(i);
    if (i < revi) swap(alpha[i], alpha[revi]);
  }
  for (int k = 2; k <= bmask; k <<= 1)
  {
    int h = k >> 1;
    cd omega_n(cos(pi / h * r), sin(pi / h * r));
    for (int i = 0; i < bmask; i+= k)
    {
      cd omega = 1;
      for (int j = i; j < h + i; j++)
      {
        cd t = alpha[j + h] * omega;
        alpha[j + h] = alpha[j] - t;
        alpha[j] = alpha[j] + t;
        omega *= omega_n;
      }
    }
  }
  if (r == -1)
  {
    for (int i = 0; i < bmask; i++)
    {
      alpha[i] /= bmask;
    }
  }
}
int T, tmp;
int main()
{
  while (scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d", &n);
      ll ceiling = 0;
      memset(A, 0, sizeof(A));
      memset(B, 0, sizeof(B));
      for (int i = 0; i < n; i++)
      {
        scanf("%d", &tmp);
        A[i].real(tmp);
        ceiling += tmp * tmp;
      }
      reverse(A, A + n);
      for (int i = 0; i < n; i++)
      {
        scanf("%d", &tmp);
        B[i].real(tmp);
        ceiling += tmp * tmp;
        B[n + i].real(tmp);
      }
      n *= 2;
      init();
      FFT(A);
      FFT(B);
      for (int i= 0; i < bmask; i++)
      {
        C[i] = A[i] * B[i];
      }
      FFT(C, -1);
      ld halffloor = 0;
      /*for (int i = 0; i < bmask; i++)
      {
        cout << C[i].real() <<" ";
      }
      cout << endl;*/
      int memans = 0;
      for (int i = n / 2; i < n; i++)
      {
        if (C[i].real() > C[memans].real())
        {
          memans = i;
        }
      }
      printf("%.0llf\n", round(ceiling - halffloor * 2));
    }
  }
}
