#include<iostream>
using namespace std;
typedef long long ll;

ll n, k;

int main()
{
    while(cin >> n >> k)
    {
        if (k <= 0)
        {
            cout << 1 <<endl;
            continue;
        }
        n %= 10;
        k = k % 4 + 4;
        ll digit_n = n;
        for (int i = 1; i < k; i++)
        {
            n *= digit_n;
        }
        cout << n % 10 <<endl;
    }
}
