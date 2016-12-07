#include<iostream>
using namespace std;
typedef long long ll;
bool isprime(ll x)
{
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ll n;
    while(cin >> n)
    {

        if (isprime(n))
            cout << 1 <<endl;
        else if ((n % 2 == 0) || (n & 1 && isprime(n - 2)))
        {
            cout << 2 <<endl;
        }
        else
        {
            cout << 3 <<endl;
        }
    }
}
