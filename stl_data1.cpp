/*
ACMer空间是一个很大的二维空间，被划分成$1\mul 1$的小格子，每一个格子中可以堆叠放置若干道算法题，每道算法题都用id来标注。
你的任务是对每个输入，回答每一个位置上id为第k[i]大的算法题

*/
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
  for (int i = 1; i <= 1; i++)
  {
    string fext = ".in";
    string fname(1, '0' + i);
    string ffull = fname + fext;
    freopen(ffull.c_str(), "w", stdout);
    random_device rd;
    uniform_int_distribution<int> xyrand(-10000000, 10000000);
    uniform_int_distribution<int> idrand(0, 10000000);
    map<pair<int, int>, vector<int> > mp;
    cout << 500000 << endl;
    for (int i = 0; i < 500000; i++)
    {
      int x = xyrand(rd) ;
      int id = idrand(rd);
      int y = xyrand(rd);
      x = -1;
      y=-1;
      cout << id << " "<< x << " "<< y << endl;
      mp[{x,y}].push_back(id);
    }
    vector<pair<int,int>> v;
    for (auto pp:mp)
    {
      v.push_back(pp.first);
    }
    cout << 100000 << endl;
    for (int i = 0; i < 100000; i++)
    {
      uniform_int_distribution<int> indexrand(0, v.size() - 1);
      int ind = indexrand(rd);
      uniform_int_distribution<int> posrand(0, mp[v[ind]].size() - 1);
      cout << v[ind].first << " "<< v[ind].second <<" "<<posrand(rd) +1<< endl;
    }
  }
}
