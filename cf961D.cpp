#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <random>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n;
int x[maxn], y[maxn];
int shufler[maxn];
bool vis[maxn];
// mt19937 rng_engine{randutils::auto_seed_128{}.base()};

int myrandom(int i){
  return ((rand() << 16) + rand()) % i;
}
bool check(){
  if (n <= 4){
    return true;
  }
  // memset(vis, 0, sizeof(vis));
  // vis[0] = vis[1] = true;
  vector<int> other;
  for (int i = 2; i < n; i++){
    if ((ll)(x[shufler[1]] - x[shufler[0]]) * (ll)(y[shufler[i]] - y[shufler[0]]) == (ll)(x[shufler[i] ]- x[shufler[0]]) * (ll)(y[shufler[1]] - y[shufler[0]])){
      // vis[i] = true;
    }
    else{
      other.push_back(shufler[i]);
    }
  }
  if (other.size() <= 2){
    return true;
  }
  for (int i = 2; i < other.size(); i++){
    if ((ll) (x[other[1]] - x[other[0]]) * (ll)(y[other[i]] - y[other[0]]) != (ll)(x[other[i]] - x[other[0]]) * (ll)(y[other[1]] - y[other[0]])){
      return false;
    }
  }
  return true;
}
int main(){
  srand(time(0));
  while(~scanf("%d", &n)){
    for (int i = 0; i < n; i++){
      scanf("%d%d", &x[i], &y[i]);
      shufler[i] = i;
      vis[i] = false;
    }
    bool ans = false;
    for (int k = 0; k < 100; k++){
      random_shuffle(shufler, shufler + n, myrandom );
      if (check()){
        ans = true;
        break;
      }
    }
    if (ans){
      printf("YES\n");
    }
    else{
      printf("NO\n");
    }

  }
}
