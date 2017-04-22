#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
    int n;
    int T, typ;
    while(cin >> T)
    {
        while(T--)
        {
            cin >> n;
            int ko = 0, to = 0;
            for (int i = 0; i < n; i++)
            {
                cin >> typ;
                if (typ == 1)
                {
                    ko += 1;
                }
                else if (typ == 2)
                {
                    to += 1;
                }
            }
            if (ko > to)
            {
                cout << "Kobayashi" << endl;
            }
            else if (ko == to)
            {
                cout << "Draw" << endl;
            }
            else{
                cout <<"Tohru" << endl;
            }
        }
    }
}
