#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll moder = 1e9 + 7;
ll pow_mod(ll n)
{
  if (n == 0) return 1;
  if (n == 1) return 3;
  ll half = pow_mod(n / 2);
  if (n & 1) return (half * half * 3) % moder;
  return (half * half) % moder ;
}

ll towerColoring(ll n){
    // Complete this function
    moder = 1e9 + 6;
    ll up = pow_mod(n);
    moder = 1e9 + 7;
    return pow_mod(up);
}

int main() {
    int n;
    cin >> n;
    int result = towerColoring(n);
    cout << result << endl;
    return 0;
}
