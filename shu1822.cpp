#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int twos[33000];
int fifs[33000];
int main()
{
    for (int i = 1;i < 32800; i ++)
    {
        twos[i] = twos[i - 1];
        fifs[i] = fifs[i - 1];
        int b = i;
        while(b % 2 == 0)
        {
            b /= 2;
            twos[i]++;
        }
        int f = i;
        while(f % 5 == 0)
        {
            f /= 5;
            fifs[i]++;
        }
    }
    int kase = 1;
    int n;
    while(cin >> n)
    {
        cout << "Case "<<kase++<<":"<<n << ","<< min(twos[n],fifs[n])<<endl;
    }
}
