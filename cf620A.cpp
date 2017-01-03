#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c, d;
  while(cin >> a >> b >> c >> d)
  {
    cout << max(abs(a - c), abs(b - d))<<endl;
  }
}
