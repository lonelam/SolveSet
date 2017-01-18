#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000;
bool nprime[maxn];
void init()
{
    nprime[1] = true;
    for(int i = 2; i < maxn; i++)
    {
        if (!nprime[i])
        {
            for (int j = i + i; j < maxn; j+= i)
            {
                nprime[j] = true;
            }
        }
    }
}



int main()
{
    init();
    int n;
    cin >> n;
    for (int m = 1; m < maxn; m++)
    {
        if(nprime[n * m + 1])
        {
            cout << m << endl;
            return 0;
        }
    }
}
