#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int d[maxn];
char s[maxn];
int n, k;
int px[maxn];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while(cin >> n >> k){
    cin >> s;
    for (int i = 0; i < n; i++)
      d[i] = s[i] - '0';
    int x = 0;
    for (int i = 0; i < k; i++){
      while (x + 1 < n){
        if (d[x] == 4 && d[x+1] == 7){
          break;
        }
        x++;
      }
      if (x == n - 1){
        break;
      }
      if (i >= 2 && x == px[i - 2] && (i & 1) == (k & 1)){
        break;
      }
      px[i] = x;
      if (x & 1){
        d[x] = d[x+1] = 7;
        x--;
      }
      else{
        d[x] = d[x+1] = 4;
        x++;
      }
    }
    for (int i = 0; i < n; i++){
      cout << d[i];
    }
    cout << endl;
  }
}
