#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n;
char grid[4][maxn][maxn];
int main(){
  while(~scanf("%d", &n)){
    for (int g = 0; g < 4; g++){
      for (int i = 0; i < n; i++){
        scanf("%s", grid[g][i]);
        for (int j = 0; j < n; j++){
          grid[g][i][j] -= '0';
        }
      }
    }
    int ans = inf;
    for (int f = 0; f < 2; f++){
      for (int g = 1; g < 4; g++){
        int cnt = 0;
        for (int h = 0; h < 4; h++){
          for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
              if (h == 0 || h == g){
                cnt += grid[h][i][j] ^ f ^((i + j) & 1);
              }
              else{
                cnt += grid[h][i][j] ^ f ^ ((i + j) & 1) ^ 1;
              }
            }
          }
        }
        ans = min(ans, cnt);
      }
    }
    printf("%d\n", ans);
  }
}
