#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
#include <complex>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1 << 18;
typedef long long ll;
typedef double ld;
int n;
int bmask, blen;
const ld pi = M_PI;
void init()
{
	bmask = 1;
	blen = 1;
	while (bmask < n)
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
complex<ld> A[maxn], B[maxn], C[maxn];
void FFT(complex<ld> * alpha, int r = 1)
{
	for (int i = 0; i < bmask; i++)
	{
		int revi = bitrev(i);
		if (i < revi) swap(alpha[i], alpha[revi]);
	}
	for (int k = 2; k <= bmask; k <<= 1)
	{
		int h = k >> 1;
		complex<ld> omega_n(cos(2.0 * pi / k * r), sin(2.0 * pi / k * r));
		for (int i = 0; i < bmask; i += k)
		{
			int hi = h + i;
			complex<ld> omega(1,0);
			for (int j = i; j < hi; j++)
			{
				complex<ld> t = alpha[j + h] * omega;
				alpha[j + h] = alpha[j] - t;
				alpha[j] = alpha[j] + t;
				omega *= omega_n;
			}
		}
	}
	/*if (r == -1)
	{
		for (int i = 0; i < bmask; i++)
		{
			alpha[i] /= (ld)bmask;
		}
	}*/
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		init();
		int tmpin;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmpin);
			A[i].real(tmpin);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmpin);
			B[i].real(tmpin);
		}
		FFT(A);
		FFT(B);
		for (int i = 0; i < bmask; i++)
		{
			C[i] = A[i] * B[i];
		}
		FFT(C, -1);
		printf("%.0lf", round(C[0].real())/bmask);
		for (int i = 1; i < n; i++)
		{
			printf(" %.0lf", round(C[i].real())/bmask);
		}
		printf("\n");
	}
}