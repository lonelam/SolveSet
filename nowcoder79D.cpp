#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 10;
const ll moder = 1e9 + 7;
int n, m, C;
int x[maxn], y[maxn];
vector<int> xs, ys;

ll dp[2][maxn];

ll c[maxn];

ll cc[maxn];
int inline lsb(int x){
  return x & (-x);
}
void add(int x, ll a){
  c[x] = (c[x] + a) % moder;
  x++;
  while(x < maxn){
    cc[x] = (cc[x] + a + moder) % moder;
    x += lsb(x);
  }
}

ll query(int x, ll a){
  ll ret = 0;
  while(x){
    ret = (ret + cc[x]) % moder;
    x -= lsb(x);
  }
  return ret;
}

ll inline gao(ll nn, ll mm){
  return (nn * (nn + 1) / 2LL) % moder  * ((mm * (mm + 1) / 2LL) % moder);
}

int main(){
  while(~scanf("%d%d%d", &n, &m, &C)){
    set<pair<int, int> > ones;
    for (int i = 0; i < C; i++){
      scanf("%d%d", x + i, y + i);
      ones.insert(x[i], y[i]);
      xs.push_back(x[i]);
      ys.push_back(y[i]);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int tmp = xs.size();
    if (*xs.begin() != 1) xs.push_back(1);
    if(*xs.rbegin() != n) xs.push_back(n + 1);
    for (int i = 0; i < tmp; i++){
      xs.push_back(xs[i]);
    }
    sort(xs.begin(), xs.end());
    tmp = ys.size();
    if (*ys.begin() != 1) ys.push_back(1);
    if(*ys.rbegin() != m) ys.push_back(m + 1);
    for (int i = 0; i < tmp; i++){
      ys.push_back(ys[i]);
    }
    sort(ys.begin(), ys.end());


  }
}
