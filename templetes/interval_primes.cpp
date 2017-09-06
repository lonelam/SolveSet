const int maxn = 1000000 + 10;
int primes[maxn];
int ptot;
bool nprime[maxn];
void intervalprime(int L, int U)
{
  int i, j;
  int SU = sqrt((double) U);
  int d = U - L + 1;
  for (int i = 0; i < d; i++) nprime[i] = 0;
  //去偶数，可删(改下面起始点为2, 步长为1)
  for (int i = (L % 2 != 0); i < d; i+= 2) nprime[i] = 1;

  for (int i = 3; i <= SU; i += 2)
  {
    if (i > L && nprime[i - L]) continue;
    j = (L / i) * i;
    if (j < L) j += i;
    j = j - L;
    for (; j < d; j += i) nprime[j] = 1;
  }
  if (L <= 1) nprime[1 - L] = 1;
  if (L <= 2) nprime[2 - L] = 0;
  ptot = 0;
  for (int i = 0; i < d; i++) if (!nprime[i]) primes[ptot++] = i + L;
}
