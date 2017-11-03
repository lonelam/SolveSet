#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
vector<int> arr;
int main()
{
  string s;
  int kase = 1;
  while(getline(cin, s))
  {
    stringstream ss(s);
    int tmp;
    while(ss >> tmp)
    {
      arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    cout << "Case " << kase++ << ": ";
    for (int i = arr.size() - 1, j = 0; i>=0 && j < 10; i--,j++)
    {
      if (j)
      {
        cout << ", ";
      }
      cout << arr[i];
    }
    cout << endl;
  }
}
