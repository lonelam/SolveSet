#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int gs[maxn];
int main(){
  for (int i = 1; i < maxn; i++){
    set<int> r;
    r.insert(gs[i - 1]);
    if (i >= 3){
      r.insert(gs[i - 3]);
    }
    if (i >= 7){
      r.insert(gs[i - 7]);
    }
    if (i >= 9){
      r.insert(gs[i - 9]);
    }
    for (int j = 0; j < 10;j++){
      if (r.find(j) == r.end()){
        gs[i] = j;
        break;
      }
    }
  }
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  printf("%s\n", (gs[n]^gs[m] ^ gs[k])?"win":"lose");
}
