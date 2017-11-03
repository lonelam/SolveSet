#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
string line;
bool isword(int cur)
{
  if (cur >= line.size() ) return false;
  if (isupper(line[cur]))
  {
    if (!isalpha(line[cur+1])) return false;
    for (int i = cur + 1; i < line.size() && isalpha(line[i]); i++)
    {
      if (isupper(line[i])) return false;
    }
    return true;
  }
  return false;
}
int main()
{
  while(getline(cin, line))
  {
    string abbr, buf, ans;
    for (int i = 0; i < line.size();)
    {
      if (isword(i))
      {
        abbr.push_back(line[i]);
        while(i < line.size() && isalpha(line[i])) buf.push_back(line[i++]);
        if (i == line.size() || line[i] != ' ' || line[i] == ' ' && !isword(i+1))
        {
          if (abbr.size() > 1)
          {
            //ans += " ";
            ans += abbr;
            ans += " (";
            ans += buf;
            ans += ")";
          }
          else
          {
            ans += buf;
          }
          abbr = "";
          buf = "";
          ans.push_back(line[i++]);
        }
        else
        {
          buf.push_back(line[i++]);
        }
      }
      else
      {
        while(i < line.size() && isalpha(line[i])) buf.push_back(line[i++]);
        buf.push_back(line[i++]);
        ans += buf;
        buf = "";
        abbr = "";
      }
    }
    ans += buf;
    buf = "";
    cout << ans << endl;
  }
}
