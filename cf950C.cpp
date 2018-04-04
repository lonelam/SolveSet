#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
char s[maxn];
int main(){
  while(~scanf("%s", s)){
    vector<vector<int>> chains;
    vector<int> tail0, tail1;
    int n = strlen(s);
    for (int i = 0; i < n; i++){
      if (s[i] == '0'){
        if (tail1.empty()){
          tail0.push_back(chains.size());
          chains.push_back(vector<int>({i}));
        }
        else{
          chains[tail1.back()].push_back(i);
          tail0.push_back(tail1.back());
          tail1.pop_back();
        }
      }
      else{
        if (tail0.empty()){
          printf("-1\n");
          return 0;
        }
        else{
          chains[tail0.back()].push_back(i);
          tail1.push_back(tail0.back());
          tail0.pop_back();
        }
      }
    }
    if (tail1.empty()){
      printf("%d\n", chains.size());
      for (int i = 0; i < chains.size(); i++)
      {
        printf("%d ", chains[i].size());
        for (int j = 0; j < chains[i].size(); j++){
          printf("%d%c", chains[i][j] + 1, j==(chains[i].size()-1)?'\n': ' ');
        }
      }
    }
    else{
      printf("-1\n");
    }
  }
}
