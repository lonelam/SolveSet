#include <iostream>
using namespace std;

int ds[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{

    int n, d;
    cin >> n >> d;
   // if (d == 7) d = 0;
    int ans = 1;
    int dd = ds[n] - (8-d);
    ans += dd / 7;
    if (dd % 7) ans ++;
    cout << ans << endl;
}
