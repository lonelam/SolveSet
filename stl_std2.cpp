#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
    vector<string> input;
    vector<string> disc;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      string tmp;
      cin >> tmp;
      input.push_back(tmp);
      disc.push_back(tmp);
    }
    sort(disc.begin(), disc.end());
    for (int i = 0; i < n; i++)
    {
      cout << (lower_bound(disc.begin(), disc.end(), input[i]) - disc.begin() + 1) << endl;
    }
}
