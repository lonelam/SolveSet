#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int cl[maxn];
bool nprime[maxn];

void init()
{
    memset(nprime, 0, sizeof(nprime));
    for (int i = 2; i < maxn; i++)
    {
        if (!nprime[i])
        {
            for (int j = i + i; j < maxn; j += i)
            {
            //    cout << j << endl;
                nprime[j] = true;
            }
        }
    }
}
int paint(int n)
{
    int k = 1;
    memset(cl, 0, sizeof(cl));
    for (int i = 2; i <= n + 1; i++)
    {
        //cout <<"dge";
        if (cl[i] == 0)
        {
            cl[i] = 1;
            //cout << nprime[i] << endl;
            if (!nprime[i])
            {
                //cout <<"deg";
                for (int j = i+i; j <= n + 1; j += i)
                {
                    cl[j] = max(cl[j], cl[i] + 1);
                    k = max(k, cl[j]);
                }
            }
        }
    }
    return k;
}

int main()
{
    int n;
    init();
    while(cin >> n)
    {
        cout << paint(n) << endl;
        for (int i = 2; i <= n; i++)
        {
            cout << cl[i] <<" ";
        }
        cout << cl[n+1] << endl;
    }
}
