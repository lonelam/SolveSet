#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

int main()
{
    cin.get();
    ld sum = 0;
    for (int i = 1; i < 100; i++)
    {

        cout << (sum += floor((ld)i * sqrt((ld)2))) <<", ";
    }
}
