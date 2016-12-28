/*************************************************************************
	> File Name: cf611B.cpp
	> Author: Lonelam
	> Mail: laizenan@gmail.com
	> Created Time: 2016年12月28日 星期三 18时19分42秒
 ************************************************************************/

#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<iomanip>
#include<sstream>
#include<utility>
#include<functional>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#include<iostream>
const int inf = 0x3f3f3f3f;
ll p(ll x)
{
    ll rx = x;
    int hd = 0;
    while(rx)
    {
        hd++;
        rx >>= 1;
    }
    int zd = 0;
    for (int i = hd - 1; i >= 0; i--)
    {
        if (x >> i & 1)
        {
            continue;
        }
            zd = i;
        break;
    }
    ll cnt = 1 + (hd - 2) * (hd - 1) / 2;
    cnt += (hd - 2 - zd);
    for (int i = zd - 1; i >= 0; i--)
    {
        if (x >> i & 1)
        {
            continue;
        }
        return cnt;
    }
    return cnt + 1;
}
int main()
{
    ll a , b;
    while(cin >> a>> b)
    {
        cout << p(b) - p(a - 1) << endl;
    }
}
