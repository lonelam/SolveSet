#include <iostream>
using namespace std;

int a[100], b[100];
int main()
{
    int alpha, beta;
    while(cin >> alpha >> beta)
    {
        int acnt = 0, bcnt = 0;
        while(alpha)
        {
            a[acnt++] = alpha % 10;
            alpha/=10;
        }
        while(beta)
        {
            b[bcnt++] = beta % 10;
            beta /= 10;
        }
        int ans = 0;
        for (int i = 0; i < acnt; i++)
        {
            for (int j = 0; j < bcnt; j++)
            {
                ans += a[i] * b[j];
            }
        }
        cout << ans << endl;
    }
}
