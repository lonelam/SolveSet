#include<iostream>
using namespace std;
typedef long long ll;
ll f[100];
int main()
{
    f[0] = 0;
    f[1] = 1;

    for(int i = 2; i < 70; i ++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    int n;
    while(cin >> n)
    {
        cout << f[n] << endl;
    }
}
