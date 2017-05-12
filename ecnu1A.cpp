#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
string line;
string alpha = u8"ā";
string grid[5][10] = { {u8"a",u8"e",u8"i",u8"o",u8"u",u8"ü"}, {u8"ā", u8"ē", u8"ī",u8"ō",u8"ū", u8"ǖ"}, {u8"á",u8"é",u8"í",u8"ó",u8"ú",u8"ǘ"},
 {u8"ǎ",u8"ě",u8"ǐ",u8"ǒ",u8"ǔ",u8"ǚ"}, {u8"à",u8"è",u8"ì",u8"ò", u8"ù", u8"ǜ"}};
string prior = "aoeiuv";
int pro[] = {0, 3, 1, 2, 4, 5};
int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  {
    int kase = 1;
    while(T--)
    {
      cin >> line;
      int len = line.size();
      int tp;
      if (!isdigit(line[len - 1]))
      {
        tp = 0;
      }
      else
      {
        tp = line[len - 1] - '0';
      }
      int tip = -1, tar = -1;
      for (int i = 0; i < prior.size(); i++)
      {
        if (line.find(prior[i])!=string::npos)
        {
          tar = line.find(prior[i]);
          tip = pro[i];
          break;
        }
      }
      for (int i = 1; i < len; i++)
      {
        if (line[i] == 'u' && line[i - 1] == 'i')
        {
          tar = i;
          tip = 4;
        }
      }
      cout <<"Case "<<kase++<<": " ;
      int endd = line.size();
      if (tp) endd--;
      for (int i = 0; i < endd; i++)
      {
        if (i == tar) cout << grid[tp][tip];
        else if (line[i] == 'v')
        {
          cout << grid[0][5];
        }
        else
        {
          cout << line[i];
        }
      }
      cout << endl;
    }
  }
}
