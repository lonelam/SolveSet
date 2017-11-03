#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
string f[] = {"Danil", "Olya", "Slava", "Ann" , "Nikita"};
string s;
int main()
{
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < 5; i++)
  {
    if (s.find(f[i]) == string::npos) continue;
    // cout << s.find_last_of(f[i]) << endl;
    // cout << s.find_first_of(f[i]) << endl;
    if (s.rfind(f[i]) != (s.find(f[i])))
    {
      cnt += 2;
    }
    else
    {
      cnt++;
    }
  }
 // cout << cnt << endl;
  if (cnt == 1)
  {
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
}
