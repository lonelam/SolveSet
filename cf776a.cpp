#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

int main()
{
    string a, b;
    int n;
    while(cin >> a >> b)
    {
        cin >> n;
        string killed, vicnew;
        cout << a <<" "<< b << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> killed >> vicnew;
            if (a !=killed) swap(a,b);
            a = vicnew;
            cout << a <<" "<<b <<endl;
        }
    }
}
