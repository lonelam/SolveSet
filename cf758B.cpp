#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
    map<int, int> cnt;
    map<char, int> cl;
    string line;
    while(cin >> line)
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == '!')
            {
                cnt[i % 4]++;
            }
            else
            {
                cl[line[i]] = i % 4;
            }
        }
        cout << cnt[cl['R']] <<" "<< cnt[cl['B']] <<" "<< cnt[cl['Y']] <<" "<<cnt[cl['G']] <<endl;
    }
}
