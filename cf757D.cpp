
#include <bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define TR(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define TR(...)
#endif

typedef long long                LL;
typedef vector < int >           VI;
typedef pair < int,int >         II;
typedef vector < II >            VII;

#define MOD                      1000000007
#define EPS                      1e-12
#define N                        200100
#define PB                       push_back
#define MP                       make_pair
#define F                        first
#define S                        second
#define ALL(v)                   v.begin(),v.end()
#define SZ(a)                    (int)a.size()
#define FILL(a,b)                memset(a,b,sizeof(a))
#define SI(n)                    scanf("%d",&n)
#define SLL(n)                   scanf("%lld",&n)
#define PLLN(n)                  printf("%lld\n",n)
#define PIN(n)                   printf("%d\n",n)
#define REP(i,j,n)               for(LL i=j;i<n;i++)
#define PER(i,j,n)               for(LL i=n-1;i>=j;i--)
#define endl                     '\n'
#define fast_io                  ios_base::sync_with_stdio(false);cin.tie(NULL)

#define FILEIO(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);

inline int mult(int a , int b) { LL x = a; x *= LL(b); if(x >= MOD) x %= MOD; return x; }
inline int add(int a , int b) { return a + b >= MOD ? a + b - MOD : a + b; }
inline int sub(int a , int b) { return a - b < 0 ? MOD - b + a : a - b; }
LL powmod(LL a,LL b) { if(b==0)return 1; LL x=powmod(a,b/2); LL y=(x*x)%MOD; if(b%2) return (a*y)%MOD; return y%MOD; }

int dp[1<<20][77];
int b[77] , n;
int go(int mask , int i) {
  int cnt = __builtin_popcount(mask);
  if(i == n) {
    if(cnt != 0 && (1<<cnt)-1 == mask)
      return 1;
    return 0;
  }
  if(dp[mask][i] != -1) return dp[mask][i];

  int ret = 0;
  if(b[i] == 0)
    ret = go(mask , i+1);
  else {
    int num = 0;
    int j = i;
    while(1) {
      num *= 2;
      num += b[j];
      if(num > 20) break;
      //if(!(mask & (1<<(num-1))))
      ret = add(ret , go(mask | (1<<(num-1)) , j+1));
      j ++;
      if(j == n) break;
    }
    if(cnt != 0 && mask == (1<<cnt)-1)
      ret ++;
  }
  return dp[mask][i] = ret;
}

int main() {
  FILL(dp,-1);
  cin >> n;
  string s; cin >> s;
  REP(i,0,n)
    b[i] = s[i] - '0';
  int ans = 0;
  REP(i,0,n)
    ans = add(ans , go(0,i));
  PIN(ans);
  return 0;
}
