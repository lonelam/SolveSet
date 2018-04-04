#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
string s;
int main(){
  while(cin >> s){
    int tar = 0;
    string x = "";
    map<string, int> cnt;
    int n = s.length();
    for (int i = 0; i < n; i++){
      for (int j = i + 1; j <= n; j++){
        if (s[j-1] != '4' && s[j-1] != '7'){
          break;
        }
        cnt[s.substr(i, j - i)]++;
      }
    }
    for (pair<string, int> p: cnt){
      if (p.second > tar){
        x = p.first;
        tar = p.second;
      }
    }
    if (tar == 0) cout << -1 << endl;
    else cout << x << endl;
  }
}
