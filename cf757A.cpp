#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
string bul = "Bulbasaur";
int main()
{
    string s;
    cin >> s;
    map<char, int> Bmap;
    map<char, int> Pmap;
    for (int i = 0; i < bul.size(); i++)
    {
        Bmap[bul[i]]++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        Pmap[s[i]]++;
    }
    int ans = inf;
    for (pair<char, int> dig : Bmap)
    {
        ans = min(Pmap[dig.first] / dig.second, ans);
    }
    cout << ans << endl;
}
