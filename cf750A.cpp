#include <iostream>
using namespace std;
int main()
{
    int n, k;
    while(cin >> n >> k)
    {
        k = 240 - k;
        int cnt = 0;
        for (int i = 1; k && i<= n; i++)
        {
            k -= i * 5;
            if (k>=0)
            cnt++;
        }
        cout << cnt << endl;
    }
}
