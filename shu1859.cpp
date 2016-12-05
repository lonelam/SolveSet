
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
    int x[500], y[500], out[500];
    int t;
    int n;
    while(cin >> n)
    {
        memset(out, 0, sizeof(out));
        memset(y, 0, sizeof(y));
        for(int i = 0; i < n; i++)
        {
            cin >> x[i];
            while(x[i]--)
            {
                y[x[i]]++;
                out[n - y[x[i]]]++;
            }
        }
        cout << out[0];
        for(int i = 1; i < n; i++)
        {
            cout << " "<< out[i];
        }
        cout << endl;
    }
}
