#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
typedef long double ld;
int main()
{
    int T;
    while(cin >> T)
    {
        ld latitude = 0, gatituge = 0;
        ld len;
        string cmd;
        while(T--)
        {
            cin >> len >> cmd;
            if (latitude == 0 && cmd != "South" ||
            latitude == 20000 && cmd != "North" ||
            latitude > 20000 || latitude < 0)
            {
                cout << "NO\n";
                return 0;
            }
            if (cmd == "South")
            {
                latitude += len;
            }
            else if (cmd == "North")
            {
                latitude -= len;
            }
            if (latitude > 20000 || latitude < 0)
            {
                cout << "NO\n";
                return 0;
            }

        }
        if (latitude == 0)
        {
            cout << "YES\n";
        }
        else
        cout << "NO\n";
    }
	return 0;
}
