#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n, m;
int r[maxn], c[maxn];
int t[9];
int border[maxn * 2][8];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while(cin >> n >> m){
    memset(t, 0, sizeof(t));
    for (int i = 0; i < maxn * 2; i++){
      for (int j = 0; j < 8; j++){
        border[i][j] = -1;
      }
    }
    for (int i = 0; i < m; i++){
      cin >> r[i] >> c[i];
      if (border[c[i]][0] == -1 || border[c[i]][0] > r[i]){
        border[c[i]][0] = r[i];
      }
      if (border[c[i]][1] == -1 || border[c[i]][1] < r[i]){
        border[c[i]][1] = r[i];
      }
      if (border[r[i]][2] == -1 || border[r[i]][2] > c[i]){
        border[r[i]][2] = c[i];
      }
      if (border[r[i]][3] == -1 || border[r[i]][3] < c[i]){
        border[r[i]][3] = c[i];
      }
      if (border[r[i] - c[i] + maxn][4] == -1 || border[r[i] - c[i] + maxn][4] > r[i] + c[i]){
        border[r[i] - c[i] + maxn][4] = r[i] + c[i];
      }
      if (border[r[i] + c[i]][5] == -1 || border[r[i] + c[i]][5] > r[i] - c[i] + maxn){
        border[r[i] + c[i]][5]  = r[i] - c[i] + maxn;
      }
      if (border[r[i] + c[i]][6] == -1 || border[r[i] + c[i]][6] < r[i] - c[i] + maxn){
        border[r[i] + c[i]][6]  = r[i] - c[i] + maxn;
      }
      if (border[r[i] - c[i] + maxn][7] == -1 || border[r[i] - c[i] + maxn][7] < r[i] + c[i]){
        border[r[i] - c[i] + maxn][7] = r[i] + c[i];
      }
    }
    for (int i = 0; i < m; i++){
      int a = 0;
      if (border[c[i]][0] < r[i]){
        a++;
      }
      if (border[c[i]][1] > r[i]){
        a++;
      }
      if (border[r[i]][2] < c[i]){
        a++;
      }
      if (border[r[i]][3] > c[i]){
        a++;
      }
      if ( border[r[i] - c[i] + maxn][4] < r[i] + c[i]){
        a++;
      }
      if (border[r[i] + c[i]][5] < r[i] - c[i] + maxn){
        a++;
      }
      if (border[r[i] + c[i]][6] > r[i] - c[i] + maxn){
        a++;
      }
      if (border[r[i] - c[i] + maxn][7] > r[i] + c[i]){
        a++;
      }
      t[a]++;
    }
    for (int i= 0; i < 9; i++){
      cout << t[i] << (i==8?'\n':' ');
    }
  }
}
