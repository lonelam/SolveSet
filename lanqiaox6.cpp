#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int a[] = {
  258055 ,69760, 163908, 249856, 53440,

151684, 77958, 176134, 8262, 229446,

245953, 20676, 45189, 69826, 131075,

28672, 155717, 118851, 221318, 254150,

135235, 86083, 41089, 28743, 32772,

225475, 118855, 249862, 184320, 217154
};
int main(){
  int ans = 0;

  for (int st = 0; st < (1 << 30); st++){
    int tmp = 0;
    for (int i = 0; i < 30; i++){
      if (st >> i & 1){
        tmp ^= a[i];
      }
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
