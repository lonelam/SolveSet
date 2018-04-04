#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int n, m;
int c[maxn];
int main(){
  while(cin >> n >> m){
    int tmp;
    for (int i = 0; i < m; i++)
    {
      cin >> tmp;
      c[tmp - 1] ++;
    }
    cout << *min_element(c, c + n) << endl;
  }
}
