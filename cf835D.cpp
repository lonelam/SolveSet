#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include <iostream>
#include<ctime>
#include<set>
#include<vector>
using namespace std;
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef long long ll;
const int MAXN = 10010;
int palinlen[MAXN];
//ll gao[MAXN];
struct{
    ll BL,BR,ML,MR;
    unsigned long long psl[MAXN],psr[MAXN];
    char str[MAXN];
    unsigned long long hs[MAXN];
    void Hash2(int n){
        for(int i = 0; i <= n ; i ++){
            psl[i] = (i == 0 ? 1 : psl[i - 1] * BL) % ML;
        }
        for(int i = 0 ; i <= n; i ++){
            psr[i] = (i == 0 ? 1 : psr[i - 1] * BR) % MR;
        }
    }
    void build(){
        int n = strlen(str);
        long long l = 0, r = 0;
        for(int i = 0 ; i < n ; i ++){
            l = (l * BL + str[i]) % ML;
            r = (r * BR + str[i]) % MR;
            if(l < 0) l+= ML;
            if(r < 0)r += MR;
            hs[i + 1] = (l << 32) | r;
        }
    }
    long long get(int b,int e){
        unsigned long long el = (hs[e] >>32);
        unsigned long long er = (hs[e] & 0xffffffffULL);
        unsigned long long bl = (hs[b] >> 32);
        unsigned long long br = (hs[b] & 0xffffffffULL);
        long long l = el - bl * psl[e-b] % ML;
        long long r = er - br *psr[e-b] % MR;
        if(l < 0) l += ML;
        if(r < 0) r += MR;
        return (l << 32) | r;

    }
    void init(){
        int maxx = 1e9;
        srand(time(0));
        BL = (ll)maxx + rand() % maxx;
        BR = (ll)maxx + rand() % maxx;
        ML = (ll)maxx + rand() % maxx;
        MR = (ll)maxx + rand() % maxx;
    }
}Hash;
int ans[MAXN];
int mem[MAXN/2][MAXN/2];
int dp(int b, int e)
{
  if (mem[b][e] != -1)
  {
    return mem[b][e];
  }
  if (b >= e)
  {
    return mem[b][e] = 0;
  }
  if (b + 1 == e)
  {
    return mem[b][e] = 1;
  }
  const int sum = b + e;
  const int half = (e-b)/2;

  if ( palinlen[sum] < half)
  {
    return mem[b][e] = 0;
  }
  if (Hash.get(b, half + b) != Hash.get(e - half, e)) return mem[b][e] = 1;
  return mem[b][e] = dp(b, b + half) + 1;
}
int main()
{
  memset(mem,-1,sizeof(mem));
  scanf("%s", Hash.str);
  int n = strlen(Hash.str);
  Hash.init();
  Hash.Hash2(n);
  Hash.build();
  for (int i = 0; i < n; i++)
  {
    int odd = i << 1 | 1;
    while(i + palinlen[odd] < n && i - palinlen[odd] >= 0 && Hash.str[i + palinlen[odd]] == Hash.str[i - palinlen[odd]])
    {
      palinlen[odd]++;
    }
    palinlen[odd]--;
    int even = i << 1;
    while(i + palinlen[even] < n && i - palinlen[even] - 1 >= 0 && Hash.str[i + palinlen[even]] == Hash.str[i - palinlen[even] - 1])
    {
      palinlen[even]++;
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = i+1; j <= n; j++)
    {
      int ki = dp(i, j);
      // cout << i << " "<< j << " "<< ki << endl;
      ans[ki]++;
    }
  }
  for (int i = n - 1; i >= 1; i--)
  {
    ans[i] += ans[i+1];
  }
  for (int i = 1; i <= n; i++)
  {
    printf("%d%c" ,ans[i],i==n?'\n':' ');
  }
}
