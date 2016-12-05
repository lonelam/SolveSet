#include<iostream>
using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int t;

    int n, m;
    int kase = 1;
    while(cin >> n >> m)
    {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(gcd(i, m) == 1)
            {
                cnt++;
            }
        }
        cout <<"Case "<<kase++<<": "<< cnt << endl;
    }
}
