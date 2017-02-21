#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

ll a[maxn];
ll b[maxn];
ll w;
ll c[maxn];
ll bvis[maxn];
ll x;

int solve()
{
    if(!(cin >> a[0] >> b[0] >> w >> x >> c[0]))return -1;
    if (a[0] >= c[0])
    {
        cout << 0 << endl;
        return 0;
    }
    memset(bvis, -1, sizeof(bvis));
    bvis[b[0]] = 0;
    ll suba, circ;
    for (int i = 1; ; i++)
    {
        c[i] = c[i - 1] - 1;
        if (b[i - 1] < x)
        {
            b[i] = w - (x - b[i - 1]);
            a[i] = a[i - 1] - 1;
        }
        else
        {
            a[i] = a[i - 1];
            b[i] = b[i - 1] - x;
        }
    //    cout << a[i] <<" "<< b[i] <<" " << c[i] << endl;
        if (a[i] >= c[i])
        {
            cout << i << endl;
            return 0;
        }
        if (bvis[b[i]]!= -1)
        {
            circ = i - bvis[b[i]];
            suba =  a[bvis[b[i]]] - a[i];
            break;
        }
        else
        {
            bvis[b[i]] = i;
        }
    }
    ll cn = (c[0] - a[0]) / (circ - suba);
    if (cn > 0)
    {
        cn--;
    }
    a[0] -= suba * cn;
    c[0] -= circ * cn;
//    cout << cn <<" "<< circ <<" "<<a[0]<<" "<< c[0]<<endl;
    if (a[0] >= c[0])
    {
        cout << cn * circ << endl;
        return 0;
    }
    for (int  i = 1; ; i++)
    {
        c[i] = c[i - 1] - 1;
        if (b[i-1] < x)
        {
            b[i] = w - (x - b[i - 1]);
            a[i] = a[i - 1] - 1;
        }
        else
        {
            b[i] = b[i - 1] - x;
            a[i] = a[i - 1];
        }
        if (a[i] >= c[i])
        {
            cout << i + cn * circ << endl;
            return 0;
        }
    }
    return 0;
}
int main()
{
    while(solve()!=-1);
}
