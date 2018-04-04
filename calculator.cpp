#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int main(){
  vector<int> x = {1,2,3,4,5,6,7,8,9,10,11};
  for (int i = 0; i < 23415; i++) next_permutation(x.begin(), x.end());
  for (int i = 0; i < 11; i++) cout << x[i] << " ";
}
