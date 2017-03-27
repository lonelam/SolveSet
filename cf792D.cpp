#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
char s[maxn];
int main()
{

    ll n,q;

    cin >> n >> q;
    //n++;
    int dep = log2(n+1);
    for (int k = 0; k < q; k++)
    {
        ll u;
        cin >> u;
        cin >> s;
        int len = strlen(s);
        int ucnt = 0;
    /*    for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] == 'U')
            {
                ucnt++;
            }
            else if (ucnt)
            {
                ucnt--;
                s[i] = 'U';
            }
        }*/
        ll mask = 1;
        int tmp = 0;
        while(((u >> tmp) & 1 )== 0)
        {
            tmp++;
            mask <<=1;
        }
        for (int i = 0; i < len ; i++)
        {
            if (s[i] == 'L' && mask > 1)
            {
                u -= (mask >>1);
                mask >>=1;
            }
            if (s[i] == 'R' && mask > 1)
            {
                u+= (mask >> 1);
                mask>>=1;
            }
            if (s[i] == 'U' && (mask >> (dep -1)) == 0)
            {
                mask<<=1;
                if (u & mask)
                {
                    u -= (mask >> 1);
                }
                else
                {
                    u += (mask >> 1);
                }
            }
        //    cout << u<< " "<<mask<<endl;
        }
        cout << u << endl;
    }
}
