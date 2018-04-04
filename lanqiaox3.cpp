#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll a[] = {9, 8, 9, 9, 5, 7, 4, 2, 2, 4, 5, 6, 7, 8, 9, 3, 3, 4, 5, 1};
map<pair<int,int>, ll> mem;
ll dfs(int L = 0, int R = 20){
  if (L == R){
     return 1;
  }
  if (L + 1 == R){
    return a[L];
  }
  if (mem.find({L, R}) != mem.end()){
    return mem[{L, R}];
  }
  ll ret = 0;
  for (int i = L; i < R; i++){
    ret = max(ret, dfs(L, i) * dfs(i + 1, R) + a[i]);
  }
  return mem[{L, R}] = ret;
}
int main(){
  cout << dfs() << endl;
}
