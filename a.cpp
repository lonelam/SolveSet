#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
const int goal = 437338199;
const int maxn = 100000;
bool nprime[maxn] = {true, true};
void init()
{
    memset(nprime, 0, sizeof(nprime));
    nprime[0] = nprime[1] = true;
    for (int i = 2; i < maxn; i++)
    {
        if (!nprime[i])
        {
          //  cout << "debug\n";
            for (int j = i + i; j < maxn; j += i)
            {
                nprime[j] = true;
            }
        }
    }
//    cout << "debug\n";
}
void test()
{
    for (int i = 0; i < maxn; i++)
    {
        cout << i <<' ' << nprime[i] << endl;
    }
}
int main()
{

    init();
//test();
    int n = goal;
    int i = 2;

    while(i * i <= n)
    {
       // cout << i << endl;
       // cout << "debug\n";
        if (!nprime[i])
        {
            //cout << "debug\n";
            while( n % i == 0)
            {
                n /= i;
                cout << i <<',';
            }
        }
        i++;
    }
    cout << n << endl;
}
