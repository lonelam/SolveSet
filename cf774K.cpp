#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
char s[maxn];
set<char> vowel = {'a','e','i','o','u','y'};
int main()
{
    int n;
    cin >> n >> s;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (vowel.find(s[i]) != vowel.end())
        {
            if (s[i] == 'o' || s[i] == 'e')
            {
                if (c == 1 && s[i + 1] != s[i])
                {
                    cout << s[i];
                    c++;
                    continue;
                }
            }
            if (i && s[i - 1] != s[i])
            {
                c = 0;
            }
            if (!c) cout << s[i];
            c++;
        }
        else
        {
            c = 0;
            cout << s[i];
        }
    }
    cout << endl;
}
