#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n, m;
int main(){
  cin >> n >> m;
  if (n == 1){
    cout << m << endl;
  }
  else if (m == 1){
    cout << n << endl;
  }
  else if (n == 2 && m == 2){
    cout << 4 << endl;
  }
  else
  cout << (n / 2) * (m / 2) + ((n + 1) / 2) * ( (m + 1) / 2) << endl;
}
