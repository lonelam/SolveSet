#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;

bool rev[maxn * 2];
int pre[maxn* 2], ch[maxn* 2][2];
int key[maxn * 2];
int n;
int ans[maxn * 2];
int et;
int sum[maxn * 2];

void init()
{
    et = maxn + 1;
    ans[1] = 0;
    for (int i = 2; i < maxn; i++)
    {
        int q = 2;
        for (; q * q <= i; q++)
        {
            if (i % q == 0) break;
        }
        int tar;
        if (i % q == 0)
            tar = i / q;
        else
            tar = 1;
        ans[i] = ans[i - 1] + tar;
    }
}
int main()
{
    init();
    while(cin >> n)
    {
        cout << ans[n] << endl;
    }
}
