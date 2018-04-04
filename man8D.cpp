#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int n;
vector<int> disc;
vector<pair<int,int> > A;
vector<set<pair<int,int> > > con;
int main(){
  while(~scanf("%d", &n)){
    for (int i = 0; i < n; i++){
      int ss, tt;
      scanf("%d%d", &ss, &tt);
      A.push_back(ss, tt);
      disc.push_back(ss);
      disc.push_back(tt);
    }
    sort(disc.begin(), disc.end());
    disc.erase(unique(disc.begin(), disc.end()), disc.end());
    for (int i = 0; i < n; i++){
      A[i].first = lower_bound(disc.begin(), disc.end(),A[i].first) - disc.begin();
      A[i].second = lower_bound(disc.begin(), disc.end(),A[i].second) - disc.begin();
    }
    for (int i = 1; i < disc.size(); i++){
      con.push_back(set<pair<int,int> >());
      for (int j = 0; j < n; j++){
        if (A[j].first <= i-1 && A[j].second >= i){
          con.rbegin()->insert(A[j]);
        }
      }
    }
    flg = false;
    do {
      int tmp = -1;
      for (int i = 1; i < disc.size(); i++){
        if (tmp == -1 || con[i-1].size() < con[tmp].size()){
          tmp = i-1;
        }
      }
      int L = 0;
      int R = inf;
      for (pair<int,int> p: con[tmp]){
        L = max(L, p.first);
        R = min(R, p.second);
      }
      for (int ll = tmp - 1; ll >= 0; ll--){

      }
      for (int i = 1; i < disc.size(); i++){
        if (con[i-1].size()){
          flg = true;
        }
      }
    } while(flg);
  }
}
